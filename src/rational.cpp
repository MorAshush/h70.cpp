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

Rational Rational::add(Rational a_rational) const
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    int numer2 = a_rational.m_numerator;
    int denom2 = a_rational.m_denumerator;

    if( denom1 == denom2 )
    {
        numer1 += numer2;
    }
    else if( denom1 < denom2 )
    {
        if( !(denom2 % denom1) )
        {
            int factor = denom2 / denom1;

            denom1 = denom2;

            numer1 *= factor;
            numer1 += numer2;
        }
        else
        {
            int newDenumerator = denom1 * denom2;

            numer1 *= denom2;
            numer2 *=  denom1;

            numer1 += numer2;
            denom1 = newDenumerator;
        }
    }
    else 
    {
        if( !(denom1 % denom2) )
        {
            int factor = denom1 / denom2;

            numer2 *= factor;
            numer1 += numer2;
        }
        else
        {
            int newDenumerator = denom1 * denom2;

            numer1 *= denom2;
            numer2 *=  denom1;

            numer1 += numer2;
            denom1 = newDenumerator;
        }
    }

    Rational sum(numer1, denom1);

    return  sum;  
}

Rational Rational::add(int a_num) const
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    if(!a_num)
    {
        Rational sum(numer1, denom1);

        return sum;
    }
    else if(a_num < 0)
    {
        numer1 -= (a_num * denom1);
    }
    else
    {
        numer1 += (a_num * denom1);
    }

    Rational sum(numer1, denom1);

    return sum;

}

Rational Rational::substruct(Rational a_rational) 
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    int numer2 = a_rational.m_numerator;
    int denom2 = a_rational.m_denumerator;

    if( denom1 == denom2 )
    {
        numer1 -= numer2;
    }
    else if( denom1 > denom2 )
    {
        if( !(denom1 % denom2) )
        {
            int factor = denom1 / denom2;

            numer2 *= factor;
            numer1 -= numer2;
        }
        else
        {
            int newDenumerator = denom1 * denom2;

            numer1 *= denom2;
            numer2 *=  denom1;

            numer1 -= numer2;
            denom1 = newDenumerator;           
        }
    }
    else 
    {
        if( !(denom2 % denom1) )
        {
            int factor = denom2 / denom1;

            denom1 = denom2;

            numer1 *= factor;
            numer1 -= numer2;
        }
        else
        {
            int newDenumerator = denom1 * denom2;

            numer1 *= denom2;
            numer2 *=  denom1;

            numer1 -= numer2;
            denom1 = newDenumerator;
        }
    }

    Rational result(numer1, denom1);

    return result;
}

Rational Rational::substruct(int a_num) const
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    if(!a_num)
    {
        Rational sum(numer1, denom1);

        return sum;
    }
    else if(a_num < 0)
    {
        numer1 += (a_num * denom1);
    }
    else
    {
        numer1 -= (a_num * denom1);
    }

    Rational sum(numer1, denom1);

    return sum;

}

Rational Rational::multiply(Rational a_rational) 
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    int numer2 = a_rational.m_numerator;
    int denom2 = a_rational.m_denumerator;

    numer1 *= numer2;
    denom1 *= denom2;

    Rational result(numer1, denom1);

    return result;
}

Rational Rational::multiply(int a_num) const
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    if(!a_num)
    {
        Rational result(a_num, denom1);

        return result;
    }
    
    numer1 *= a_num;

    if(numer1 < 0 && denom1 < 0)
    {
        Rational result(-numer1, -denom1);

        return result;
    }

    Rational result(numer1, denom1);

    return result;

}

Rational Rational::divide(Rational a_rational) 
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    int numer2 = a_rational.m_numerator;

    assert(numer2 != 0 && "cannot be divided by zero"); 

    int denom2 = a_rational.m_denumerator;

    numer1 *= denom2;
    denom1 *= numer2;

    Rational result(numer1, denom1);

    return result;
}

Rational Rational::divide(int a_num) const
{
    int numer1 = this->m_numerator;
    int denom1 = this-> m_denumerator;

    assert(a_num != 0 && "cannot be divided by zero");

    denom1 *= a_num ;

    Rational result(numer1, denom1);

    return result;

}

Rational Rational::reduce() const
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

    Rational result(numer, denom);

    return result;

}
/*
Rational add_two_rationals(Rational const a_rational1, Rational const a_rational2)
{
    int numer1 = a_rational1.get_m_numerator();
    int denom1 = a_rational1.get_m_denumerator();

    int numer2 = a_rational2.get_m_numerator();
    int denom2 = a_rational2.get_m_denumerator();



}

bool is_rationals_equal(Rational const a_rational1, Rational const a_rational2)
{

}*/