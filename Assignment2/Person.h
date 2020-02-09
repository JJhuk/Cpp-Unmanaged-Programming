#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		Person();
		Person(const Person& other);

		Person& operator=(const Person& other);
		~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;
	private:
		std::string mString;
		unsigned int mWeight;
	};
}
