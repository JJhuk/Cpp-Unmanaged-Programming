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
		const double COST_BERMUDA;
		const double COST_BAHIA;
		const double COST_BENT_GRASS;
		const double COST_PERENNIAL_RYEGRASS;
		const double COST_ST_AUGUSTINE;

		//∑— ¿‹µ¿« ≥–¿Ã
		const double AREA_ROLL_LAWN;
	};
}
