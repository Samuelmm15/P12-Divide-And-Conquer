/**
 * @file algorithmKaratsuba.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#pragma once

class KaratsubaAlgorithm {
 public:
  KaratsubaAlgorithm();
  long long KaratsubaOperation(long long num1, long long num2);
};