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
	SingleLinkedList();

	SingleLinkedList(const SingleLinkedList& a_list); //copy constructor
	SingleLinkedList& operator=(const SingleLinkedList& a_list); //copy assignment operator
//	~SingleLinkedList();

	SingleLinkedList<T>& append(T const& a_v);  //adds to the back
	SingleLinkedList<T>& append(SingleLinkedList<T> const& a_list);

	SingleLinkedList<T>& prepend(T const& a_v);  //adds to the front
	SingleLinkedList<T>& prepend(SingleLinkedList<T>& a_list);

	T& front();
	T const & front() const;

	T& back();
	T const & back() const;

	size_t size() const;

	T remove_front();
	T remove_back();

//	Holder<T> optional_next(Node<T>& a_node) const;
//	Holder<T> optional_next(SingleLinkedList<T> a_list) const; //global?
	
	bool operator==(SingleLinkedList<T>const& a_list);
	bool operator<(SingleLinkedList<T>const& a_list);
	
	SingleLinkedList& operator<<(T a_v);
	SingleLinkedList& operator<<(SingleLinkedList<T> a_list);

	SingleLinkedList<T> reverse();
	//Node& for_each();

	bool is_empty() const;

private:
	class Node
	{
	public:    
		Node(T a_v, Node* a_next);
	
		Node(const Node* a_node); //copy constructor
		Node* operator=(Node* a_node);
//		~Node();

		Node* next();
		void set_next(Node* a_next);

		T& data();
		T const& data() const;
//		bool operator==(const Node& a_node) const;

	private:
		T m_data;
		Node* m_next;
	};//class node

private:
	Node* get_head() const;
	Node* get_tail() const;
	Node* get_end() const;
//	Node* get_next(Node* a_current);
	Node* get_front();
//	void set_front();
	Node* get_back();
//	void set_back();

private:
	Node* m_head;
	Node* m_tail;
	Node* m_end;
	size_t m_size;
};
/*
bool operator!=(SingleLinkedList<T> a_list);
bool operator>(SingleLinkedList<T> a_list);
bool operator>=(SingleLinkedList<T> a_list);
bool operator<=(SingleLinkedList<T> a_list);
*/
template<typename T>
SingleLinkedList<T>::Node::Node(T a_v, Node* a_next)
: m_data(a_v)
, m_next(a_next)
{}

/*
template<typename T>
SingleLinkedList<T>::Node::~Node()
{
	if(m_next != &m_end)
	{
		delete[] m_next;
	}
}
*/

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


template<typename T>
SingleLinkedList<T>::SingleLinkedList()
: m_head(0)
, m_tail(0)
, m_end(0)
, m_size(0)
{

}

/*
template<typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	if(!is_empty())
	{
		Node* curNode = m_head;
		while(curNode != 0)
		{
			Node* nextNode = curNode->next();
			delete [] curNode;
			curNode = nextNode;
		}
	}	
}
*/

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
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::get_tail() const
{
	assert(!is_empty() && "list is empty");
	return m_tail;
}


template<typename T>
typename SingleLinkedList<T>::Node* SingleLinkedList<T>::get_end() const
{
	assert(!is_empty() && "list is empty");
	return m_end;
}


template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::append(T const& a_v)
{
	Node* newNode = new Node(a_v, 0);
	assert(newNode && "allocation failed");

	if(is_empty())
	{		
		m_end = new Node(0, 0);
		assert(m_end && "sentinal allocation failed");

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
	assert(newNode && "allocation failed");

	if(is_empty())
	{
		m_end = new Node(0, 0);
		assert(m_end && "sentinal allocation failed");

		newNode->set_next(m_end);
		m_tail = newNode;
	}
	else
	{
		newNode->set_next(m_head->next());	
	}

	m_head = newNode;
	++m_size;

	return *this;
}


template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::prepend(SingleLinkedList<T>& a_list)
{
	if(a_list.is_empty())
	{
		return *this;
	}

	SingleLinkedList<T> copyList;

	copyList.append(a_list);

	copyList.get_tail()->set_next(m_head);
	m_head = copyList.get_head();
	m_size += copyList.size();

	delete [] copyList.get_end();
	
	return *this;
}

/*
template<typename T>
T SingleLinkedList<T>::remove_front()
{
	assert(m_size && "list is empty");

	Node* temp = m_head->next()->next();

	T removedData = front();

	delete [] m_head->next();

	m_head->set_next(temp);

	--m_size;

	return removedData;
}
*/

template<typename T>
T SingleLinkedList<T>::remove_back()
{
	assert(!is_empty() && "list is empty");

	Node* currentNode = get_head();

	for(size_t i = m_size; i > 2; --i)
	{
		currentNode = currentNode->next();
	}

	T removedData = back();

	delete m_tail;
	
	currentNode->set_next(m_end);

	--m_size;

	return removedData;
}


template<typename T>
bool SingleLinkedList<T>::is_empty() const
{
	return m_size == 0;
}


template<typename T>
bool SingleLinkedList<T>::operator==(SingleLinkedList<T>const& a_list)
{
	if(a_list.is_empty() && this->is_empty())
	{
		return true;
	}
	else if(this->size() != a_list.size())
	{
		return false;
	}

	Node* currentOther = a_list.get_head();
	Node* currentSelf = this->get_head();

	while(currentOther != a_list.get_end())
	{
		if(currentOther->data() != currentSelf->data())
		{
			return false;
		}
	}	
	
	return true;
}


template<typename T>
bool SingleLinkedList<T>::operator<(SingleLinkedList<T>const& a_list)
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
			if(currentSelf->data() > currentOther->data())
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
			if(currentSelf->data() > currentOther->data())
			{
				return false;
			}

			currentSelf = currentSelf->next();
			currentOther = currentOther->next();
		}

		return true;
	}

	
	
	return true;
}


}//namespace adt





#endif //SLIST_HPP