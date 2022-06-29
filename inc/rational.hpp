#ifndef RATIONAL_H
#define RATIONAL_H


namespace algebra
{
class Rational 
{    
    public:
        Rational(int a_num);
        Rational(int a_num, int a_denumerator);

        void print() const;

        void scale(int a_s);

        int get_numerator() const;
        int get_denumerator() const;

        bool is_positive() const;

        void add(Rational const& a_rational);

        void substruct(Rational a_rational);

        void multiply(Rational a_rational);

        void divide(Rational a_rational);

        void reduce();

        void operator*=(const Rational a_rational);

        void operator+=(const Rational a_rational);

        void operator-=(const Rational a_rational);

        void operator/=(const Rational a_rational);
/*   

        Rational sqrt_rational(const Rational a_rational) const;
*/

    private:
        void display(const char* fmt) const;
        
    private:    
        int m_numerator;
        int m_denumerator;
};

/**
 * @brief global function that adds two rationals: a_first with a_second and returns a new rational result.
 
 * @param a_first and a_second to add to other 
 * @return a rational of the adding result
 */
Rational add_two_rationals(Rational const a_first, Rational const a_second);


/**
 * @brief global function to subtruct two rationals: a_first by a_second and returns a new rational result.
 
 * @param a_first and a_second to subtruct from each other 
 * @return a rational of the subtruct result
 */
Rational substruct_two_rationals(Rational const a_first, Rational const a_second);


/**
 * @brief global function that multiplys two rationals: a_first by a_second and returns a new rational result.
 
 * @param a_first and a_second to multiply by each other 
 * @return a rational of the multipication result
 */
Rational multiply_two_rationals(Rational const a_first, Rational const a_second);


/**
 * @brief global function that divides two rationals: a_first by a_second and returns a new rational result.
 
 * @param a_first and a_second to divide in each other 
 * @return a rational of the division result
 */
Rational divide_two_rationals(Rational const a_first, Rational const a_second);


/**
 * @brief check if two rationals are equal, returns true or false
 
 * @param a_rational1 and a_rational2 to compare between 
 * @return int true(1) if equals, or false(0) if not equals 
 */
bool equal(Rational const a_first, Rational const a_second);


/**
 * @brief check if two rationals are not equal, returns true or false
 
 * @param a_rational1 and a_rational2 to compare between 
 * @return int true(1) if not equals, or false(0) if equals
 */
bool not_equal(Rational const a_first, Rational const a_second);


/**
 * @brief multiplys two rationals: a_first by a_second and returns a new rational result.
 
 * @param a_first and a_second to multiply by each other 
 * @return a rational of the multipication result
 */
Rational operator*(const Rational a_first, const Rational a_second);


/**
 * @brief adds two rationals: a_first with a_second and returns a new rational result.
 
 * @param a_first and a_second to add to other 
 * @return a rational of the adding result
 */
Rational operator+(const Rational a_first, const Rational a_second);


/**
 * @brief subtruct two rationals: a_first by a_second and returns a new rational result.
 
 * @param a_first and a_second to subtruct from each other 
 * @return a rational of the subtruct result
 */
Rational operator-(const Rational a_first, const Rational a_second);


/**
 * @brief divides two rationals: a_first by a_second and returns a new rational result.
 
 * @param a_first and a_second to divide in each other 
 * @return a rational of the division result
 */
Rational operator/(const Rational a_first, const Rational a_second);


/**
 * @brief an operator overloading function to check if one rational is smaller than the other, returns true or false
 
 * @param a_first and a_second to compare between 
 * @return int true(1) if a_first is smaller, or false(0) if otherwise
 */
bool operator<(const Rational a_first, const Rational a_second);


bool operator<=(const Rational a_first, const Rational a_second);


/**
 * @brief an operator overloading function to check if two rationals are equal, returns true or false
 
 * @param a_first and a_second to compare between 
 * @return int true(1) if equals, or false(0) if not equals
 */
bool operator==(const Rational a_first, const Rational a_second);


/**
 * @brief an operator overloading function to check if one rational is bigger than the other, returns true or false
 
 * @param a_first and a_second to compare between 
 * @return int true(1) if a_first is bigger, or false(0) if otherwise
 */
bool operator>(const Rational a_first, const Rational a_second);


bool operator>=(const Rational a_first, const Rational a_second);


/**
 * @brief check if a_rational is zero , returns true or false
 
 * @param a_rational to compare to zero 
 * @return int true(1) if zero, or false(0) if not zero
 */
bool operator!(const Rational a_rational); 


/**
 * @brief an operator overloading function to check if two rationals are not equal, returns true or false
 
 * @param a_rational1 and a_rational2 to compare between 
 * @return int true(1) if not equals, or false(0) if equals
 */
bool operator!=(const Rational a_first, const Rational a_second); 

}//namespace algebra



#endif