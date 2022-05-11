#ifndef RATIONAL_H
#define RATIONAL_H



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
        void add(Rational a_rational);
        void add(int a_num);
        void substruct(Rational a_rational);
        void substruct(int a_num);
        void multiply(Rational a_rational);
        void multiply(int a_num);
        void divide(Rational a_rational);
        void divide(int a_num);
        void reduce(); 

    private:
        void display(const char* fmt) const;
        
    private:    
        int m_numerator;
        int m_denumerator;
};

/*
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
        Rational add(Rational a_rational) const;
        Rational add(int a_num) const;
        Rational substruct(Rational a_rational);
        Rational substruct(int a_num) const;
        Rational multiply(Rational a_rational);
        Rational multiply(int a_num) const;
        Rational divide(Rational a_rational);
        Rational divide(int a_num) const;
        Rational reduce() const; 

    private:
        void display(const char* fmt) const;
        
    private:    
        int m_numerator;
        int m_denumerator;
};*/

/**
 * @brief returns the sum of two rationals as a Rational
 * complixity ?
 * @param a_rational1 and a_rational2 to sum together
 * @return a class Rational variable with the sum result
 */
Rational add_two_rationals(Rational a_rational1, Rational a_rational2);

/**
 * @brief check if two rationals are equal, returns true or false
 * complixity ?
 * @param a_rational1 and a_rational2 to compare between 
 * @return int 0 if not equals, or 1 if equals
 */
bool is_rationals_equal(Rational const a_rational1, Rational const a_rational2);


#endif