#include <iostream>

#include "week_1.h"

void progress(std::string message)
{
	std::cout << message << '\n';
}

int main()
{
	max_pairwise_product_stress_test(progress, max_pairwise_product_2n, max_pairwise_product_n2);

	return 0;
}