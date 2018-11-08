#include "week_1.h"

#include <algorithm>
#include <cmath>
#include <sstream>
#include <random>


void max_pairwise_product_stress_test(std::function<void(std::string)> progress_callback, std::function<unsigned long long(const std::vector<unsigned long long>&)> f1, std::function<unsigned long long(const std::vector<unsigned long long>&)> f2)
{
	std::random_device rd;
	std::mt19937 mt(rd());

	while (true)
	{
		std::stringstream ss;

		ss << "{ ";

		unsigned long long count = mt() % 200 + 2;
		unsigned long long max = mt() % 10000000 + 1;

		std::vector<unsigned long long> numbers;
		for (int i = 0; i < count; i++)
		{
			unsigned long long number = mt() % max;
			
			numbers.push_back(number);
			ss << number << ' ';
		}

		ss << " } ";

		unsigned long long p1 = f1(numbers);
		unsigned long long p2 = f2(numbers);

		ss << "p1: " << p1 << " p2: " << p2;
		
		progress_callback(ss.str());

		if (p1 != p2)
		{
			break;
		}
	}

}

unsigned long long max_pairwise_product_2n(const std::vector<unsigned long long>& numbers)
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

	unsigned long long product = *it1 * *it2;
	return product;
}

unsigned long long max_pairwise_product_n2(const std::vector<unsigned long long>& numbers)
{
	size_t count = numbers.size();

	unsigned long long product = 0;
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = i + 1; j < count; j++)
		{
			product = std::max(product, numbers[i] * numbers[j]);
		}
	}

	return product;
}