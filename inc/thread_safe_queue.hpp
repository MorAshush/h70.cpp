#ifndef THREAD_SAFE_QUEUE_HPP
#define THREAD_SAFE_QUEUE_HPP

#include <queue>
#include <mutex>

template <typename T>
class SafeQueue
{
public:
	SafeQueue();
	~SafeQueue();

	SafeQueue(SafeQueue<T>const& a_other);
	SafeQueue(SafeQueue<T>&& a_other);

	SafeQueue<T>& operator=(SafeQueue<T>const& a_other);
	SafeQueue<T>& operator=(SafeQueue<T>&& a_other);

	void pop();
	void push(T const& a_element);

private:
	std::queue<T> m_que;
	std::mutex m_mtx;
};

template <typename T>
SafeQueue<T>::SafeQueue()
{

}

template <typename T>
SafeQueue<T>::SafeQueue(SafeQueue<T>const& a_other)
: m_que(a_other)
{

}

template <typename T>
SafeQueue<T>::~SafeQueue()
{

}

template <typename T>
void SafeQueue<T>::pop()
{
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











#endif //THREAD_SAFE_QUEUE_HPP