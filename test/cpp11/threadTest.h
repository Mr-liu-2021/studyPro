//
// Created by Acer on 2021/06/30.
//

#ifndef STUDYPRO_THREADTEST_H
#define STUDYPRO_THREADTEST_H


#include <iostream>
#include <thread>


#include <Logger.hpp>
void fun1(){
  std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::fun1()");
  logger->Info("fun1() start...");

  logger->Info("fun1() end...");
}

void test7() {
  std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::test7()");

  std::thread th_1(fun1);
  th_1.detach();

  logger->Info("hello world...");
  logger->Info("xxx");

}


























#endif //STUDYPRO_THREADTEST_H
