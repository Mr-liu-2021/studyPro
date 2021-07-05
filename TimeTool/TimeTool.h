//
// Created by Acer on 2021/07/04.
//

#ifndef STUDYPRO_TIMETOOL_H
#define STUDYPRO_TIMETOOL_H


#include <string>
#include <ctime>

class TimeTool {
public:
  static time_t getCurrentMilliSecond();

  static time_t getCurrentSecond();

  static std::string currentTimeFormat();






};


#endif //STUDYPRO_TIMETOOL_H
