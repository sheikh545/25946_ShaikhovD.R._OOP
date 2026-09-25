#include <random>

template <typename T1, typename Container>
void containers(Container& cont, const int N)
{
	std::random_device rd;
	std::mt19937 generator(rd());

	std::uniform_real_distribution<T1> random_numbers(-N, N);

	for (T1& element : cont)
	{
		element = random_numbers(generator);
	}
}