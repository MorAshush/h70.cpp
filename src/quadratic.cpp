#include <cstdio>
#include <cassert>

#include "quadratic.hpp"
#include "rational.hpp"

namespace algebra
{
//constructors:

Quadratic::Quadratic(Rational a_a, Rational a_b, Rational a_c)
: m_a(a_a)
, m_b(a_b)
, m_c(a_c)
{
    assert(a_a.get_numerator() != 0 && "higest power argument's coefficient can't be zero");    
    assert(a_b.get_numerator() != 0 && "second higest power argument can't be zero");  

}

/*
void Quadratic::print() const  
{ 
	m_a.print();
	printf("X^2");

	if(m_b.is_positive())
	{
		printf("+");
	}

	m_b.print();

	if(m_c.get_numerator())
	{
		if(m_c.is_positive())
		{
			printf("+");
		}

		m_c.print();
	}

	printf("\n");
}
*/
void Quadratic::print() const  
{ 
	if(!(m_a.is_positive()))
	{
		printf("-");
		Rational t = m_a * -1;
		t.print();
		printf("X^2");
	}
	else
	{
		m_a.print();
		printf("X^2");
	}

	if(!(m_b.is_positive()))
	{
		printf("-");
		Rational t = m_b * -1;
		t.print();
		printf("X");
	}
	else
	{
		printf("+");
		m_b.print();
		printf("X");
	}

	if(!(m_c.is_positive()))
	{
		printf("-");
		Rational t = m_c * -1;
		t.print();
	}
	else
	{
		printf("+");
		m_c.print();
	}

	printf("\n");
}
/*
roots Quadratic::calc_polinum_roots() const
{
	Rational a = m_a;
	Rational b = m_b;
	Rational c = m_c;

	roots solutions = {0};

	m_polinumRoots.m_first = calc_pol_root_on_plus(a, b, c, &solutions);
	if(solutions.m_numOfRoots == 0)
	{
		return 0;
	}
	else if(solutions.m_numOfRoots == 1)
	{
		return solutions;
	}

	m_polinumRoots.m_second = calc_pol_root_on_minus(a, b, c, &solutions);

	return solutions;
}


void Quadratic::calc_pol_root_on_plus(Rational a_a, Rational a_b, Rational a_c, roots* a_roots)
{
	Rational a = m_a;
	Rational b = m_b;
	Rational c = m_c;

	Rational part1 = multiply_two_rationals(b,b);                                  //(b ^ 2)
	Rational part2 = multiply_two_rationals(multiply_rational_by_int(a,4), c);     //(4 a c)

	if((part1 - part2) < 0)
	{
		return;
	}

	Rational part3 = sqrt_rational(substruct_two_rationals(part2 - part3));        // sqrt(b^2 - 4ac)
	Rational part4 = multiply_rational_by_int(a, 2);                               //(2 * a) 

	Rational root1 = divide_two_rationals( add_two_rationals(-b, part3), part4 );  //(-b + part3) / part4; 
	
	a_roots->m_numOfRoots++;
	a_roots->m_first = root1;
}

Rational Quadratic::calc_pol_root_on_minus(Rational a_a, Rational a_b, Rational a_c, roots* a_roots)
{
	Rational a = m_a;
	Rational b = m_b;
	Rational c = m_c;

	Rational part1 = multiply_two_rationals(b, b);                                  //(b ^ 2)
	Rational part2 = multiply_two_rationals(multiply_rational_by_int(a, 4), c);     //(4 a c)
	Rational part3 = sqrt_rational( substruct_two_rationals(part2 - part3) );        // sqrt(b^2 - 4ac)
	Rational part4 = multiply_rational_by_int(a, 2);                               //(2 * a) 

	Rational root2 = divide_two_rationals( substruct_two_rationals(-b, part3), part4 );  //(-b + part3) / part4; 
	
	a_roots->m_numOfRoots++;
	a_roots->m_second = root2;
}*/


/**
 * @brief class function to get the first quadratic coefficient. 
 
 * @param self quadratic.
 * @return a rational of the coefficient.
 */
Rational Quadratic::get_first_cofefficient() const
{
	return this->m_a;
}


/**
 * @brief class function to get the second quadratic coefficient. 
 
 * @param self quadratic.
 * @return a rational of the coefficient.
 */
Rational Quadratic::get_second_cofefficient() const
{
	return this->m_b;
}


/**
 * @brief class function to get the third quadratic coefficient. 
 
 * @param self quadratic.
 * @return a rational of the coefficient.
 */
Rational Quadratic::get_third_cofefficient() const
{
	return this->m_c;
}


Quadratic multiply(Quadratic a_quadratic, int a_num)
{
	Rational a = a_quadratic.get_first_cofefficient();
	Rational b = a_quadratic.get_second_cofefficient();
	Rational c = a_quadratic.get_third_cofefficient();

	Quadratic result(a * a_num, b * a_num, c * a_num);

	return result;
}

Quadratic multiply(Quadratic a_quadratic, Rational a_rational)
{
	Rational a = a_quadratic.get_first_cofefficient();
	Rational b = a_quadratic.get_second_cofefficient();
	Rational c = a_quadratic.get_third_cofefficient();

	Quadratic result(a * a_rational , b * a_rational , c * a_rational);

	return result;
}

Quadratic add_two_quadratics(Quadratic a_first, Quadratic a_second)
{
	Rational a1 = a_first.get_first_cofefficient();
	Rational b1 = a_first.get_second_cofefficient();
	Rational c1 = a_first.get_third_cofefficient();

	Rational a2 = a_second.get_first_cofefficient();
	Rational b2 = a_second.get_second_cofefficient();
	Rational c2 = a_second.get_third_cofefficient();

	Quadratic result(a1 + a2, b1 + b2, c1 + c2);

	return result;
}


}//namespace algebra




