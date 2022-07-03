#ifndef SELECTOR_BASE_HPP
#define SELECTOR_BASE_HPP


namespace net
{

class SelectorBase
{

public:
	virtual ~SelectorBase();

	virtual void select() = 0;
};

}//namespace net






#endif // SELECTOR_BASE_HPP
