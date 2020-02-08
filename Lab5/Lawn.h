#pragma once

#include "eGrassType.h"

namespace lab5
{
	class Lawn
	{
	public:
		Lawn();
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

		//m2 ¥Á ¿‹µ¿« ∞°∞›
		const unsigned int COST_BERMUDA;
		const unsigned int COST_BAHIA;
		const unsigned int COST_BENT_GRASS;
		const unsigned int COST_PERENNIAL_RYEGRASS;
		const unsigned int COST_ST_AUGUSTINE;

		//∑— ¿‹µ¿« ≥–¿Ã
		const double AREA_ROLL_LAWN;
	};
}
