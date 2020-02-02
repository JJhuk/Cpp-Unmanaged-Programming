#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight) : mString(name), mWeight(weight)
	{

	}

	Person::Person() : mString(""), mWeight(0)
	{
		
	}

	Person::~Person()
	{
		
	}

	const std::string& Person::GetName() const
	{
		return mString;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}
