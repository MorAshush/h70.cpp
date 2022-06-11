#include <list>
#include <iterator>

#include "transformers_factory.hpp"


TransformersFactory::TransformersFactory(std::map<std::string, functionPointer> const& a_transformers)
: m_transformers(a_transformers)
{

}

text::TextTransformer* TransformersFactory::create(std::string a_string)
{
	std::map<std::string, functionPointer>::iterator transformerCreatorPtr;
	transformerCreatorPtr = m_transformers.find(a_string);

	if(transformerCreatorPtr == m_transformers.end())
	{
		return 0;
	}

	return transformerCreatorPtr->second();
	
}

std::vector<text::TextTransformer*> TransformersFactory::create(std::list<std::string> a_namesList)
{
	std::vector<text::TextTransformer*> transformers;
	transformers.reserve(a_namesList.size());

	std::list<std::string>::iterator currentName = a_namesList.begin();
	std::list<std::string>::iterator end = a_namesList.end();
	while(currentName != end)
	{
		std::map<std::string, functionPointer>::iterator transformerCreatorPtr;

		transformerCreatorPtr = m_transformers.find(*currentName);

		if(transformerCreatorPtr != m_transformers.end())
		{
			transformers.push_back(transformerCreatorPtr->second());
		}

		++currentName;
	}

	return transformers;
}