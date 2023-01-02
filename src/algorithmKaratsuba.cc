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
    /// Código tomado como ejemplo, haciendo uso de números enteros, pero se puede hacer uso de cadenas como se puede ver a continuación
    // if (n == 1)
    // {
    //     result[0] = a[0] * b[0];
    //     return;
    // }

    // int n2 = n / 2;
    // int n1 = n - n2;

    // int *a1 = new int[n1];
    // int *a2 = new int[n2];
    // int *b1 = new int[n1];
    // int *b2 = new int[n2];
    // int *c0 = new int[n];
    // int *c1 = new int[n];
    // int *c2 = new int[n];

    // for (int i = 0; i < n1; i++)
    //     a1[i] = a[i];
    // for (int i = 0; i < n2; i++)
    //     a2[i] = a[i + n1];
    // for (int i = 0; i < n1; i++)
    //     b1[i] = b[i];
    // for (int i = 0; i < n2; i++)
    //     b2[i] = b[i + n1];

    // KaratsubaOperation(a1, b1, c1, n1);
    // KaratsubaOperation(a2, b2, c2, n2);

    // for (int i = 0; i < n1; i++)
    //     a1[i] += a2[i];
    // for (int i = 0; i < n1; i++)
    //     b1[i] += b2[i];
    // KaratsubaOperation(a1, b1, c0, n1);

    // for (int i = 0; i < n; i++)
    //     c0[i] -= c1[i];
    // for (int i = 0; i < n; i++)
    //     c0[i] -= c2[i];

    // for (int i = 0; i < n2; i++)
    //     result[i] = c2[i];
    // for (int i = 0; i < n1; i++)
    //     result[i + n2] += c1[i];
    // for (int i = 0; i < n1; i++)
    //     result[i + n1] += c0[i];

    // result_ = result[0];

    // delete[] a1;
    // delete[] a2;
    // delete[] b1;
    // delete[] b2;
    // delete[] c0;
    // delete[] c1;
    // delete[] c2;
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
    std::string a = num1.substr(0, n/2);
    std::string b = num1.substr(n/2, n - n/2);
    std::string c = num2.substr(0, m/2);
    std::string d = num2.substr(m/2, m - m/2);

    // Calcular los productos intermedios
    std::string ac = KaratsubaOperation(a, c);
    std::string bd = KaratsubaOperation(b, d);
    std::string abcd = KaratsubaOperation(std::to_string(std::stoi(a) + std::stoi(b)), std::to_string(std::stoi(c) + std::stoi(d)));
    std::string adbc = std::to_string(std::stoi(abcd) - std::stoi(ac) - std::stoi(bd));

    // Llenar con ceros para que tenga la misma longitud que los números originales
    while (ac.size() < n)
        ac.push_back('0');
    while (adbc.size() < n/2)
        adbc.push_back('0');

    // Unir todas las partes y devolver el resultado
    return std::to_string(stoi(ac) + stoi(adbc) + stoi(bd));
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