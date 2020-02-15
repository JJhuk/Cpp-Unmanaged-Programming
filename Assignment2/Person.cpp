#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight) : mString(name), mWeight(weight)
	{

	}

	Person::Person() : mString(""), mWeight(0)
	{

	}

	Person::Person(const Person& other) : mString(other.mString), mWeight(other.mWeight)
	{
	}

	Person& Person::operator=(const Person& other)
	{
		if (&other != &(*this))
		{
			mString = other.mString;
			mWeight = other.mWeight;
		}

		return *this;
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
