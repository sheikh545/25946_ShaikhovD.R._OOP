#include <iostream>
#include <memory>

int main()
{
	int size_mas = 5;
	int* mas{ new int[size_mas] };

	int* number = new int(17);
	std::cout << "Before delete: " << *number << '\n';
	delete number;
	// number = nullptr;
	std::cout << "After delete: " << *number << '\n';

	std::unique_ptr<int> new_number = std::make_unique<int>(17);
	std::cout << "New_number: " << *new_number << '\n';

	for (int i = 0; i < size_mas; i++)
	{
		std::cin >> mas[i];
	}

	std::cout << "mas before adding: ";
	for (int i = 0; i < size_mas; i++)
	{
		std::cout << mas[i] << " ";
	}

	int* new_mas = new int[++size_mas];

	for (int i = 0; i < size_mas; i++)
	{
		if (i == 2)
		{
			new_mas[i] = 55;
		}
		else if (i < 2)
		{
			new_mas[i] = mas[i];
		}
		else
		{
			new_mas[i] = mas[i - 1];
		}
	}

	delete[] mas;
	mas = new_mas;
	new_mas = nullptr;

	std::cout << '\n' << "mas after adding: ";
	for (int i = 0; i < size_mas; i++)
	{
		std::cout << mas[i] << " ";
	}

	delete[] mas;
	mas = nullptr;

	return 0;
}