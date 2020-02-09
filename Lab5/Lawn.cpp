#include "Lawn.h"
#include <cmath>

namespace lab5
{
	Lawn::Lawn() : COST_BERMUDA(8.0), COST_BAHIA(5.0),
		COST_BENT_GRASS(3.0), COST_PERENNIAL_RYEGRASS(2.5),
		COST_ST_AUGUSTINE(4.5), AREA_ROLL_LAWN(0.3)
	{

	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double price = static_cast<double>(GetArea());
		switch (grassType)
		{
		case lab5::BERMUDA:
			price *= COST_BERMUDA;
			break;
		case lab5::BAHIA:
			price *= COST_BAHIA;
			break;
		case lab5::BENTGRASS:
			price *= COST_BENT_GRASS;
			break;
		case lab5::PERENNIAL_RYEGRASS:
			price *= COST_PERENNIAL_RYEGRASS;
			break;
		case lab5::ST_AUGUSTINE:
			price *= COST_ST_AUGUSTINE;
			break;
		default:
			return 0;
		}
		return static_cast<unsigned int>(round(price));
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double area = static_cast<double>(GetArea());

		if (area != 0)
		{
			double div = area / AREA_ROLL_LAWN;
			div = ceil(div);
			return static_cast<unsigned int>(div);
		}
		else
		{
			return 0;
		}
	}
}
