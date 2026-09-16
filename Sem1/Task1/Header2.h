#include "iostream"
#include <random>

namespace func2
{
	template <typename T>
	T func_average(const T& a, const T& b)
	{
		T aver_sum = (a + b) / 2;

		std::random_device rd;
		std::mt19937 generator(rd()); // rd() = seed
		// generator - источник случайности для распределения

		std::uniform_int_distribution<int> chance(0, 1);
		std::uniform_int_distribution<int> random_number(1, 100);

		if (chance(generator)) return aver_sum + random_number(generator);
		else return aver_sum;
	}

}
