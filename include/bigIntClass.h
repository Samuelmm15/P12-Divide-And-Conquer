/**
 * @file bigIntClass.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2023-01-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#pragma once

class BigInt{
    std::string digits;
public:
 
    //Constructors:
    BigInt(unsigned long long n = 0);
    BigInt(std::string &);
    BigInt(const char *);
    BigInt(BigInt &);
 
    //Helper Functions:
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    int operator[](const int)const;

    //Multiplication and Division
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
 
    //Read and Write
    friend std::ostream &operator<<(std::ostream &,const BigInt &);
    friend std::istream &operator>>(std::istream &, BigInt &);
};