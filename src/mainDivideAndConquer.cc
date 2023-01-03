/**
 * @file mainDivideAndConquer.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This is the main file of the program.
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "../include/algorithmKaratsuba.h"
#include "../include/bigIntClass.h"

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    std::string option = argv[1];
    if (option == "-h" || option == "--help") {
      std::cout << std::endl;
      std::cout << " <<< Bienvenido a la ayuda del programa >>> " << std::endl;
      std::cout << "Ayuda: ./mainDivideAndConquer [Nº Entero Grande Nº Entero "
                   "Grande | -k [Nº Entero Grande Nº Entero Grande] | -m [Nº "
                   "Entero Grande Nº Entero Grande]]"
                << std::endl;
      std::cout << "La opción -k permite ejecutar el algoritmo de Karatsuba."
                << std::endl;
      std::cout << "La opción -m permite ejecutar la sobrecarga del operador * "
                   "de la clase BigInt."
                << std::endl;
      std::cout << std::endl;
    }
  } else if (argc == 3) {
    /// Determinación de las distintas opciones con las que se puede ejecutar el
    /// algoritmo.
    std::string number1 = argv[1];
    std::string number2 = argv[2];
    std::cout << std::endl;
    std::cout << "El primer operador es: " << number1 << std::endl;
    std::cout << "El segundo operador es: " << number2 << std::endl;
    KaratsubaAlgorithm KaratsubaExample;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "La solución de la operación es: "
              << KaratsubaExample.KaratsubaOperation(std::stoi(number1),
                                                     std::stoi(number2))
              << std::endl;
    /// tiempo de ejecución del algoritmo de Karatsuba.
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "Tiempo de ejecución del algoritmo de Karatsuba: " << duration << " segundos" << std::endl;
    std::cout << std::endl;
  } else if (argc == 4) {
    std::string option = argv[1];
    std::string number1 = argv[2];
    std::string number2 = argv[3];
    if (option == "-k") {
      /// Comienzo del programa con el algoritmo Karatsuba.
      std::cout << std::endl;
      std::cout << "El primer operador es: " << number1 << std::endl;
      std::cout << "El segundo operador es: " << number2 << std::endl;
      KaratsubaAlgorithm KaratsubaExample;
      auto start = std::chrono::high_resolution_clock::now();;
      std::cout << "La solución de la operación es: "
                << KaratsubaExample.KaratsubaOperation(std::stoi(number1),
                                                       std::stoi(number2))
                << std::endl;
        /// tiempo de ejecución del algoritmo de Karatsuba.
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
        std::cout << "Tiempo de ejecución del algoritmo de Karatsuba: " << duration << " segundos" << std::endl;
        std::cout << std::endl;
    } else if (option == "-m") {
      /// Comienzo del programa con la sobrecarga del operador * de la clase
      /// BigInt.
        std::cout << std::endl;
        std::cout << "El primer operador es: " << number1 << std::endl;
        std::cout << "El segundo operador es: " << number2 << std::endl;
        BigInt number1BigInt(number1);
        BigInt number2BigInt(number2);
        BigInt result;
        auto start = std::chrono::high_resolution_clock::now();
        result = number1BigInt * number2BigInt;
        std::cout << "El resultado de la operación es: " << result << std::endl;
        /// tiempo de ejecución del algoritmo de la clase BigInt.
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
        std::cout << "Tiempo de ejecución del algoritmo de la clase BigInt: " << duration << " segundos" << std::endl;
        std::cout << std::endl;
    } else {
      std::cout << std::endl;
      std::cout << "ERROR >>> La opción introducida no es correcta."
                << std::endl;
      std::cout << "Para más información sobre la ejecución del programa, haga "
                   "uso de la opción -h o --help."
                << std::endl;
      std::cout << "Ejemplo: ./mainDivideAndConquer [-h | --help]" << std::endl;
      std::cout << std::endl;
    }
  } else {
    std::cout << std::endl;
    std::cout << "ERROR >>> El número de argumentos es incorrecto."
              << std::endl;
    std::cout << "Para más información sobre la ejecución del programa, haga "
                 "uso de la opción -h o --help."
              << std::endl;
    std::cout << "Ejemplo: ./mainDivideAndConquer [-h | --help]" << std::endl;
    std::cout << std::endl;
  }
};