#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int vectorSum = 0;
		int vSize = v.size();
		for (int i = 0; i < vSize; i++)
		{
			vectorSum += v[i];
		}
		return vectorSum;
	}

	int Min(const std::vector<int>& v)
	{
		int vMin = INT_MAX;
		int vSize = v.size();
		for (int i = 0; i < vSize; i++)
		{
			if (i == 0)
				vMin = v[i];
			else
				vMin = vMin < v[i] ? vMin : v[i];
		}
		return vMin;
	}

	int Max(const std::vector<int>& v)
	{
		int vMax = INT_MIN;
		unsigned int vSize = v.size();
		for (unsigned int i = 0; i < vSize; i++)
		{
			vMax = vMax > v[i] ? vMax : v[i];
		}
		return vMax;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() != 0)
		{
			float vSum = 0;
			unsigned int vSize = v.size();
			for (unsigned int i = 0; i < vSize; i++)
			{
				vSum += static_cast<float>(v[i]);
			}
			return vSum / static_cast<float>(vSize);
		}
		else
		{
			return 0;
		}
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		int checkOccurrence = 0;
		int valueNumber;

		int maxOccurence = 0;
		int maxValueNumber = 0;
		if (!v.empty())
		{
			for (unsigned int i = 0; i < v.size() - 1; i++)
			{
				valueNumber = v[i];
				for (unsigned int j = i + 1; j < v.size(); j++)
				{
					if (valueNumber == v[j])
					{
						checkOccurrence++;
					}
				}
				if (checkOccurrence > maxOccurence)
				{
					maxOccurence = checkOccurrence;
					maxValueNumber = valueNumber;
					checkOccurrence = 0;
					valueNumber = 0;
				}
			}
		}
		return maxValueNumber;
	}

	void SortDescending(std::vector<int>& v)
	{
		if (v.size() >= 2)
		{
			for (unsigned int i = v.size() - 1; i >= 0; i--)
			{
				for (unsigned int j = 0; j < i; j++)
				{
					if (v[j] < v[j + 1])
					{
						int temp = v[j];
						v[j] = v[j + 1];
						v[j + 1] = temp;
					}
				}
			}
		}
	}

}
