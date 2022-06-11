#ifndef MULTI_TRANSFORMER_HPP
#define MULTI_TRANSFORMER_HPP

#include <string>
#include <vector>

#include "text_transformer.hpp"


namespace text
{

// MultiTransformer implements the abstraction
// MultiTransformer is-a TextTransformer
class MultiTransformer: public TextTransformer {
public:
    MultiTransformer(std::vector<TextTransformer*> const& a_transformers);
    virtual std::string transform(std::string& a_string);

//    ~MultiTransformer(); compiler will do

private:
	void extract_transformers(std::string const& a_string);
	TextTransformer* get_transformer(std::string const& a_string);
private:
    std::vector<TextTransformer*> m_transformers;  
};

}//namespace text







#endif // MULTI_TRANSFORMER_HPP