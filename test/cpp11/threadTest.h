//
// Created by Acer on 2021/06/30.
//

#ifndef STUDYPRO_THREADTEST_H
#define STUDYPRO_THREADTEST_H


#include <iostream>
#include <thread>


#include <Logger.hpp>

void fun1() {
  std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::fun1()", Logger::file_and_terminal,
                                                            "../log/thread.log");
  logger->Info("fun1() start...");

  logger->Info("fun1() end...");
}

void fun2(const int i, const std::string &str) {
  std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::fun2()", Logger::file_and_terminal,
                                                            "../log/thread.log");
  logger->Debug("i = ", i, ", str = ", str);
}

class classFun {
public:
  int &m_i;

  explicit classFun(int &i) : m_i(i) {
    std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::classFun()", Logger::file_and_terminal,
                                                              "../log/thread.log");
    logger->Debug("classFun constructor is use");
  }

  classFun(const classFun &cf) : m_i(cf.m_i) {
    std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::classFun()", Logger::file_and_terminal,
                                                              "../log/thread.log");
    logger->Debug("classFun copy constructor is use");
  }

  ~classFun() {
    std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::classFun()", Logger::file_and_terminal,
                                                              "../log/thread.log");
    logger->Debug("classFun destructor is use");
  }

  void operator()() const {
    std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::classFun()", Logger::file_and_terminal,
                                                              "../log/thread.log");
    /*logger->Info("classFun start...");
    logger->Info("classFun end...");*/
    logger->Debug("m_i_1: ", m_i);
    logger->Debug("m_i_2: ", m_i);
    logger->Debug("m_i_3: ", m_i);
    logger->Debug("m_i_4: ", m_i);
    logger->Debug("m_i_5: ", m_i);
  }
};

void test7() {
  std::shared_ptr<Logger> logger = std::make_shared<Logger>("ThreadTest::test7()", Logger::file_and_terminal,
                                                            "../log/thread.log");
  auto threadLambda = [logger] {
      logger->Info("threadLambda is execute");
  };
  /*int i = 9;
  classFun cf(i);*/
  std::thread th_1(fun2, 5, "hello");
  th_1.join();
  logger->Info("hello world...");
}


#endif //STUDYPRO_THREADTEST_H



