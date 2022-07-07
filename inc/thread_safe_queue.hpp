#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <iostream>
#include <queue>
#include <mutex>
#include <list>
#include <memory>
#include <condition_variable>


template <typename T>
class SafeQueue
{
public:
	SafeQueue();
	~SafeQueue();

	SafeQueue(SafeQueue<T>const& a_other);
	SafeQueue(SafeQueue<T>&& a_other) = delete;

	SafeQueue<T>& operator=(SafeQueue<T>const& a_other);
	SafeQueue<T>& operator=(SafeQueue<T>&& a_other) = delete;

	bool dequeue(T& a_popped);
	void enqueue(T const& a_element);

	size_t size() const;
	void print() const;

private:
	std::queue<T> m_que;
	mutable std::mutex m_mtx;
};

template <typename T>
SafeQueue<T>::SafeQueue()
{

}

template <typename T>
SafeQueue<T>::SafeQueue(SafeQueue<T> const& a_other)
{
	std::unique_lock<std::mutex> thisGuard(m_mtx);
	std::lock_guard<std::mutex> otherGuard(a_other.m_mtx);

	m_que = a_other.m_que;
}

template <typename T>
SafeQueue<T>::~SafeQueue()
{

}

template <typename T>
bool SafeQueue<T>::dequeue(T& a_popped)
{
	std::unique_lock<std::mutex> thisGuard(m_mtx);

	auto not_empty = [this]()
	{
		return !(m_que.empty());
	};

	std::condition_variable cv;

	cv.wait(thisGuard, not_empty);

	try
	{
		a_popped = m_que.front();
		m_que.pop();
	}
	catch(...)
	{
		return 0;
	}

	return 1;
}

template <typename T>
void SafeQueue<T>::enqueue(T const& a_element)
{
	std::unique_lock<std::mutex> thisGuard(m_mtx);
	m_que.push(a_element);
}

template <typename T>
size_t SafeQueue<T>::size() const
{
	std::unique_lock<std::mutex> thisGuard(m_mtx);
	return m_que.size();
}

template <typename T>
void SafeQueue<T>::print() const
{
	SafeQueue<T> queCopy(*this);

	size_t size = queCopy.size();

	std::list<T> elements;

	for(size_t i = 0; i < size; ++i)
	{
		T element;
		queCopy.dequeue(element);	
		elements.push_front(element);
	}

	auto it = elements.begin();
	auto end = elements.end();

	while(it != end)
	{
		std::cout << *it << ", ";

		++it;
	}

	std::cout << "\n\n";
}

#endif //THREAD_SAFE_QUEUE_HPP