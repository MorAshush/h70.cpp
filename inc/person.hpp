#ifndef PERSON_HPP
#define PERSON_HPP

#include <cstddef>
#include <string>
#include <iostream>
#include <list>

namespace objects
{

class Person
{
public:
	Person(std::string const& a_id, std::string const& a_name, double a_bodyMass, short a_height);

//	Person(Person const& a_person); compiler will do
//	Person& operator=(Person const& a_person); compiler will do

	std::string const& id() const;
	std::string const& name() const;
	size_t body_mass() const;
	size_t height() const;

	void change_name(std::string a_newName);
	void set_body_mass(size_t a_newBMass);
	void swap(Person& a_person);

	bool operator<(Person const& a_person) const;	
	bool operator<=(Person const& a_person) const;

	std::ostream& operator<<(std::ostream& a_os);



private:
	std::string m_id;
	std::string m_name;
	double m_bodyMass;
	short m_height;	
};


void swap_persons(Person& a_first, Person& a_second);

bool operator>(Person const& a_first, Person const& a_second);

bool operator>=(Person const& a_first, Person const& a_second);

bool operator==(Person const& a_first, Person const& a_second);

bool operator!=(Person const& a_first, Person const& a_second);


} //namespace objects




#endif // PERSON_HPP