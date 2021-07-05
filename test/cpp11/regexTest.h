//
// Created by Acer on 2021/05/06.
//

#ifndef STUDYPRO_REGEXTEST_H
#define STUDYPRO_REGEXTEST_H

#include <regex>
#include <string>
#include <iostream>

void test1() {
    std::regex r("^1\\d{9}0$");
    std::string str = "12345678900";
    bool flag = std::regex_match(str, r);


    if(flag) {
        std::cout<<"yes..."<<std::endl;
    } else{
        std::cout<<"no..."<<std::endl;
    }

}




#endif //STUDYPRO_REGEXTEST_H
