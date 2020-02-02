#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		Person();
		~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;
	private:
		const std::string mString;
		const unsigned int mWeight;
	};
}
