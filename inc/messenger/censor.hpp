#ifndef CENSOR_HPP
#define CENSOR_HPP

#include <string>
#include <list>
#include <map>

#include "text_transformer.hpp"


namespace text
{

// Censor implements the abstraction
// Censor is-a TextTransformer
class Censor: public TextTransformer {
public:

//  ~Censor(); compiler will do
    Censor();
    virtual std::string transform(std::string& a_string);

public:

    static std::string const& name();

private:

    static const std::string m_name;

private:
    
    std::map<std::string, bool> m_badWords;  
};



TextTransformer* create_censor();

}//namespace text



#endif //CENSOR_HPP