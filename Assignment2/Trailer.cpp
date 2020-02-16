#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight) : mWeight(weight)
	{

		//std::cout << "Trailer 생성자 호출" << std::endl;
	}

	Trailer::Trailer() : mWeight(0)
	{

		//std::cout << "Trailer 생성자 호출" << std::endl;
	}

	Trailer::~Trailer()
	{

		//std::cout << "Trailer 소멸자 호출" << std::endl;
	}

	unsigned int Trailer::GetWeight() const
	{
		return mWeight;
	}
}
