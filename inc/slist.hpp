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


template <typename T>
class SingleLinkedList
{

public:
	class ListItr;
	class ConstListItr;

public:
	SingleLinkedList();

	SingleLinkedList(const SingleLinkedList& a_list); 
	SingleLinkedList& operator=(const SingleLinkedList& a_list); 
	~SingleLinkedList();

	SingleLinkedList& append(T const& a_v); 
	SingleLinkedList& append(SingleLinkedList const& a_list);

	SingleLinkedList& prepend(T const& a_v); 
//	SingleLinkedList& prepend(SingleLinkedList const& a_list);

	T& front();
	T const & front() const;
	T& back();
	T const & back() const;

	ListItr begin();
	ConstListItr cbegin() const;
	ListItr end();
	ConstListItr cend() const;

	size_t size() const;

	T remove_front();
	T remove_back();

//	Holder optional_next(Node& a_node) const;
//	Holder optional_next(SingleLinkedList a_list) const; //global?
	
	bool operator==(SingleLinkedList const& a_list) const;
	bool operator<(SingleLinkedList const& a_list) const;
	
	SingleLinkedList& operator<<(T a_v);
	SingleLinkedList& operator<<(SingleLinkedList a_list);

	SingleLinkedList& reverse();
//	Node& for_each();

	bool is_empty() const;
	void print() const;

private:
	class Node;

private:
	Node* get_head() const;
	void set_head(Node* a_node);

	Node* get_tail() const;
	void set_tail(Node* a_node);

	Node* get_end() const;

	Node* reverse(Node* a_node);

	Node* one_before_last();

private:
	Node* m_head;
	Node* m_tail;
	Node* m_end;
	size_t m_size;

};//class SingleLinkedList


template<typename T>
class SingleLinkedList<T>::ListItr
{
public:
    ListItr(Node* a_current);

    ListItr operator++() ;
    T& operator*() ;
    const T& operator*() const;
    bool operator==(ListItr const& a_itr) const;

private:
	Node* m_currentNode;
}; //class ListItr


template<typename T>
class SingleLinkedList<T>::ConstListItr
{
public:
    ConstListItr(const Node* a_current);
    ConstListItr operator++() ;
    const T& operator*() const;

private:
	const Node* m_currentNode;
}; //class ConstListItr


template<typename T>
class SingleLinkedList<T>::Node	
{
public:    
	Node(T a_v, Node* a_next);

	Node* next();
	void set_next(Node* a_next);

	T& data();
	T const& data() const;
	bool operator==(const Node& a_node) const;
	bool operator!=(const Node& a_node) const;

private:
	T m_data;
	Node* m_next;

};//class node


template<typename T>
bool operator!=(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second);

template<typename T>
bool operator>(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second);

template<typename T>
bool operator>=(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second);

template<typename T>
bool operator<=(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second);



template<typename T>
SingleLinkedList<T>::SingleLinkedList()
: m_head(0)
, m_tail(0)
, m_end(0)
, m_size(0)
{

}


template<typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	Node* curNode = m_head;
	while(curNode != 0)
	{
		Node* nextNode = curNode->next();
		delete curNode;
		curNode = nextNode;
	}
}


template<typename T>
T& SingleLinkedList<T>::front()
{
	assert(m_size && "list is empty");
	return m_head->data();
}


template<typename T>
T& SingleLinkedList<T>::back()
{
	assert(m_size && "list is empty");
	return m_tail->data();
}


template<typename T>
T const& SingleLinkedList<T>::front() const
{
	assert(m_size && "list is empty");
	return m_head->data();
}


template<typename T>
T const& SingleLinkedList<T>::back() const
{
	assert(m_size && "list is empty");
	return m_tail->data();
}


template<typename T>
typename SingleLinkedList<T>::ListItr SingleLinkedList<T>::begin() 
{
	assert(!is_empty() && "list is empty");

	ListItr itr(m_head);

	return itr;
}


template<typename T>
typename SingleLinkedList<T>::ConstListItr SingleLinkedList<T>::cbegin() const 
{
	assert(!is_empty() && "list is empty");

	ConstListItr itr(m_head);

	return itr;
}


template<typename T>
typename SingleLinkedList<T>::ListItr SingleLinkedList<T>::end() 
{
	assert(!is_empty() && "list is empty");

	ListItr itr(m_tail);

	return itr;
}


template<typename T>
typename SingleLinkedList<T>::ConstListItr SingleLinkedList<T>::cend() const
{
	assert(!is_empty() && "list is empty");

	ConstListItr itr(m_tail);

	return itr;
}


template<typename T>
size_t SingleLinkedList<T>::size() const
{
	return m_size;
}


template<typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::get_head() const
{
	assert(!is_empty() && "list is empty");
	return m_head;
}


