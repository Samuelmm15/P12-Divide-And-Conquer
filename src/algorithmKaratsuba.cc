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

int KaratsubaAlgorithm::KaratsubaOperation(int *a, int *b, int *result, int n) {
    if (n == 1)
    {
        result[0] = a[0] * b[0];
        return;
    }

    int n2 = n / 2;
    int n1 = n - n2;

    int *a1 = new int[n1];
    int *a2 = new int[n2];
    int *b1 = new int[n1];
    int *b2 = new int[n2];
    int *c0 = new int[n];
    int *c1 = new int[n];
    int *c2 = new int[n];

    for (int i = 0; i < n1; i++)
        a1[i] = a[i];
    for (int i = 0; i < n2; i++)
        a2[i] = a[i + n1];
    for (int i = 0; i < n1; i++)
        b1[i] = b[i];
    for (int i = 0; i < n2; i++)
        b2[i] = b[i + n1];

    KaratsubaOperation(a1, b1, c1, n1);
    KaratsubaOperation(a2, b2, c2, n2);

    for (int i = 0; i < n1; i++)
        a1[i] += a2[i];
    for (int i = 0; i < n1; i++)
        b1[i] += b2[i];
    KaratsubaOperation(a1, b1, c0, n1);

    for (int i = 0; i < n; i++)
        c0[i] -= c1[i];
    for (int i = 0; i < n; i++)
        c0[i] -= c2[i];

    for (int i = 0; i < n2; i++)
        result[i] = c2[i];
    for (int i = 0; i < n1; i++)
        result[i + n2] += c1[i];
    for (int i = 0; i < n1; i++)
        result[i + n1] += c0[i];

    result_ = result[0];

    delete[] a1;
    delete[] a2;
    delete[] b1;
    delete[] b2;
    delete[] c0;
    delete[] c1;
    delete[] c2;
};

void KaratsubaAlgorithm::setFirstOperand(int firstOperand) {
    firstOperand_ = firstOperand;
};

void KaratsubaAlgorithm::setSecondOperand(int secondOperand) {
    secondOperand_ = secondOperand;
};

void KaratsubaAlgorithm::PrintTheSolution() {
    std::cout << std::endl;
    std::cout << "La solución es: " << firstOperand_ * secondOperand_ << std::endl;
    std::cout << "El resultado es: " << result_ << std::endl;
};