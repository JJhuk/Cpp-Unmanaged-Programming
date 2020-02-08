#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn() : COST_BERMUDA(800), COST_BAHIA(500),
		COST_BENT_GRASS(300), COST_PERENNIAL_RYEGRASS(250),
		COST_ST_AUGUSTINE(450), AREA_ROLL_LAWN(0.3)
	{

	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		switch (grassType)
		{
		case lab5::BERMUDA:
			return GetArea() * COST_BERMUDA;

		case lab5::BAHIA:
			return GetArea() * COST_BAHIA;

		case lab5::BENTGRASS:
			return GetArea() * COST_BENT_GRASS;

		case lab5::PERENNIAL_RYEGRASS:
			return GetArea() * COST_PERENNIAL_RYEGRASS;

		case lab5::ST_AUGUSTINE:
			return GetArea() * COST_ST_AUGUSTINE;
		default:
			return 0;
		}
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double area = static_cast<double>(GetArea());

		if (area != 0)
		{
			double div = area / AREA_ROLL_LAWN;
			div += 0.5;	//무조껀 반올림 해야 하기 때문 최솟값
			return static_cast<unsigned int>(div);
		}
		else
		{
			return 0;
		}
	}
}
