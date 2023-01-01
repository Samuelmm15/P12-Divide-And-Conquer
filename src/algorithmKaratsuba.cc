/**
 * @file algorithmKaratsuba.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2023-01-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/algorithmKaratsuba.h"

KaratsubaAlgorithm::KaratsubaAlgorithm() {
    firstOperand_ = 0;
    secondOperand_ = 0;
};

int KaratsubaAlgorithm::KaratsubaOperation() {
    return 0;
};

void KaratsubaAlgorithm::setFirstOperand(int firstOperand) {
    firstOperand_ = firstOperand;
};

void KaratsubaAlgorithm::setSecondOperand(int secondOperand) {
    secondOperand_ = secondOperand;
};

void KaratsubaAlgorithm::PrintTheSolution() {
    std::cout << "El resultado de la operación es: " << KaratsubaOperation() << std::endl;
};