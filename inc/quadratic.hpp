#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

#include "rational.hpp"

class Quadratic 
{    
    public:

        Quadratic(Rational a_rational1, Rational a_rational2, Rational a_rational3);
        void print() const;
        Rational* roots(Quadratic a_Quadratic) const;
        void multiply(int a_num);
        void multiply(Rational a_rational);

    private:
        void display(const char* fmt) const;
        Rational calc_pol_root_on_plus(Rational a_rational1, Rational a_rational2, Rational a_rational3);
        Rational calc_pol_root_on_minus(Rational a_rational1, Rational a_rational2, Rational a_rational3);

    private:    
        Rational m_first;
        Rational m_second;
        Rational m_third;

};




#endif
    /*    Quadratic(Rational a_rational, int a_power, int a_num2, int a_num3);
        Quadratic(Rational a_rational1, int a_power, Rational a_rational2, int a_num3);
        Quadratic(Rational a_rational1, int a_power, Rational a_rational2, Rational a_rational3);
        Quadratic(int a_num, int a_power, Rational a_rational1, Rational a_rational2);
        Quadratic(int a_num1, int a_power, int a_num2, Rational a_rational);
        Quadratic(Rational a_rational1, int a_power, int a_num, Rational a_rational2);
        Quadratic(int a_num1, int a_power, Rational a_rational, int a_num2);*/