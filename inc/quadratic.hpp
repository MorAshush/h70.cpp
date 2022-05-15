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
        Rational get_first_cofefficient() const;
        Rational get_second_cofefficient() const;
        Rational get_third_cofefficient() const;

    private:
        void display(const char* fmt) const;
/*      Rational calc_pol_root_on_plus(Rational a_a, Rational a_b, Rational a_c, roots* a_roots);
        Rational calc_pol_root_on_minus(Rational a_a, Rational a_b, Rational a_c, roots* a_roots);*/

    public:
/*      roots roots()const;*/

    private:    
        Rational m_a;
        Rational m_b;
        Rational m_c;

/*        roots m_polinumRoots;*/

};


/**
 * @brief global function that multiplys a quadratic by an int. returns a new quadratic result.
 
 * @param a_quadratic and a_num to multiply by.
 * @return a quadratic of the multipication result
 */
Quadratic multiply(const Quadratic a_quadratic, int a_num);


/**
 * @brief global function that multiplys a quadratic by a rational. returns a new quadratic result.
 
 * @param a_quadratic and a_rational to multiply by.
 * @return a quadratic of the multipication result
 */
Quadratic multiply(const Quadratic a_quadratic, const Rational a_rational);

/**
 * @brief global function to add two quadratics. returns a new quadratic result.
 
 * @param a_first and a_second to add together.
 * @return a quadratic of the adding result
 */
Quadratic add_two_quadratics(Quadratic a_first, Quadratic a_second);

}//namespace algebra




#endif
