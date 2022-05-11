#include <cstdio>
#include <cassert>
#include "rational.hpp"


// Rational* RationalCreate(int num, int denom);

Rational::Rational(int a_num, int a_denom)
: m_numerator(a_num)               // MIL
, m_denumerator(a_denom)
{
    assert(m_denumerator != 0 && "denom can't be zero");    
    // this->m_numerator = a_num;
    // m_denumerator = a_denom;

    //TODO: place the sign of the rational on the numerator if one of them is negative.
}

Rational::Rational(int a_num)
: m_numerator(a_num)               // MIL
, m_denumerator(1)
{    
}


// void RationalScale(Rational* r, int s);
void Rational::scale(int s)
{
    this->m_numerator *= s;
    m_denumerator *= s;
}


// void RationalPrint(Rational const* r);
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


void Rational::display(const char* fmt) const
{
    printf(fmt, m_numerator, m_denumerator);
}


int Rational::get_numerator() const
{
    return this-> m_numerator;
}

int Rational::get_denumerator() const 
{
    return this-> m_denumerator;
}

bool Rational::is_positive() const
{
    if (m_numerator > 0 && m_denumerator > 0)
    {
        return 1;
    }

    return 0;
}

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

void Rational::add(int a_num) 
{
    if(!a_num)
    {
        return;
    }

    this->m_numerator += (a_num * this-> m_denumerator);
}

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

void Rational::substruct(int a_num)
{
    if(!a_num)
    {
        return;
    }
    
    this->m_numerator -= (a_num * this-> m_denumerator);
}

void Rational::multiply(Rational a_rational) 
{
    int numer2 = a_rational.m_numerator;
    int denom2 = a_rational.m_denumerator;

    this->m_numerator *= numer2;
    this-> m_denumerator *= denom2;
}
/*************************************************************************************/
void Rational::multiply(int a_num) 
{
    this->m_numerator *= a_num;
}

void Rational::divide(Rational a_rational) 
{
    int numer2 = a_rational.m_numerator;

    assert(numer2 != 0 && "cannot be divided by zero"); 

    int denom2 = a_rational.m_denumerator;

    this->m_numerator *= denom2;
    this-> m_denumerator *= numer2;
}

void Rational::divide(int a_num)
{
    assert(a_num != 0 && "cannot be divided by zero");

    this-> m_denumerator *= a_num ;
}

void Rational::reduce()
{
    int numer = this->m_numerator;
    int denom = this-> m_denumerator;

    if(numer > denom)
    {
        size_t i = denom;

        while(denom--)
        {
            i = denom;

            if( !(numer % i) && !(denom % i) )
            {
                numer /= i;
                denom /= i;
            }
        }
    }
    else if(numer < denom)
    {
       size_t i = numer;

        while(numer--)
        {
            if( !(numer % i) && !(denom % i) )
            {
                numer /= i;
                denom /= i;

            }
        } 
    }
    else
    {
        numer = 1;
        denom = 1;
    }

    this->m_numerator = numer;
    this->m_denumerator = denom;
}

Rational add_two_rationals(Rational a_rational1, Rational a_rational2)
{
    Rational result = a_rational1;
    result.add(a_rational2);

    return result;
}
/*
bool is_rationals_equal(Rational const a_rational1, Rational const a_rational2)
{

}*/