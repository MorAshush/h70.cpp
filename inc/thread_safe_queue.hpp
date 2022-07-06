#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <iostream>
#include <queue>
#include <mutex>
#include <list>
#include <memory>


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

	void pop();
	void push(T const& a_element);

	T front() const;

	size_t size() const;

private:
	std::queue<T> m_que;
	std::mutex m_mtx;
};

template <typename T>
SafeQueue<T>::SafeQueue()
{

}

template <typename T>
SafeQueue<T>::SafeQueue(SafeQueue<T> const& a_other)
: m_que(a_other.m_que)
{

}

template <typename T>
SafeQueue<T>::~SafeQueue()
{

}

template <typename T>
void SafeQueue<T>::pop()
{
	if(m_que.empty())
	{
		return;
	}

	m_mtx.lock();
	m_que.pop();
	m_mtx.unlock();
}

template <typename T>
void SafeQueue<T>::push(T const& a_element)
{
	m_mtx.lock();
	m_que.push(a_element);
	m_mtx.unlock();
}

template <typename T>
T SafeQueue<T>::front() const
{
	T front = m_que.front();
	return front;
}

template <typename T>
size_t SafeQueue<T>::size() const
{
	return m_que.size();
}


#endif //THREAD_SAFE_QUEUE_HPP