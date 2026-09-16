#include "Header1.h"

namespace func1
{
	template <typename T>
	T func_average(const T& a, const T& b)
	{
		return (a + b) / 2;
	}

	// явное инстанцированние шаблона
	template int func_average<int>(const int& a, const int& b);
	template double func_average<double>(const double& a, const double& b);
}
	