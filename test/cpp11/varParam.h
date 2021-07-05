//
// Created by Acer on 2021/04/16.
//
#ifndef STUDYPRO_VARPARAM_H
#define STUDYPRO_VARPARAM_H


#include <iostream>
#include <string>

int print() {
    return 0;
}

template<typename T, typename... Types>
int print(const T &firstArg, const Types &... otherArgs) {
    std::cout << firstArg << std::endl;
    print(otherArgs...);
    return 0;
}


int testVarParam() {
    print("hello", 123, 0.25, 'a');
    return 0;
}




#endif //STUDYPRO_VARPARAM_H

