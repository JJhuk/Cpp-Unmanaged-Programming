#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		size_t mapSize = keys.size() < values.size() ? keys.size() : values.size();

		for (size_t i = 0; i < mapSize; i++)
		{
			m.insert(std::make_pair(keys[i], values[i]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(m.size());

		for (typename std::map<K, V>::const_iterator iterator = m.begin(); iterator != m.end(); iterator++)
		{
			v.push_back(iterator->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		v.reserve(m.size());

		for (typename std::map<K, V>::const_iterator iterator = m.begin(); iterator != m.end(); iterator++)
		{
			v.push_back(iterator->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		rv.reserve(v.size());

		for (typename std::vector<T>::const_reverse_iterator iterator = v.rbegin(); iterator != v.rend(); iterator++)
		{
			rv.push_back(*iterator);
		}
		return rv;
	}

	template <typename T>
	void PushAndCheckOverlap(std::vector<T>& combined, const std::vector<T>& inputVector)
	{
		for (size_t i = 0; i < inputVector.size(); i++)
		{
			bool bIsNotInVector = false;
			for (size_t j = 0; j < combined.size(); j++)
			{
				if (combined[j] == inputVector[i])
				{
					bIsNotInVector = true;
					break;
				}
			}
			if (!bIsNotInVector)
			{
				combined.push_back(inputVector[i]);
			}
		}
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		combined.reserve(v1.size() + v2.size());
		PushAndCheckOverlap(combined, v1);
		PushAndCheckOverlap(combined, v2);
		return combined;
	}



	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined = m1;

		for (typename std::map<K, V>::const_iterator iterator = m2.begin(); iterator != m2.end(); iterator++)
		{
			combined.insert(std::make_pair(iterator->first, iterator->second));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			os << v[i];
			if (i + 1 < v.size())
			{
				os << ", ";
			}
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator iterator = m.begin(); iterator != m.end(); iterator++)
		{
			os << "{ " << iterator->first << ", " << iterator->second << " }\n";
		}
		return os;
	}
}
