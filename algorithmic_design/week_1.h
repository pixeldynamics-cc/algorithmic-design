#pragma once

#include <functional>
#include <string>
#include <vector>

void max_pairwise_product_stress_test(std::function<void(std::string)> progress_callback, std::function<unsigned long long(const std::vector<unsigned long long>&)> f1, std::function<unsigned long long(const std::vector<unsigned long long>&)> f2);

unsigned long long max_pairwise_product_2n(const std::vector<unsigned long long>& numbers);
unsigned long long max_pairwise_product_n2(const std::vector<unsigned long long>& numbers);

