//
// Created by 朱俊驰 on 9/3/24.
//

#ifndef LEECODE_HELPER_H
#define LEECODE_HELPER_H

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
template <typename T>

void vector_printer(const std::vector<T>& my_vector) {
    for(const auto& ele : my_vector) {
        std::cout << ele << ", ";
    }
    std::cout << std::endl;
}


template <typename T>
void matrix_printer(const std::vector<std::vector<T>>& my_matrix) {
    for (const auto& row : my_matrix) {
        for (const auto& ele : row) {
            std::cout << ele << " ";
        }
        std::cout << std::endl;
    }
}
#endif //LEECODE_HELPER_H
