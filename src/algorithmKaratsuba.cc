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

/*
EJEMPLO DE CÓDIGO DE KARATSUBA
int n = num1.size();
    int m = num2.size();

    // Si uno de los números es cero, la multiplicación es cero
    if (n == 0 || m == 0)
        return "0";

    // Si uno de los números es de un solo dígito, se puede multiplicar de manera convencional
    if (n == 1 && m == 1)
        return std::to_string((num1[0] - '0') * (num2[0] - '0'));

    // Ajustar el tamaño de los números para que tengan la misma longitud
    if (n > m) {
        num2.insert(0, n - m, '0');
    } else {
        num1.insert(0, m - n, '0');
    }

    n = num1.size();
    m = num2.size();

    // Dividir los números en dos partes
    std::string a = num1.substr(0, n / 2);
    std::string b = num1.substr(n/2, n - n/2);
    std::string c = num2.substr(0, m / 2);
    std::string d = num2.substr(m/2, m - m/2);

    // Calcular los productos intermedios
    std::string ac = KaratsubaOperation(a, c);
    std::string bd = KaratsubaOperation(b, d);
    std::string abcd = KaratsubaOperation(std::to_string(std::stoi(a) + std::stoi(b)), std::to_string(std::stoi(c) + std::stoi(d)));

    // Calcular el producto final usando la fórmula de Karatsuba
    std::string result = std::to_string(pow(10, n) * std::stoi(ac) + pow(10, n / 2) * (std::stoi(abcd) - std::stoi(ac) - std::stoi(bd)) + std::stoi(bd));

    return result;
*/

/*
OTRO EJEMPLO DE CÓDIGO DE KARATSUBA
// Si uno de los números es cero, la multiplicación es cero
    if (num1 == 0 || num2 == 0)
        return 0;

    // Si uno de los números es de un solo dígito, se puede multiplicar de manera convencional
    if (num1 < 10 && num2 < 10)
        return num1 * num2;

    // Contar el número de dígitos de cada número
    int n = 0;
    int temp = num1;
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
    int a = num1 / pow(10, n / 2);
    int b = num1 % (int)pow(10, n / 2);
    int c = num2 / pow(10, m / 2);
    int d = num2 % (int)pow(10, m / 2);

    // Calcular los productos intermedios de manera recursiva
    int ac = KaratsubaOperation(a, c);
    int bd = KaratsubaOperation(b, d);
    int adbc = KaratsubaOperation(a + b, c + d) - ac - bd;

    // Unir todas las partes y devolver el resultado utilizando la técnica de divide y vencerás
    return ac * pow(10, n) + adbc * pow(10, n / 2) + bd;
*/