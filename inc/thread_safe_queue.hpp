#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <iostream>
#include <queue>
#include <mutex>
#include <semaphore>
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

	bool dequeue(T& a_popped);//if que is empty, waits until it is not empty and then dequeues.
	bool try_dequeue(T& a_popped); //tries to dequeue, if not succeeded returns 0. 1 on success.
	void enqueue(T const& a_element);

	size_t size() const;
	void print() const;

private:
	std::queue<T> m_que;
	mutable std::mutex m_mtx;
	std::binary_semaphore m_smph;
};

template <typename T>
SafeQueue<T>::SafeQueue()
: m_smph(0)
{

}

template <typename T>
SafeQueue<T>::SafeQueue(SafeQueue<T> const& a_other)
: m_smph(0)
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
bool SafeQueue<T>::try_dequeue(T& a_popped)
{
	std::unique_lock<std::mutex> thisGuard(m_mtx);
	if(m_que.empty())
	{
		return 0;
	}

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
bool SafeQueue<T>::dequeue(T& a_popped)
{
	std::cout << "dequeue is acquiering\n\n";
	m_smph.acquire();

	a_popped = m_que.front();
	m_que.pop();

//	m_smph.release();

	return 1;
}

template <typename T>
void SafeQueue<T>::enqueue(T const& a_element)
{
	std::unique_lock<std::mutex> thisGuard(m_mtx);
	m_que.push(a_element);

	std::cout << "enqueue - an element was pushed in to que\n\n";

	m_smph.release();
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