#include "week_1.h"

#include <algorithm>
#include <cmath>
#include <sstream>
#include <random>


void max_pairwise_product_stress_test(std::function<void(std::string)> progress_callback, std::function<unsigned int(const std::vector<unsigned int>&)> f1, std::function<unsigned int(const std::vector<unsigned int>&)> f2)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	while (true)
	{
		std::stringstream ss;

		ss << "{ ";

		unsigned int count = mt() % 2000 + 2;
		unsigned int max = mt() % 2000 + 1;

		std::vector<unsigned int> numbers;
		for (int i = 0; i < count; i++)
		{
			unsigned int number = mt() % max;
			
			numbers.push_back(number);
			ss << number << ' ';
		}

		ss << " } ";

		unsigned int p1 = f1(numbers);
		unsigned int p2 = f2(numbers);

		ss << "p1: " << p1 << " p2: " << p2;
		
		progress_callback(ss.str());

		if (p1 != p2)
		{
			break;
		}
	}

}

unsigned int max_pairwise_product_2n(const std::vector<unsigned int>& numbers)
{
	auto it1 = std::begin(numbers);
	for (auto it = std::begin(numbers); it != std::end(numbers); it++)
	{
		it1 = *it > *it1 ? it : it1;
	}

	auto it2 = std::end(numbers);
	for (auto it = std::begin(numbers); it != std::end(numbers); it++)
	{
		if (it == it1)
		{
			continue;
		}

		if (it2 == std::end(numbers) || *it > *it2)
		{
			it2 = it;
		}
	}

	unsigned int product = *it1 * *it2;
	return product;
}

unsigned int max_pairwise_product_n2(const std::vector<unsigned int>& numbers)
{
	size_t count = numbers.size();

	unsigned int product = 0;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = i + 1; j < count; j++)
		{
			product = std::max(product, numbers[i] * numbers[j]);
		}
	}

	return product;
}