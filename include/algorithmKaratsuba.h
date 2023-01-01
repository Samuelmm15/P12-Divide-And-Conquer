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

class KaratsubaAlgorithm {
    public:
        KaratsubaAlgorithm();
        int KaratsubaOperation();
        void setFirstOperand(int firstOperand);
        void setSecondOperand(int secondOperand);
        void PrintTheSolution();
    private:
        int firstOperand_;
        int secondOperand_;
};