#include <cstddef>
#include <string>
#include <iterator>
#include <iostream>

#include "person.hpp"

namespace objects
{

Person::Person(std::string const& a_id, std::string const& a_name, double a_bodyMass, short a_height)
: m_id(a_id)
, m_name(a_name)
, m_bodyMass(a_bodyMass)
, m_height(a_height)
{

}

std::string const& Person::id() const
{
	return m_id;
}

std::string const& Person::name() const
{
	return m_name;
}

size_t Person::body_mass() const
{
	return m_bodyMass;
}

size_t Person::height() const
{
	return m_height;
}

void Person::change_name(std::string a_newName)
{
	m_name = a_newName;
}

void Person::set_body_mass(size_t a_newBMass)
{
	m_bodyMass = a_newBMass;
}
/*
void Person::swap(Person& a_person)
{
	using std::swap;
	swap(m_id, a_person.m_id);
	swap(m_name, a_person.m_name);
	swap(m_bodyMass, a_person.m_bodyMass);
	swap(m_height, a_person.m_height);
}
*/

bool Person::operator<(Person const& a_person) const
{
	return m_name < a_person.m_name;
}

bool Person::operator<=(Person const& a_person) const
{
	return m_name <= a_person.m_name;
}

std::ostream& Person::operator<<(std::ostream& a_os)
{
	a_os << m_id << '\n';
	a_os << m_name << '\n';
	a_os << m_bodyMass << '\n';
	a_os << m_height << '\n';

	return a_os;
}


void swap_persons(Person& a_first, Person& a_second)
{
	Person temp(a_first);
	a_first = a_second;
	a_second = temp;
}


bool operator>(Person const& a_first, Person const& a_second)
{
	return !(a_first <= a_second);
}


bool operator>=(Person const& a_first, Person const& a_second)
{
	return !(a_first < a_second);
}


bool operator==(Person const& a_first, Person const& a_second)
{
	return (a_first.name() == a_second.name());
}


bool operator!=(Person const& a_first, Person const& a_second)
{
	return !(a_first.name() == a_second.name());
}

/*
std::ostream& operator<<(std::ostream& a_os, Person const& a_person)
{
	a_os << a_person.name() << '\n';
	a_os << a_person.id() << '\n';
	a_os << a_person.body_mass() << '\n';
	a_os << a_person.height() << '\n';

	return a_os;
}
*/



} //namespace objects