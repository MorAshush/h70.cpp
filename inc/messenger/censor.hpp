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
    Censor(std::list<std::string> a_badWords);
    virtual std::string transform(std::string& a_string);

//    ~Censor();
private:
    std::map<std::string, bool> m_badWords;  
};

}//namespace text



#endif //CENSOR_HPP