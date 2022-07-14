#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <iostream>
#include <queue>
#include <mutex>
#include <semaphore>
#include <list>
#include <memory>
#include <condition_variable>
#include <cassert>

#include "semaphore.hpp"


template <typename T>
class SafeQueue
{
public:
	explicit SafeQueue(size_t a_capacity);
	~SafeQueue();

	SafeQueue(SafeQueue<T>const& a_other);
	SafeQueue(SafeQueue<T>&& a_other) = delete;

	SafeQueue<T>& operator=(SafeQueue<T>const& a_other) = delete;
	SafeQueue<T>& operator=(SafeQueue<T>&& a_other) = delete;

	void dequeue(T& a_popped);//if que is empty, waits until it is not empty and then dequeues.
	bool try_dequeue(T& a_popped); //tries to dequeue, if not succeeded returns 0. 1 on success.
	void enqueue(T const& a_element);
	void enqueue(T&& a_element);

	size_t size() const;
	void print() const;

private:
	void decrement_available_slots();
	void decrement_available_elements();

	void increment_available_slots();
	void increment_available_elements();

private:
	std::queue<T> m_que;
	size_t m_capacity;
	mutable std::mutex m_mtx;
	Semaphore m_occupiedCount;
	Semaphore m_emptyCount;
};

template <typename T>
SafeQueue<T>::SafeQueue(size_t a_capacity)
: m_que()
, m_capacity(a_capacity)
, m_occupiedCount(0)
, m_emptyCount(a_capacity)
{

}

template <typename T>
SafeQueue<T>::SafeQueue(SafeQueue<T>const& a_other)
: m_que()
, m_capacity(a_other.m_capacity)
, m_occupiedCount(0)
, m_emptyCount(m_capacity)
{
	std::lock_guard<std::mutex> otherGuard(a_other.m_mtx);

	m_que = a_other.m_que;
	for(size_t i = 0; i < m_que.size(); ++i)
	{
		decrement_available_slots();
		increment_available_elements();
	}
}

template <typename T>
SafeQueue<T>::~SafeQueue()
{

}

template <typename T>
bool SafeQueue<T>::try_dequeue(T& a_popped)
{
	if(m_occupiedCount.try_wait())
	{
		if(m_mtx.try_lock())
		{
			try
			{
				a_popped = m_que.front();
				m_que.pop();
			}
			catch(...)
			{
				m_mtx.unlock();
				m_occupiedCount.release();
				throw;
			}
		}
		else
		{
			m_mtx.unlock();
			return 0;
		}

		m_emptyCount.release();
		return 1;
	}

	return 0;
}

template <typename T>
void SafeQueue<T>::dequeue(T& a_popped)
{
	decrement_available_elements();

	try
	{
		std::unique_lock gaurd(m_mtx);
		a_popped = std::move(m_que.front());
		m_que.pop();
	}
	catch(...)
	{
		increment_available_elements();
		throw;
	}

	increment_available_slots();
}

template <typename T>
void SafeQueue<T>::enqueue(T const& a_element)
{
	T t(a_element);
	enqueue(std::move(t));
}

template <typename T>
void SafeQueue<T>::enqueue(T&& a_element)
{
	decrement_available_slots();

	try
	{
		std::unique_lock gaurd(m_mtx);
		m_que.push(std::move(a_element));		
	}
	catch(...)
	{
		increment_available_slots();
		throw;
	}

	increment_available_elements();
}

template <typename T>
size_t SafeQueue<T>::size() const
{
	std::unique_lock<std::mutex> thisGuard(m_mtx);
	return m_que.size();
}

template <typename T>
void SafeQueue<T>::decrement_available_slots()
{
	m_emptyCount.wait();
}

template <typename T>
void SafeQueue<T>::decrement_available_elements()
{
	m_occupiedCount.wait();
}

template <typename T>
void SafeQueue<T>::increment_available_slots()
{
	try
	{
		m_emptyCount.release();
	}
	catch(...)
	{
		assert(false);
	}
}

template <typename T>
void SafeQueue<T>::increment_available_elements()
{
	try
	{
		m_occupiedCount.release();
	}
	catch(...)
	{
		assert(false);
	}
}

#endif //THREAD_SAFE_QUEUE_HPP