#include <iostream>
#include <cstddef>

#include "multi_transformer.hpp"
#include "uppercase.hpp"
#include "lowercase.hpp"
#include "rot13.hpp"
#include "censor.hpp"

namespace text
{

MultiTransformer::MultiTransformer(std::vector<TextTransformer*> const& a_transformers)
: TextTransformer()
, m_transformers(a_transformers)
{

}

MultiTransformer::~MultiTransformer()
{
	size_t size = m_transformers.size();
	for(size_t i = 0; i < size; ++i)
	{
		delete m_transformers[i];
	}
}


std::string MultiTransformer::transform(std::string& a_string)
{
	size_t size = m_transformers.size();

	for(size_t i = 0; i < size; ++i)
	{
		m_transformers[i]->transform(a_string);
	}

	return a_string;
}

}//namespace text