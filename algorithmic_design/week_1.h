#pragma once

#include <functional>
#include <string>
#include <vector>

void max_pairwise_product_stress_test(std::function<void(std::string)> progress_callback, std::function<unsigned int(const std::vector<unsigned int>&)> f1, std::function<unsigned int(const std::vector<unsigned int>&)> f2);

unsigned int max_pairwise_product_2n(const std::vector<unsigned int>& numbers);
unsigned int max_pairwise_product_n2(const std::vector<unsigned int>& numbers);

