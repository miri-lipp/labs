//
// Created by Miriam Lipkovich on 3/4/19.
//
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#ifndef BVYF_MATRIX_H
#define BVYF_MATRIX_H
int Menu();
void Display();

class Matrix {
    int **array;
    int size1;
    int size2;

public:
    friend std::ostream &operator<< (std::ostream& out, const Matrix &b);
    Matrix(int size1, int size2) : size1(size1), size2(size2){
        array = new int *[size1];
        this->size1 = size1;
        for (int i = 0; i < size1; i++) {
            array[i] = new int[size2];
        }
        this->size2 = size2;
        srand(time(nullptr));
        for(int i = 0; i < size1; i++){
            for(int j = 0; j < size2; j++)
                array[i][j] = rand()%100;
        }
    }

    Matrix(Matrix const &a) {
        size1 = a.size1;
        size2 = a.size2;
        array = new int *[a.size1];
        for (int i = 0; i < a.size1; i++) {
            array[i] = new int[a.size2];
        }
    }

    Matrix(Matrix &&a) {
        array = a.array;
        size1 = a.size1;
        size2 = a.size2;
        a.array = nullptr;
    }

    ~Matrix() {
        for (int i = 0; i < size1; i++) {
            delete[] array[i];
        }
        delete[] array;
    }

    Matrix operator= (const Matrix &b){
        if (this == &b)
            return *this;
        for(int i = 0; i < size1; i++){
                delete array[i];
        }
        delete[] array;

        size1 = b.size1;
        size2 = b.size2;
        array = new int *[size1];
        for(int i = 0; i < size1; i++){
            array[i] = new int [size2];
        }
        for(int i = 0; i < size1; i++){
            for (int j = 0; j < size2; j++)
                array[i][j] = b.array[i][j];
        }
        return *this;
    }

    Matrix operator+ (const Matrix &b){
        if ((size1 != b.size1) || (size2 != b.size2)) {
            throw std::logic_error("Error");
        }
        Matrix app(size1, b.size2);
        for (int i = 0; i < size1; i++){
            for (int j = 0; j < size2; j++){
                app.array[i][j] = array[i][j] + b.array[i][j];
            }
        }
        return app;
    }

    Matrix operator- (const Matrix &b){
        if ((size1 != b.size1) || (size2 != b.size2)) {
            throw std::logic_error("Error");
        }
        Matrix app(size1, b.size2);
        for (int i = 0; i < size1; i++){
            for (int j = 0; j < size2; j++){
                app.array[i][j] = array[i][j] - b.array[i][j];
            }
        }
        return app;
    }

    Matrix operator* (const Matrix &b){
        if (size2 != b.size1){
            throw std::logic_error("Error");
        }
        Matrix app(size1, b.size2);
        for (int i = 0; i < size1; i++){
            for (int k = 0; k < b.size1; k++) {
                for (int j = 0; j < size2; j++) {
                    app.array[i][k] = 0;
                    app.array[i][k] += array[i][j] * b.array[j][k];
                }
            }
        }
        return app;
    }

    Matrix operator*(double n){
        for (int i = 0; i < size1; i++){
            for (int j = 0; j < size2; j++){
                array[i][j] *= n;
            }
        }
        return *this;
    }
};
#endif //BVYF_MATRIX_H
