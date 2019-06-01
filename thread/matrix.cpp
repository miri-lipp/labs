//
// Created by Miriam Lipkovich on 2019-05-13.
//

#include "matrix.h"
#include "catch.h"

std::ostream& operator<<(std::ostream &out, const multiplication &b) {
    throw std::logic_error("not implemented");
}

multiplication::multiplication(int row_, int col_) {
    row = row_;
    col = col_;
    matrix = std::vector<std::vector<int>>(row, std::vector<int>(col, 0));
}

multiplication& multiplication::operator=(const multiplication& a) {
    if(this == &a)
        return *this;
    matrix = a.matrix;
}

multiplication multiplication::operator*(const multiplication &a) {
    if (col != a.row)
        throw std::logic_error("error.");
    std::vector<std::vector<int>> result(row, std::vector<int>(a.col, 0));
    for(auto i = 0; i < row; i++)
        for(auto j = 0; j < a.col; j++)
            for(auto k = 0; k < col; k++)
                result[i][j] += matrix[i][k] * a.matrix[i][j];

    return multiplication(result);
}

multiplication multiplication::multiply(multiplication& a) {
    if(col != a.row)
        throw std::logic_error("error.");
    std::vector<std::vector<int>> result(row, std::vector<int>(col, 0));
    auto thread_num = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    threads.reserve(thread_num);
    int elements = a.col * row;
    int elements_for_each = elements/thread_num;
    int left_elements = elements % thread_num;
    for(int i = 0, j = 0; i < row;){
        if(left_elements != 0){
            elements_for_each++;
            left_elements--;
        }
        threads.emplace_back(std::thread([&a, &result, i, j, elements_for_each, this]{
            int k = j, n = elements_for_each;
            for(int m = i; n != 0; m++){
                for(; n != 0 && k < a.col; k++){
                    for(int f = 0; f < col; f++)
                        result[m][k] += matrix[m][f] * a.matrix[f][k];
                    n--;
                }
                k = 0;
            }
        }));
        i += (j + elements_for_each)/a.col;
        j = (j + elements_for_each) % a.col;
    }

    for(auto &i : threads)
        i.join();
    return multiplication(result);
}

multiplication::multiplication(std::vector<std::vector<int>> matrix_){
    matrix = matrix_;
    row = matrix_.size();
    col = matrix_[0].size();
}

multiplication::~multiplication() {

}