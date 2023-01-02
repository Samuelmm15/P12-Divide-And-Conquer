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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

class KaratsubaAlgorithm {
    public:
        KaratsubaAlgorithm();
        std::string KaratsubaOperation(std::string num1, std::string num2);
        void setFirstOperand(int firstOperand);
        void setSecondOperand(int secondOperand);
        void PrintTheSolution();
    private:
        int firstOperand_;
        int secondOperand_;
        int result_;
};