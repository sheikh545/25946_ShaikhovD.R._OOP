#include <iostream>
#include <array>
#include <random>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <fstream>

#include "task2_containers.h"
#include "task2_mod_func.h"

#define M 14




int main()
{
	int N = 2;
	using T1 = double;
	using T2 = int;

	std::array<T1, M> arr_cont{};
	std::vector<T1> vec_cont(M);
	std::list<T1> list_cont(M);
	std::deque<T1> deq_cont(M);

	containers<T1>(arr_cont, N);
	containers<T1>(vec_cont, N);
	containers<T1>(list_cont, N);
	containers<T1>(deq_cont, N);
	
	std::array<T2, M> arr_cont_new{};
	std::vector<T2> vec_cont_new;
	std::list<T2> list_cont_new;
	std::deque<T2> deq_cont_new;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<T1> gen_rand_num(-N, N);
	const T1 second_arg = gen_rand_num(gen);

	// classic for
	for (int i = 0; i < M; i++)
	{
		T2 value = func2::func_average<T1, T2>(arr_cont[i], second_arg);
		deq_cont_new.push_back(value);
	}

	int i = 0;	
	// for with iter
	for (std::list<T1>::iterator iter = list_cont.begin(); iter != list_cont.end(); ++iter)
	{
		T2 value = func2::func_average<T1, T2>(*iter, second_arg);
		arr_cont_new[i++] = value;
	}

	for (std::vector<T1>::iterator iter = vec_cont.begin(); iter != vec_cont.end(); ++iter)
	{
		T2 value = func2::func_average<T1, T2>(*iter, second_arg);
		list_cont_new.push_back(value);
	}

	// range-based for
	for (const T1& element : deq_cont)
	{
		T2 value = func2::func_average<T1, T2>(element, second_arg);
		vec_cont_new.push_back(value);
	}
	
	std::array<std::string, M + 1> table{};
	table[0] = "Index|array|vector|list|deque|new_array|new_vector|new_list|new_deque";

	std::list<T1>::iterator iter1 = list_cont.begin();
	std::list<T2>::iterator iter2 = list_cont_new.begin();

	for (int i = 0; i < M; i++)
	{
		table[i + 1] = std::to_string(i) + "|" + std::to_string(arr_cont[i]) + "|" + std::to_string(vec_cont[i]) + "|" +
			std::to_string(*iter1) + "|" + std::to_string(deq_cont[i]) + "|" + std::to_string(arr_cont_new[i]) + "|" +
			std::to_string(vec_cont_new[i]) + "|" + std::to_string(*iter2) + "|" + std::to_string(deq_cont_new[i]);
		

		++iter1;
		++iter2;

	}


	std::ofstream file("D:/C++/Sem1/Task2/Table.md");

	file << "|" << table[0] << "|\n";
	file << "|---|---|---|---|---|---|---|---|---|\n";

	for (int i = 1; i <= M; i++)
	{
		file << "|" << table[i] << "|\n";
	}

	file.close();

	return 0;
}