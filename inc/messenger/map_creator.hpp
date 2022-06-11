#ifndef MAP_CREATOR_HPP
#define MAP_CREATOR_HPP

#include <map>
#include <string>

#include "text_transformer.hpp"
#include "censor.hpp"
#include "lowercase.hpp"
#include "uppercase.hpp"
#include "rot13.hpp"

/*tried to only declare the function and dont include all hpp files. but didnt compile*/

namespace text
{
	TextTransformer* create_censor();
	TextTransformer* create_lowercase();
	TextTransformer* create_uppercase();
	TextTransformer* create_rotThirteen();
}

typedef text::TextTransformer* (*functionPointer)(void);

class MapCreator
{

public:

	MapCreator();

	std::map<std::string, functionPointer> const& get_map() const;

private:
	std::map<std::string, functionPointer> m_transformers;
};



#endif//MAP_CREATOR_HPP