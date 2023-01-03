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

KaratsubaAlgorithm::KaratsubaAlgorithm() {};

long long KaratsubaAlgorithm::KaratsubaOperation(long long num1, long long num2) {
    // Si uno de los números es cero, la multiplicación es cero
    if (num1 == 0 || num2 == 0)
        return 0;

    // Si uno de los números es de un solo dígito, se puede multiplicar de manera convencional
    if (num1 < 10 && num2 < 10)
        return num1 * num2;

    // Contar el número de dígitos de cada número
    int n = 0;
    long long temp = num1;
    while (temp > 0)
    {
        n++;
        temp /= 10;
    }

    int m = 0;
    temp = num2;
    while (temp > 0)
    {
        m++;
        temp /= 10;
    }

    // Dividir los números en dos partes
    long long a = floor(num1 / pow(10, n / 2));
    long long b = num1 - a * pow(10, n / 2);
    long long c = floor(num2 / pow(10, m / 2));
    long long d = num2 - c * pow(10, m / 2);

    // Calcular los productos intermedios de manera recursiva
    long long ac = KaratsubaOperation(a, c);
    long long bd = KaratsubaOperation(b, d);
    long long adbc = KaratsubaOperation(a + b, c + d) - ac - bd;

    // Unir todas las partes y devolver el resultado utilizando la técnica de divide y vencerás
    return ac * pow(10, n) + adbc * pow(10, n / 2) + bd;

};