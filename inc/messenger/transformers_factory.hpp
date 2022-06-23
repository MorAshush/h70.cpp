#ifndef TRANSFORMERS_FACTORY_HPP
#define TRANSFORMERS_FACTORY_HPP

#include <string>
#include <vector>
#include <list>

#include "map_creator.hpp"
#include "text_transformer.hpp"


class TransformersFactory
{

public:
	TransformersFactory(std::map<std::string, functionPointer> const& a_transformers);

	text::TextTransformer* create(std::string const& a_string);
	std::vector<text::TextTransformer*> create(std::list<std::string> const& a_namesList);

private:
	std::map<std::string, functionPointer> m_transformers;
};




#endif//TRANSFORMERS_FACTORY_HPP