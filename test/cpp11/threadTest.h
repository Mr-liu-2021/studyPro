//
// Created by Acer on 2021/06/30.
//

#ifndef STUDYPRO_THREADTEST_H
#define STUDYPRO_THREADTEST_H


#include <iostream>
#include <thread>


#include <Logger.hpp>
void fun1(){
  std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::fun1()", Logger::file_and_terminal, "../log/thread.log");
  logger->Info("fun1() start...");

  logger->Info("fun1() end...");
}

void test7() {
  std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::test7()", Logger::file_and_terminal, "../log/thread.log");

  std::thread th_1(fun1);
  th_1.join();

  logger->Info("hello world...");

}


























#endif //STUDYPRO_THREADTEST_H