template<typename T>
void SingleLinkedList<T>::set_head(typename SingleLinkedList<T>::Node* a_node)
{
	m_head = a_node;
}


template<typename T>
void SingleLinkedList<T>::set_tail(typename SingleLinkedList<T>::Node* a_node)
{
	m_tail = a_node;
}


template<typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::get_tail() const
{
	assert(!is_empty() && "list is empty");
	return m_tail;
}


template<typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::get_end() const
{
	assert(m_end && "list is empty");
	return m_end;
}


template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::append(T const& a_v)
{
	Node* newNode = new Node(a_v, 0);

	if(is_empty())
	{		
		m_end = new Node(0, 0);

		newNode->set_next(m_end);
		m_head = newNode;
	}
	else
	{
		newNode->set_next(m_end);
		m_tail->set_next(newNode);
	}

	m_tail = newNode;
	++m_size;

	return *this;
}

template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::append(SingleLinkedList<T> const& a_list)
{
	if(a_list.is_empty())
	{
		return *this;
	}

	Node* currentAddedNode = a_list.get_head();

	while(currentAddedNode != a_list.get_end())
	{
		this->append(currentAddedNode->data());
		currentAddedNode = currentAddedNode->next();
	}	
	
	return *this;
}


template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::prepend(T const& a_v)
{
	Node* newNode = new Node(a_v, 0);

	if(is_empty())
	{
		m_end = new Node(0, 0);

		newNode->set_next(m_end);
		m_tail = newNode;
	}
	else
	{
		newNode->set_next(get_head());	
	}

	set_head(newNode);
	++m_size;

	return *this;
}

/*
template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::prepend(SingleLinkedList<T> const& a_list)
{
	if(a_list.is_empty())
	{
		return *this;
	}

	SingleLinkedList<T> copyList;

	copyList.append(a_list);

	while(copyList.size())
	{
		printf("list size: %ld\n", copyList.size());
		T data = copyList.remove_back();
		this->prepend(data);
	}

	Node* keeper = get_head();
	set_head(copyList.get_head());

	Node* lastInCopy = copyList.get_tail(); 
	lastInCopy->set_next(keeper);

	a_list.set_head(a_list.get_end());

	return *this;
}
*/

template<typename T>
T SingleLinkedList<T>::remove_front()
{
	assert(m_size && "list is empty");

	Node* temp = m_head->next();

	T removedData = front();

	delete get_head();

	set_head(temp);

	--m_size;

	return removedData;
}


template<typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::one_before_last()
{
	assert(size() >= 2 && "num of items must be at least two");

	Node* currentNode = get_head();

	while(currentNode->next()->next() != get_end())
	{
		currentNode = currentNode->next();
	}

	return currentNode;
}



template<typename T>
T SingleLinkedList<T>::remove_back()
{
	assert(!is_empty() && "list is empty");

	T removedData = back();

	if(size() == 1)
	{
		delete get_tail();
		set_tail(0);
		set_head(0);
	}
	else
	{
		Node* oneBeforeLast = one_before_last();
	
		oneBeforeLast->set_next(m_end);

		delete get_tail();
		set_tail(oneBeforeLast);
	}

	--m_size;

	return removedData;
}


template<typename T>
bool SingleLinkedList<T>::is_empty() const
{
	return m_size == 0;
}


template<typename T>
bool SingleLinkedList<T>::operator==(SingleLinkedList<T>const& a_list) const
{
	if(a_list.is_empty() && this->is_empty())
	{
		return true;
	}
	else if(!a_list.is_empty() && this->is_empty())
	{
		return true;
	}
	else if(a_list.is_empty() && !(this->is_empty()))
	{
		return false;
	}
	else if(this->size() != a_list.size())
	{
		return false;
	}

	Node* currentOther = a_list.get_head();
	Node* currentSelf = this->get_head();

	if(a_list.size() <= this->size())
	{
		while(currentOther != a_list.get_end())
		{
			if(currentOther->data() != currentSelf->data())
			{
				return false;
			}

			currentSelf = currentSelf->next();
			currentOther = currentOther->next();
		}	
	}
	else
	{
		while(currentSelf != this->get_end())
		{
			if(currentSelf->data() != currentOther->data())
			{
				return false;
			}

			currentSelf = currentSelf->next();
			currentOther = currentOther->next();
		}	
	}
	
	
	
	return true;
}


