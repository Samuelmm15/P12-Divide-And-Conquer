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

std::string KaratsubaAlgorithm::KaratsubaOperation(std::string num1, std::string num2) {
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
    std::string b = num1.substr(n / 2);
    std::string c = num2.substr(0, m / 2);
    std::string d = num2.substr(m / 2);

    // Calcular los productos intermedios
    std::string ac = KaratsubaOperation(a, c);
    std::string bd = KaratsubaOperation(b, d);
    std::string abcd = KaratsubaOperation(std::to_string(std::stoi(a) + std::stoi(b)), std::to_string(std::stoi(c) + std::stoi(d)));

    // Calcular el producto final usando la fórmula de Karatsuba
    std::string result = std::to_string(pow(10, n) * std::stoi(ac) + pow(10, n / 2) * (std::stoi(abcd) - std::stoi(ac) - std::stoi(bd)) + std::stoi(bd));

    return result;
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