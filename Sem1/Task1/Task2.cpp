#include <iostream>

int main()
{
	int* mean{ new int {54} };
	delete mean;

	int* mas{ new int[7] {1, 5, 10, 15, 3, 44, 55} };

	for (int i = 0; i < 7; i++)
	{
		std::cout << *(mas + i) << '\n';
	}

	delete mas;
	delete mean;
	mas = nullptr;
	mean = nullptr;	

	return 0;
}