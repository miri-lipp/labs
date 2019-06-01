//
// Created by Miriam Lipkovich on 2019-05-13.
//

#ifndef MULTIPLICATION_MATRIX_H
#define MULTIPLICATION_MATRIX_H
#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <thread>
class multiplication{
    int row, col;
    std::vector<std::vector<int>> matrix;
public:

    friend std::ostream &operator<< (std::ostream& out, const multiplication& b);
    multiplication(int row, int col);
    multiplication(std::vector<std::vector<int>> matrix_);
    multiplication(multiplication const &a) = delete;
    multiplication(multiplication&& a) = delete;
    virtual ~multiplication();
    multiplication& operator =(const multiplication& a);
    multiplication operator *(const multiplication& a);
    multiplication multiply(multiplication& a);
};

#endif //MULTIPLICATION_MATRIX_H
