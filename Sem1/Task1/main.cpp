#include <iostream>
#include "Header1.h"
#include "Header2.h"

int main()
{
	int a, b;
	
	std::cin >> a >> b;

	std::cout << "Result without random: " << func1::func_average<int, double>(a, b) << '\n';
	std::cout << "Result with random: " << func2::func_average<int, double>(a, b) << '\n';

	return 0;
}	