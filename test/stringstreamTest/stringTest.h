//
// Created by Acer on 2021/04/15.
//

#ifndef STUDYPRO_STRINGTEST_H
#define STUDYPRO_STRINGTEST_H

#include <string>
#include <iostream>
#include <sstream>

int testString() {
    std::string str = "Hello";
    std::cout << str << std::endl;
    str.resize(3);
    std::cout << str << std::endl;

    return 0;
}


int testStringStream() {
    std::stringstream ss;
    ss << "Hello" << std::endl;
    ss << "World";

    std::cout << ss.str() << std::endl;
    ss << "hhhh" << std::endl;
    std::cout << ss.str() << std::endl;
    return 0;
}

int test0() {
    std::stringstream  ss;
    std::string str1;
    std::string str2;
    int a = 100;
    ss << a;
    ss << "hello world";
    ss >> str1;
    ss >> str2;

    std::cout<<str1<<std::endl;
    std::cout<<str2<<std::endl;


    std::cout<<ss.str()<<std::endl;


    std::vector<std::vector<std::string>> v{{"N13728_C"}, {"N13730_1", "N13734_A", "N13734_B", "N13731_F", "N13735_2", "N13735_3"}, {"N13728_F"}, {"N14C1F_C"}};
    for(auto x : v){
        for(auto item : x) {
            std::cout<<item<<std::endl;
        }
        std::cout<<"----------------"<<std::endl;
    }

    return 0;
}

#endif //STUDYPRO_STRINGTEST_H
