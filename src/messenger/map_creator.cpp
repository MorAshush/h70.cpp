#include "map_creator.hpp"



MapCreator::MapCreator()
{
	m_transformers[text::Censor::name()] = &text::create_censor;
	m_transformers[text::LowerCase::name()] = &text::create_lowercase;
	m_transformers[text::UpperCase::name()] = &text::create_uppercase;
	m_transformers[text::RotThirteen::name()] = &text::create_rotThirteen;
}

std::map<std::string, functionPointer> const& MapCreator::get_map() const
{
	return m_transformers;
}