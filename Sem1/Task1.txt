#include <iostream>
#include "Header1.h"
#include "Header2.h"

int main()
{
	int a, b;
	// double c, d;
	std::cin >> a >> b;
	// std::cin >> c >> d;

	std::cout << "Result without random: " << func1::func_average<int>(a, b) << '\n';
	std::cout << "Result with random: " << func2::func_average<int>(a, b) << '\n';

	return 0;
}