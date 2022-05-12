#ifndef QUADRATIC_HPP
#define QUADRATIC_HPP

#include "rational.hpp"

#include <cstddef>

namespace algebra
{
/*struct Roots
{
    Rational m_first;
    Rational m_second;

    size_t m_numOfRoots;
}roots;*/


class Quadratic 
{    
    public:

        Quadratic(Rational a_a, Rational a_b, Rational a_c);
        void print() const;
        void calc_polinum_roots();
        void multiply(int a_num);
        void multiply(Rational a_rational);
/*        roots roots()const;*/


    private:
        void display(const char* fmt) const;
/*        Rational calc_pol_root_on_plus(Rational a_a, Rational a_b, Rational a_c, roots* a_roots);
        Rational calc_pol_root_on_minus(Rational a_a, Rational a_b, Rational a_c, roots* a_roots);*/


    private:    
        Rational m_a;
        Rational m_b;
        Rational m_c;

/*        roots m_polinumRoots;*/

};


}//namespace algebra





#endif
    /*    Quadratic(Rational a_rational, int a_power, int a_num2, int a_num3);
        Quadratic(Rational a_rational1, int a_power, Rational a_rational2, int a_num3);
        Quadratic(Rational a_rational1, int a_power, Rational a_rational2, Rational a_rational3);
        Quadratic(int a_num, int a_power, Rational a_rational1, Rational a_rational2);
        Quadratic(int a_num1, int a_power, int a_num2, Rational a_rational);
        Quadratic(Rational a_rational1, int a_power, int a_num, Rational a_rational2);
        Quadratic(int a_num1, int a_power, Rational a_rational, int a_num2);*/