//
// Created by Acer on 2021/04/15.
//

#ifndef STUDYPRO_LOGGER_HPP
#define STUDYPRO_LOGGER_HPP

#include <TimeTool.h>
#include <fstream>
#include <sstream>
#include <string>


class Logger {

public:

  // 日志输出目标
  enum log_target {
    file,
    terminal,
    file_and_terminal
  };


  explicit Logger(std::string funName) : m_funName(std::move(funName)) {
    m_target = terminal;
  }

  Logger(std::string funName, const log_target &target, const std::string &filePath = "../log/text.log") :
          m_funName(std::move(funName)), m_target(target) {
    m_fw.open(filePath, std::ios::app);
  }

  ~Logger() {
    if (m_fw.is_open()) {
      m_fw.close();
    }
  }


private:
  log_target m_target;
  std::fstream m_fw;
  std::string m_funName;
  std::stringstream strContent;

  void outToLog() {
    if (m_target == terminal) {
      std::cout << strContent.str() << std::endl;
    } else if (m_target == file) {
      m_fw << strContent.str() << std::endl;
    } else if (m_target == file_and_terminal) {
      m_fw << strContent.str() << std::endl;
      std::cout << strContent.str() << std::endl;
    }
    strContent.str("");
  }

  template<class T, class...Types>
  void outToLog(const T &t, const Types &... args) {
    strContent << t << " ";
    outToLog(args...);
  }

public:

  template<class ...Types>
  void Debug(const Types &... args) {
    strContent << TimeTool::currentTimeFormat() << "|" << m_funName << "|DEBUG|";
    outToLog(args...);
  }

  template<class ...Types>
  void Info(const Types &... args) {
    strContent << TimeTool::currentTimeFormat() << "|" << m_funName << "| INFO|";
    outToLog(args...);
  }

  template<class ...Types>
  void Warn(const Types &... args) {
    strContent << TimeTool::currentTimeFormat() << "|" << m_funName << "| WARN|";
    outToLog(args...);
  }

  template<class ...Types>
  void Error(const Types &... args) {
    strContent << TimeTool::currentTimeFormat() << "|" << m_funName << "|ERROR|";
    outToLog(args...);
  }
};

#endif //STUDYPRO_LOGGER_HPP
