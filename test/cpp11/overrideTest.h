//
// Created by Acer on 2021/04/27.
//

#ifndef STUDYPRO_OVERRIDETEST_H
#define STUDYPRO_OVERRIDETEST_H

#include <iostream>

class Base {
public:
    virtual void test(const float &v) {
        std::cout << "Base test();" << std::endl;
    }
};


class Foo : public Base {
public:
    void test(const float &v) {
        std::cout << "Foo test();" << std::endl;
    }
};


#endif //STUDYPRO_OVERRIDETEST_H
