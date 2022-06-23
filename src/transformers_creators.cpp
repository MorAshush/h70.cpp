#include "transformers_creators.hpp"

namespace text
{
	TextTransformer* create_censor()
	{
		return new Censor;
	}

	TextTransformer* create_lowercase()
	{
		return new LowerCase;
	}

	TextTransformer* create_uppercase()
	{
		return new UpperCase;
	}

	TextTransformer* create_rotThirteen()
	{
		return new RotThirteen;
	}
}




