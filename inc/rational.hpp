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
            void add(Rational a_rational);
            void add(int a_num);
            void substruct(Rational a_rational);
            void substruct(int a_num);
            void multiply(Rational a_rational);
            void multiply(int a_num);
            void divide(Rational a_rational);
            void divide(int a_num);
            void reduce();
            Rational sqrt_rational(const Rational a_rational) const;


        private:
            void display(const char* fmt) const;
            
        private:    
            int m_numerator;
            int m_denumerator;
    };

    /**
     * @brief returns the sum of two rationals as a Rational
     * complixity ?
     * @param a_rational1 and a_rational2 to sum together
     * @return a class Rational variable with the sum result
     */
    Rational add_two_rationals(Rational const a_first, Rational const a_second);

    Rational add_two_rationals(int a_num);



    Rational substruct_two_rationals(Rational const a_first, Rational const a_second);

    Rational substruct_two_rationals(int a_num);


    Rational multiply_two_rationals(Rational const a_first, Rational const a_second);

    Rational multiply_rational_by_int(Rational const a_rational, int a_num);


    Rational divide_two_rationals(Rational const a_first, Rational const a_second);

    Rational divide_two_rationals(int a_num);




    /**
     * @brief check if two rationals are equal, returns true or false
     
     * @param a_rational1 and a_rational2 to compare between 
     * @return int 0 if not equals, or 1 if equals
     */
    bool equal(Rational const a_first, Rational const a_second);
    bool not_equal(Rational const a_first, Rational const a_second);

}//namespace algebra



#endif