#include "map_creator.hpp"



MapCreator::MapCreator()
{
	m_transformers["censor"] = &text::create_censor;
	m_transformers["lowercase"] = &text::create_lowercase;
	m_transformers["uppercase"] = &text::create_uppercase;
	m_transformers["rot13"] = &text::create_rotThirteen;

}

std::map<std::string, functionPointer> const& MapCreator::get_map() const
{
	return m_transformers;
}