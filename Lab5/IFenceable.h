#pragma once

#include "eFenceType.h"

namespace lab5
{
	class IFenceable
	{
	public:
		virtual unsigned int GetMinimumFencesCount() const = 0;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const = 0;

		//울타리 자재 가격
		const unsigned int COST_RED_CENDAR = 6;
		const unsigned int COST_SPRUCE = 7;

		//울타리 너비
		const double WIDTH_FENCE = 0.25;
	};
}
