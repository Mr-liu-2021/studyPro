//
// Created by Acer on 2021/04/07.
//

#ifndef STUDYPRO_BINDTEST_H
#define STUDYPRO_BINDTEST_H

#include <iostream>
#include <functional>
using namespace std::placeholders;


double myDiv(const double &x, const double &y) {
    return x / y;
}

struct MyPair {
    double a, b;

    double multiply() const {
        return a * b;
    }
};


int testBind() {

    auto fn_five = std::bind(myDiv, 10, 2);
    std::cout<<fn_five()<<std::endl;



    return 0;
}








#endif //STUDYPRO_BINDTEST_H
