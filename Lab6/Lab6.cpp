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
		int vSize = v.size();
		for (int i = 0; i < vSize; i++)
		{
			vMax = vMax > v[i] ? vMax : v[i];
		}
		return vMax;
	}

	float Average(const std::vector<int>& v)
	{
		if (!v.empty())
		{
			float vSum = 0;
			int vSize = v.size();
			for (int i = 0; i < vSize; i++)
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
		int maxOccurence = 0;
		int maxValueNumber = 0;
		int vSize = v.size();
		if (vSize >= 2)
		{
			for (int i = 0; i < vSize - 1; i++)
			{
				int valueNumber = v[i];
				for (int j = i + 1; j < vSize; j++)
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
			int vSize = v.size();
			for (int i = vSize - 1; i >= 0; i--)
			{
				for (int j = 0; j < i; j++)
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
