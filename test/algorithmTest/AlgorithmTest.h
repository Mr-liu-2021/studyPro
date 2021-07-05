//
// Created by Acer on 2021/04/02.
//

#ifndef STUDYPRO_ALGORITHMTEST_H
#define STUDYPRO_ALGORITHMTEST_H

#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>


int accFun(const int &x, const int &y) {
    return x + 2 * y;
}

class accClass {
public:
    int operator()(const int &x, const int &y) {
        return x + 3 * y;
    }
};


int testAccumulateForArray() {
    std::cout << "array..." << std::endl;
    int testArr[] = {10, 20, 30};
    int init = 100;

    std::cout << std::accumulate(testArr, testArr + 3, init) << std::endl; //160
    std::cout << std::accumulate(testArr, testArr + 3, init, accFun) << std::endl; //220
    std::cout << std::accumulate(testArr, testArr + 3, init, accClass()) << std::endl; //280

    return 0;
}

int testAccumulateForVector() {
    std::cout << "vector..." << std::endl;
    std::vector<int> vec = {10, 20, 30};
    int init = 100;

    std::cout << std::accumulate(vec.begin(), vec.end(), init) << std::endl; //160
    std::cout << std::accumulate(vec.begin(), vec.end(), init, accFun) << std::endl; //220
    std::cout << std::accumulate(vec.begin(), vec.end(), init, accClass()) << std::endl; //280

    return 0;
}


int forFun(int &x) {
    if (x % 2 != 0) {
        x += 100;
    }
    return 0;
}

struct forStruct {
    int operator()(int &x) {
        if (x % 2 != 0) {
            x += 100;
        }
        return 0;
    }
};


int testForeach() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (const auto &x : vec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
//    std::for_each(vec.begin(), vec.end(), forFun);
//    std::for_each(vec.begin(), vec.end(), forStruct());
    for (const auto &x : vec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    return 0;
}


int testSort() {
    std::vector<int> vec = {13, 2, 1, 14, 5};
    for (const auto &x : vec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    std::sort(vec.begin()+3, vec.end());
    for (const auto &x : vec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());
    for (const auto &x : vec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    std::sort(vec.rbegin(), vec.rend());
    for (const auto &x : vec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;

    return 0;
}


int testAlgorithmAll() {
//    testAccumulateForArray();
//    testAccumulateForVector();

//    testForeach();

    testSort();





    return 0;
}


#endif //STUDYPRO_ALGORITHMTEST_H