template<typename T>
bool SingleLinkedList<T>::operator<(SingleLinkedList<T>const& a_list) const
{
	if(a_list.is_empty() && this->is_empty())
	{
		return false;
	}

	Node* currentOther = a_list.get_head();
	Node* currentSelf = this->get_head();

	if(a_list.size() <= this->size())
	{
		while(currentOther != a_list.get_end())
		{
			if(currentSelf->data() < currentOther->data())
			{
				return true;
			}
			else if(currentSelf->data() > currentOther->data())
			{
				return false;
			}

			currentSelf = currentSelf->next();
			currentOther = currentOther->next();
		}

		return false;	
	}
	else
	{
		while(currentSelf != this->get_end())
		{
			if(currentSelf->data() < currentOther->data())
			{
				return true;
			}
			else if(currentSelf->data() > currentOther->data())
			{
				return false;
			}

			currentSelf = currentSelf->next();
			currentOther = currentOther->next();
		}

		return true;
	}
}


template<typename T>
bool operator<=(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second)
{
	if(a_first == a_second)
	{
		return true;
	}
	if(a_first < a_second)
	{
		return true;
	}

	return false;
}


template<typename T>
bool operator>(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second)
{
	if(a_first == a_second)
	{
		return false;
	}
	if(a_first < a_second)
	{
		return false;
	}

	return true;
}


template<typename T>
bool operator>=(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second)
{
	return !(a_first < a_second);
}


template<typename T>
bool operator!=(SingleLinkedList<T>const& a_first, SingleLinkedList<T>const& a_second)
{
	return !(a_first == a_second);
}


template<typename T>        
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::reverse(typename SingleLinkedList<T>::Node* a_current)
{
	if(a_current->next() == m_end)
	{
		return a_current; 
	}

	Node* returned = reverse(a_current->next());

	returned->set_next(a_current);

	return a_current;
}


template<typename T>        
SingleLinkedList<T>& SingleLinkedList<T>::reverse()
{
	Node* oldTail = get_tail();
	Node* newTail = reverse(m_head);

	set_tail(newTail);
	newTail->set_next(m_end);

	set_head(oldTail);

	return *this;
}


template<typename T>        
void SingleLinkedList<T>::print() const
{
	Node* currentNode = get_head();

	std::cout << "[";

	while(currentNode)
	{
		Node* nextNode = currentNode->next();
		std::cout << currentNode->data();

		if(currentNode == get_tail())
		{
			break;
		}

		std::cout << ",";
		currentNode = nextNode;
	}

	std::cout << "]";
}


template<typename T>
SingleLinkedList<T>::Node::Node(T a_v, Node* a_next)
: m_data(a_v)
, m_next(a_next)
{}

template<typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::Node::next()
{
	return m_next;
}


template<typename T>
void SingleLinkedList<T>::Node::set_next(Node* a_next)
{
	m_next = a_next;
}


template<typename T>
T& SingleLinkedList<T>::Node::data()
{
	return m_data;
}


template<typename T>
T const& SingleLinkedList<T>::Node::data() const
{
	return m_data;
}


template<typename T>
bool SingleLinkedList<T>::Node::operator==(const Node& a_node) const
{
	return this->data() == a_node.data();
}


template<typename T>
bool SingleLinkedList<T>::Node::operator!=(const Node& a_node) const
{
	return !(this->data() == a_node.data());
}
/*
template<typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::Node::operator=(Node* a_node)
{
	if(&a_node == this)
	{
		return this;
	}

	m_data = a_node->m_data;
	m_next = a_node->m_next;

	return this;
}
*/


template<typename T>
SingleLinkedList<T>::ListItr::ListItr(Node* a_current)
: m_currentNode(0)
{
	assert(a_current && "node pointer is null");
	m_currentNode = a_current;
}


template<typename T>
typename SingleLinkedList<T>::ListItr SingleLinkedList<T>::ListItr::operator++()
{
	if(m_currentNode->next() == 0) //if end?
	{
		return *this;
	}

	return m_currentNode->next();
}


template<typename T>
T& SingleLinkedList<T>::ListItr::operator*()
{
	return m_currentNode->data();
}


template<typename T>
T const& SingleLinkedList<T>::ListItr::operator*() const
{
	return m_currentNode->data();
}


template<typename T>
bool SingleLinkedList<T>::ListItr::operator==(ListItr const& a_itr) const
{
	return m_currentNode == a_itr.m_currentNode;;
}



/*
template<typename T>
typename SingleLinkedList<T>::ListItr::ConstListItr(const Node* a_current)
: m_currentNode(a_current)
{}


template<typename T>
typename SingleLinkedList<T>::ConstListItr SingleLinkedList<T>::ConstListItr::operator++()
{
	if(m_currentNode->next() == 0)
	{
		return *this;
	}

	return m_currentNode->next();
}


template<typename T>
T const& SingleLinkedList<T>::ConstListItr::operator*() const
{
	return m_currentNode->data();
}

*/







}//namespace adt





#endif //SLIST_HPP