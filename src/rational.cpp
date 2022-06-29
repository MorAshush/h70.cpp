#include <cstdio>
#include <cassert>
#include <cmath>

#include "rational.hpp"

static size_t find_gcd(int a_first, int a_second);

namespace algebra
{
/**
 * @brief class constractor function to initiailize a class rational. was not defined as explicit to able compiler conversion
 * of an integers to rational , to pass to class functions arguments.
 
 * @param a_num and a a_denom, to put in a rational 
 * @return an initialized rational
 */
Rational::Rational(int a_num, int a_denom)
    : m_numerator(a_num)               // MIL
    , m_denumerator(a_denom)
    {
        assert(m_denumerator != 0 && "denom can't be zero");    
        
        if(m_numerator > 0 && m_denumerator < 0)
        {
            m_numerator *= -1;
            m_denumerator *= -1;
        }
        if(m_numerator < 0 && m_denumerator < 0)
        {
            m_numerator *= -1;
            m_denumerator *= -1;  
        }
    }


/**
 * @brief class constractor function to initiailize a class rational with passing an int. 
 
 * @param a_num, to put in a rational numerator. a defult denumerator is determined as 1.
 * @return an initialized rational
 */
Rational::Rational(int a_num)
: m_numerator(a_num)               // MIL
, m_denumerator(1)
{    
}


/**
 * @brief class function to scale a rational by a number. changes self. 
 
 * @param self rational, and a_s, scale the rational by.
 * @return none.
 */
void Rational::scale(int a_s)
{
    m_numerator *= a_s;
    m_denumerator *= a_s;
}


/**
 * @brief class function to print a rational. 
 
 * @param self rational.
 * @return none.
 */
void Rational::print() const
{   
    if(m_denumerator == 1)
    {
        display("[%d]");
    }
    else
    {
        display("[%d/%d]");
    }
}


/**
 * @brief class function to print a rational. 
 
 * @param self rational.
 * @return none.
 */
void Rational::display(const char* fmt) const
{
    printf(fmt, m_numerator, m_denumerator);
}


/**
 * @brief class function to get a rationals numerator. 
 
 * @param self rational.
 * @return int value of the numerator.
 */
int Rational::get_numerator() const
{
    return this-> m_numerator;
}


/**
 * @brief class function to get a rationals denumerator. 
 
 * @param self rational.
 * @return int value of the denumerator.
 */
int Rational::get_denumerator() const 
{
    return this-> m_denumerator;
}


/**
 * @brief class function to if a rational is positive. return true or false. 
 
 * @param self rational.
 * @return returns true(1) if positive, or false(0) otherwise.
 */
bool Rational::is_positive() const
{
    if (m_numerator > 0 && m_denumerator > 0)
    {
        return 1;
    }

    return 0;
}


/**
 * @brief class function that add a rational to self. changes self.
 
 * @param a_rational to add to self 
 * @return non
 */
    void Rational::add(Rational a_rational) 
    {
        int numer2 = a_rational.m_numerator;
        int denom2 = a_rational.m_denumerator;

        if( this-> m_denumerator == denom2 )
        {
            this->m_numerator += numer2;
        }
        else if( this-> m_denumerator < denom2 )
        {
            if( !(denom2 % this-> m_denumerator) )
            {
                int factor = denom2 / this-> m_denumerator;

                this-> m_denumerator = denom2;

                this->m_numerator *= factor;
                this->m_numerator += numer2;
            }
            else
            {
                int newDenumerator = this-> m_denumerator * denom2;

                this->m_numerator *= denom2;
                numer2 *=  this-> m_denumerator;

                this->m_numerator += numer2;
                this-> m_denumerator = newDenumerator;
            }
        }
        else 
        {
            if( !(this-> m_denumerator % denom2) )
            {
                int factor = this-> m_denumerator / denom2;

                numer2 *= factor;
                this->m_numerator += numer2;
            }
            else
            {
                int newDenumerator = this-> m_denumerator * denom2;

                this->m_numerator *= denom2;
                numer2 *=  this-> m_denumerator;

                this->m_numerator += numer2;
                this-> m_denumerator = newDenumerator;
            }
        }
    }


/**
 * @brief class function that subtruct a rational from self. changes self.
 
 * @param a_rational to subtruct from self 
 * @return non
 */
void Rational::substruct(Rational a_rational)  
{
    int numer2 = a_rational.m_numerator;
    int denom2 = a_rational.m_denumerator;

    if( this-> m_denumerator == denom2 )
    {
        this->m_numerator -= numer2;
    }
    else if( this-> m_denumerator > denom2 )
    {
        if( !(this-> m_denumerator % denom2) )
        {
            int factor = this-> m_denumerator / denom2;

            numer2 *= factor;
            this->m_numerator -= numer2;
        }
        else
        {
            int newDenumerator = this-> m_denumerator * denom2;

            this->m_numerator *= denom2;
            numer2 *=  this-> m_denumerator;

            this->m_numerator -= numer2;
            this-> m_denumerator = newDenumerator;           
        }
    }
    else 
    {
        if( !(denom2 % this-> m_denumerator) )
        {
            int factor = denom2 / this-> m_denumerator;

            this-> m_denumerator = denom2;

            this->m_numerator *= factor;
            this->m_numerator -= numer2;
        }
        else
        {
            int newDenumerator = this-> m_denumerator * denom2;

            this->m_numerator *= denom2;
            numer2 *=  this-> m_denumerator;

            this->m_numerator -= numer2;
            this-> m_denumerator = newDenumerator;
        }
    }
}


/**
 * @brief class function that multiplies a rational by other rational. changes self.
 
 * @param a self and a_rational to multiply by 
 * @return non
 */
void Rational::multiply(Rational a_rational) 
{
    int numer2 = a_rational.m_numerator;
    int denom2 = a_rational.m_denumerator;

    this->m_numerator *= numer2;
    this-> m_denumerator *= denom2;
    if((m_denumerator < 0 && m_numerator > 0) || (m_denumerator < 0 && m_numerator < 0))
    {
        m_denumerator *= -1;
        m_numerator *= -1;
    }
}


/**
 * @brief class function that divides a rational by other rational. changes self.
 
 * @param a self and a_rational to divide by 
 * @return non
 */
void Rational::divide(Rational a_rational) 
{
    int numer2 = a_rational.m_numerator;

    assert(numer2 != 0 && "cannot be divided by zero"); 

    int denom2 = a_rational.m_denumerator;

    this->m_numerator *= denom2;
    this-> m_denumerator *= numer2;

    if((m_denumerator < 0 && m_numerator > 0) || (m_denumerator < 0 && m_numerator < 0))
    {
        m_denumerator *= -1;
        m_numerator *= -1;
    }
}


/**
 * @brief class function to reduce a rational to minimum possible. changes self.
 
 * @param a self . 
 * @return non
 */
void Rational::reduce()
{
    int numer = this->m_numerator;
    int denom = this-> m_denumerator;
    if(numer <  0)
    {
        numer *= -1;
    }

    size_t gcd = find_gcd(numer, denom);

    numer /= gcd;
    denom /= gcd;

    if((m_denumerator < 0 && m_numerator > 0) || (m_denumerator < 0 && m_numerator < 0))
    {
        m_denumerator *= -1;
        m_numerator *= -1;
    }

    if(!(this->is_positive()))
    {
        numer *= -1;
    }

    m_numerator = numer;
    m_denumerator = denom;
}


/*Rational sqrt_rational(const Rational a_rational)
{
    Rational result = (sqrt(a_rational.m_numerator), sqrt(a_rational.m_denumerator));

    return result;
}

*/
Rational add_two_rationals(Rational const a_first, Rational const a_second)
{
    Rational result = a_first;
    result.add(a_second);

    return result;
}


Rational add(Rational const a_rational, int const a_num)
{
    Rational result = a_rational;
    result.add(a_num);

    return result;
}


Rational add(int const a_num, Rational const a_rational)
{
    Rational result = a_rational;
    result.add(a_num);

    return result;
}


Rational substruct_two_rationals(Rational const a_first, Rational const a_second)
{
    Rational result = a_first;
    result.substruct(a_second);

    return result;
}

   
Rational multiply_two_rationals(Rational const a_first, Rational const a_second)
{
    Rational result = a_first;
    result.multiply(a_second);

    return result;
}

Rational multiply_rational_by_int(Rational const a_rational, int a_num)
{
    Rational result = a_rational;
    result.multiply(a_num);

    return result;
}


Rational divide_two_rationals(Rational const a_first, Rational const a_second)
{
    Rational result = a_first;
    result.divide(a_second);

    return result;
}


bool equal(Rational const a_first, Rational const a_second)
{
    int numer1 = a_first.get_numerator();
    int denom1 = a_first.get_denumerator();

    int numer2 = a_second.get_numerator();
    int denom2 = a_second.get_denumerator();

    return numer1 * denom2 == numer2 * denom1;
}


bool not_equal(Rational const a_first, Rational const a_second)
{
    return !equal(a_first, a_second);
}

void Rational::operator*=(const Rational a_rational)
{
    this->multiply(a_rational);
}


void Rational::operator+=(const Rational a_rational)
{
    this->add(a_rational);
}



void Rational::operator-=(const Rational a_rational)
{
    this->substruct(a_rational);
}


void Rational::operator/=(const Rational a_rational)
{
    this->divide(a_rational);
}




Rational operator*(const Rational a_first, const Rational a_second) 
{
    return multiply_two_rationals(a_first, a_second);
}


Rational operator+(const Rational a_first, const Rational a_second) 
{
    return add_two_rationals(a_first, a_second);
}


Rational operator-(const Rational a_first, const Rational a_second) 
{
    return substruct_two_rationals(a_first, a_second);
}


Rational operator/(const Rational a_first, const Rational a_second) 
{
    return divide_two_rationals(a_first, a_second);
}

bool operator<(const Rational a_first, const Rational a_second)
{
    if(a_first.is_positive() && !a_second.is_positive())
    {
        return false;
    }
    else if(!a_first.is_positive() && a_second.is_positive())
    {
        return true;
    }

    return !(substruct_two_rationals(a_first, a_second)).is_positive(); 
}


bool operator<=(const Rational a_first, const Rational a_second)
{
    return !(a_first > a_second);

}

bool operator>(const Rational a_first, const Rational a_second)
{
    if(a_first.is_positive() && !a_second.is_positive())
    {
        return true;
    }
    else if(!a_first.is_positive() && a_second.is_positive())
    {
        return false;
    }

    return (substruct_two_rationals(a_first, a_second)).is_positive();
}

bool operator>=(const Rational a_first, const Rational a_second)
{
    return !(a_first < a_second);
}

bool operator==(const Rational a_first, const Rational a_second)
{
    return equal(a_first, a_second);
}

bool operator!(const Rational a_rational)
{
    return (a_rational.get_numerator() == 0);
}

bool operator!=(const Rational a_first, const Rational a_second)
{
    return not_equal(a_first, a_second);
}


}//namespace algebra

    
static size_t find_gcd(int a_first, int a_second)
    {
        if(a_first <= a_second)
        {
            size_t i = a_first;

            while(i)
            {
                if(!(a_first % i) && !(a_second % i))
                {
                    return i;
                }

                if(i == 0)
                {
                    break;
                }
                --i;
            }
        }
        else
        {
            size_t i = a_second;

            while(i)
            {
                if(!(a_first % i) && !(a_second % i))
                {
                    return i;
                }

                if(i == 0)
                {
                    break;
                }
                --i;
            }
        }

        return 1;
    }
