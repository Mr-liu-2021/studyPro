//
// Created by Acer on 2021/05/24.
//

#ifndef STUDYPRO_LAMBDASTEST_H
#define STUDYPRO_LAMBDASTEST_H

#include <string>
#include <vector>
#include <iostream>


void test3() {
    [] {
        std::cout << "hello lambda_1!" << std::endl;
    }();

    auto Lam = []() -> int {
        std::cout << "hello lambda_2!" << std::endl;
        return 2;
    };

    int x = Lam();
    std::cout << x << std::endl;
}


void test4() {
    int id_1 = 0;
    auto Lam1 = [id_1]() mutable {
        std::cout << id_1 << std::endl;
        id_1++;
    };
    id_1 = 100;
    Lam1();//1
    Lam1();//2
    Lam1();//3
    std::cout << id_1 << std::endl;//100
    std::cout << "-----------" << std::endl;

    int id_2 = 0;
    auto Lam2 = [&id_2] {
        std::cout << id_2 << std::endl;
        id_2++;
    };
    id_2 = 100;
    Lam2();//100
    Lam2();//101
    Lam2();//102
    std::cout << id_2 << std::endl;//103
    std::cout << "-----------" << std::endl;
}

class Fun {
private:
    int m_down, m_up;
public:

    Fun(const int &down, const int &up) : m_down(down), m_up(up) {}

    bool operator()(const int &n) const {
        return n > m_down && n < m_up;
    }
};


void test5() {
    std::vector<int> v{4, 87, 65, 26, 88, 27, 15, 37, 100};
    int down = 30, up = 50;
    /*v.erase(std::remove_if(v.begin(), v.end(), Fun(down, up)), v.end());*/
    v.erase(std::remove_if(v.begin(), v.end(),
                           [down, up](int n) {
                               return n > down && n < up;
                           }), v.end());
    for (const auto &x : v) {
        std::cout << x << std::endl;
    }
}


#endif //STUDYPRO_LAMBDASTEST_H
