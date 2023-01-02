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
#include <vector>
#include <string>

#include "../include/algorithmKaratsuba.h"

int main(int argc, char const *argv[]) {
    if (argc == 2) {
        std::string option = argv[1];
        if (option == "-h" || option == "--help") {
            std::cout << std::endl;
            std::cout << " <<< Bienvenido a la ayuda del programa >>> " << std::endl;
            std::cout << "Ayuda: ./mainDivideAndConquer [Nº Entero Grande | -k [Nº Entero Grande] | -m [Nº Entero Grande]]" << std::endl;
            std::cout << "La opción -k permite ejecutar el algoritmo de Karatsuba." << std::endl;
            std::cout << "La opción -m permite ejecutar la sobrecarga del operador * de la clase BigInt." << std::endl;
            std::cout << std::endl;
        } else {
            /// Compienzo del programa con el algoritmo Karatsuba por defecto.
            std::string number = argv[1];
            std::cout << "El primer número es: " << number << std::endl;
            std::string number2 = "87654321";
            std::cout << "El segundo número es: " << number2 << std::endl;
            KaratsubaAlgorithm KaratsubaExample;
            std::cout << "La solución de la operación es: " << KaratsubaExample.KaratsubaOperation(number, number2) << std::endl;
        }
    } else if (argc == 3) {
        /// Determinación de las distintas opciones con las que se puede ejecutar el algoritmo.
        std::string option = argv[1];
        std::string number = argv[2];
        if (option == "-k") {
            /// Comienzo del programa con el algoritmo Karatsuba.
        } else if (option == "-m") {
            /// Comienzo del programa con la sobrecarga del operador * de la clase BigInt.
        } else {
            std::cout << std::endl;
            std::cout << "ERROR >>> La opción introducida no es correcta." << std::endl;
            std::cout << "Para más información sobre la ejecución del programa, haga uso de la opción -h o --help." << std::endl;
            std::cout << "Ejemplo: ./mainDivideAndConquer [-h | --help]" << std::endl;
            std::cout << std::endl;
        }
    } else {
        std::cout << std::endl;
        std::cout << "ERROR >>> El número de argumentos es incorrecto." << std::endl;
        std::cout << "Para más información sobre la ejecución del programa, haga uso de la opción -h o --help." << std::endl;
        std::cout << "Ejemplo: ./mainDivideAndConquer [-h | --help]" << std::endl;
        std::cout << std::endl;
    }
};