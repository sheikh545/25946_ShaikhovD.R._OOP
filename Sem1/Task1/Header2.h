#include "iostream"
#include <random>

namespace func2
{
	template <typename T1, typename T2>
	T2 func_average(const T1& a, const T1& b)
	{
		T2 aver_sum = (a + b) / 2.0;

		std::random_device rd;
		std::mt19937 generator(rd()); // rd() = seed
		// generator - источник случайности для распределения

		std::uniform_int_distribution<int> chance(0, 1);
		std::uniform_int_distribution<int> random_number(1, 100);

		if (chance(generator)) return aver_sum + random_number(generator);
		else return aver_sum;
	}

}
