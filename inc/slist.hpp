#ifndef SLIST_HPP
#define SLIST_HPP

#include <iostream>
#include <cassert>

namespace adt
{


template<typename T>
class Holder{
public:    
	Holder();
	explicit Holder(T v);

	bool have() const;

	T value() const;

private:
	T m_data;
	bool m_have;
};


template<typename T>
Holder<T>::Holder()
: m_data()
, m_have(false)
{}


template<typename T>
Holder<T>::Holder(T v)
: m_data(v)
, m_have(true)
{}


template<typename T>
bool Holder<T>::have() const
{
	return m_have;
}


template<typename T>
T Holder<T>::value() const
{
	assert(have());
	return m_data;
}


template<typename T>
class Node{
public:    
//	Node();
	Node(T a_v, Node<T>* a_next);
//	Node(const Node<T>& a_node); //copy constructor

	Node<T>* operator=(Node<T>* a_node);
//	~Node();

	Node<T>* next();
	T data() const;
	bool operator==(const Node<T>& a_node) const;


private:
	T m_data;
	Node<T>* m_next;
};

/*
template<typename T>
Node<T>::Node()
: m_data()
, m_next(*this)
{}
*/

template<typename T>
Node<T>::Node(T a_v, Node<T>* a_next)
: m_data(a_v)
, m_next(a_next)
{}


template<typename T>
Node<T>* Node<T>::next()
{
	return m_next;
}


template<typename T>
T Node<T>::data() const
{
	return m_data;
}


template<typename T>
Node<T>* Node<T>::operator=(Node<T>* a_node)
{
	if(&a_node == this)
	{
		return this;
	}

	m_data = a_node.m_data;
	m_next = a_node.m_next;

	return this;
}


template<typename T>
bool Node<T>::operator==(const Node<T>& a_node) const
{
	return this == &a_node;
}


template <typename T>
class SingleLinkedList
{
public:
	SingleLinkedList();

	//SingleLinkedList(const SingleLinkedList& a_list); ??? is this a valid copy constructor?
	//SingleLinkedList(const SingleLinkedList(T a_v)); ??? or this?
	//SingleLinkedList& operator=(const SingleLinkedList(T a_v)); 

	~SingleLinkedList();

	void append(T a_v);  //adds to the front
	void append(SingleLinkedList<T> a_list);

	void prepend(T a_v);  //adds to the back
	void prepend(SingleLinkedList<T> a_list);

	Node<T>* front() const;
	Node<T>* back() const;

	size_t size() const;

	T remove_front();
	T remove_back();

	Holder<T> optional_next(Node<T>& a_node) const;
	Holder<T> optional_next(SingleLinkedList<T> a_list) const; //global?

	SingleLinkedList& operator<<(T a_v);
	SingleLinkedList& operator<<(SingleLinkedList<T> a_list);

	bool operator==(SingleLinkedList<T> a_list);
	bool operator!=(SingleLinkedList<T> a_list);
	bool operator>(SingleLinkedList<T> a_list);
	bool operator<(SingleLinkedList<T> a_list);
	bool operator>=(SingleLinkedList<T> a_list);
	bool operator<=(SingleLinkedList<T> a_list);

	SingleLinkedList<T> reverse();
	//Node& for_each();

private:
	Node<T>* m_headSentinal;
	Node<T>* m_lastNode;
	size_t m_size;
};


template<typename T>
SingleLinkedList<T>::SingleLinkedList()
: m_headSentinal(0)
, m_lastNode(0)
, m_size(0)
{
/*	assert(m_headSentinal && m_endSentinal && "Node allocation failed");

	m_headSentinal.next() = m_endSentinal;
	m_endSentinal.next() = m_headSentinal;*/
}


template<typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	if(!m_size)
	{
		return;
	}

	Node<T>* currentNode = m_headSentinal->next();
	
	while(currentNode)
	{
		Node<T>* nextNode = currentNode->next();
		delete[] currentNode;
		currentNode = nextNode;
	}
}

template<typename T>
void SingleLinkedList<T>::append(T a_v)
{
	if(m_size == 0)
	{
		Node<T>* newNode = new Node<T>(a_v, 0);
		assert(newNode && "allocation failed");

		m_headSentinal = new Node<T>(0, newNode);
		assert(m_headSentinal && "allocation failed");

		m_lastNode = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(a_v, m_lastNode->next());

		*(m_headSentinal->next()) = *newNode;
	}

	++m_size;
}

/*
template<typename T>
void SingleLinkedList<T>::append(SingleLinkedList<T> a_list)
{
	newNode->data() = a_v;
	newNode->next() = m_headSentinal->next();

	m_headSentinal->next() = newNode;
	m_endSentinal->next() = newNode;

	++m_size;
}
*/

template<typename T>
void SingleLinkedList<T>::prepend(T a_v)
{
	if(m_size == 0)
	{
		Node<T>* newNode = new Node<T>(a_v, 0);
		assert(newNode && "allocation failed");

		m_headSentinal = new Node<T>(0, newNode);
		assert(m_headSentinal && "allocation failed");

		m_lastNode = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(a_v, m_headSentinal->next());
		assert(newNode && "allocation failed");

		*(m_headSentinal->next()) = *newNode;	
	}

	++m_size;
}

/*
template<typename T>
void SingleLinkedList<T>::prepend(SingleLinkedList<T> a_list)
{
	Node<T> lastNode = this->m_endSentinal->next();
	Node<T>* newNode = new Node<T>(sizeof(Node<T>));

	newNode->data() = a_v;
	newNode->next() = lastNode->next();

	lastNode->next() = newNode;
	m_endSentinal->next() = newNode;

	++m_size;
}
*/


template<typename T>
Node<T>* SingleLinkedList<T>::front() const
{
	assert(m_size && "list is empty");
	return m_headSentinal->next();
}


template<typename T>
Node<T>* SingleLinkedList<T>::back() const
{
	assert(m_size && "list is empty");
	return m_lastNode;
}
 

template<typename T>
size_t SingleLinkedList<T>::size() const
{
	return m_size;
}


template<typename T>
T SingleLinkedList<T>::remove_front()
{
	assert(m_size && "can't remove nodes, list is empty");

	adt::Node<T>& temp;

	temp = m_headSentinal.next().next();
	T removedData = front().data();

	delete front();

	front() = temp;

	--m_size;

	return removedData;
}

/*
template<typename T>
T SingleLinkedList<T>::remove_back()
{
	assert(m_size && "can't remove nodes, list is empty");

	if(m_size == 1)
	{
		T removedData = m_endSentinal->next().data();

		m_headSentinal->next() = m_endSentinal;

		delete m_endSentinal->next();

		m_endSentinal->next() = m_headSentinal;
	}


	return removedData;
}
*/
/*
template<typename T>
void SingleLinkedList<T>::
{

}
*/


}//namespace adt




#endif //SLIST_HPP