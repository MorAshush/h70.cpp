#include <cstdio>
#include <cassert>

#include "quadratic.hpp"
#include "rational.hpp"


//constructors:

Quadratic::Quadratic(Rational a_rational1, Rational a_rational2, Rational a_rational3)
: m_first(a_rational1)
, m_second(a_rational2)
, m_third(a_rational3)
{
    assert(m_first.get_numerator() != 0 && "higest power argument's coefficient can't be zero");    
    assert(m_second.get_numerator() != 0 && "second higest power argument can't be zero");  

}


void Quadratic::print() const  
{ 
	m_first.print();
	printf("X^2");

	if(m_second.is_positive())
	{
		printf("+");
	}

	m_second.print();

	if(m_third.get_numerator())
	{
		if(m_third.is_positive())
		{
			printf("+");
		}

		m_third.print();
	}

	printf("\n");
}

int* Quadratic::multiply(int a_num)
{
	Rational a(m_first.get_numerator(), m_first.get_denumerator());
	Rational b(m_second.get_numerator(), m_second.get_denumerator());
	Rational c(m_third.get_numerator(), m_third.get_denumerator());

	Rational const* roots[2] = {0};

	roots[0] = calc_pol_root_on_plus(a, b, c);
	roots[1] = calc_pol_root_on_minus(a, b, c);
}

Rational Rational::calc_pol_root_on_plus(const Rational a_rational1, const Rational a_rational2, const Rational a_rational3)
{
	Rational a = a_rational1;
	Rational b = a_rational2;
	Rational c = a_rational3;

}

void Quadratic::multiply(int a_num)
{
	m_first.multiply(a_num);
	m_second.multiply(a_num);
	m_third.multiply(a_num);
}

void Quadratic::multiply(Rational a_rational)
{
	m_first.multiply(a_rational);
	//m_first.reduce();?

	m_second.multiply(a_rational);
	//m_second.reduce();?

	m_third.multiply(a_rational);
	//m_third.reduce()?
}




