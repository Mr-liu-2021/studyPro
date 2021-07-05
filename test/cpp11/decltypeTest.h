//
// Created by Acer on 2021/05/24.
//

#ifndef STUDYPRO_DECLTYPETEST_H
#define STUDYPRO_DECLTYPETEST_H

#include <map>
#include <string>
#include <iostream>

void test2() {
    std::map<std::string, int> m;
    typedef decltype(m) Mydef;
    using Mydefed = decltype(m);
    Mydef::key_type key;
    Mydefed::mapped_type value;
    key = "name";
    value = 10;

    std::cout<<key<<" -> "<<value<<std::endl;

}


#endif //STUDYPRO_DECLTYPETEST_H
