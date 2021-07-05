//
// Created by Acer on 2021/07/04.
//

#include "TimeTool.h"
#include <cstring>
#include <chrono>

using namespace std;

time_t TimeTool::getCurrentMilliSecond() {
  chrono::time_point<chrono::system_clock, chrono::milliseconds> tp =
          chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
  auto tmp = chrono::duration_cast<chrono::milliseconds>(tp.time_since_epoch());
  time_t timestamp = tmp.count();
  return timestamp;
}

time_t TimeTool::getCurrentSecond() {
  return time(nullptr);
}

string TimeTool::currentTimeFormat() {
  // 获取当前时间，并规范表示
  char tmp[64];
  char buf[5];
  time_t curTime_s = TimeTool::getCurrentSecond();
  time_t curTime_ms = TimeTool::getCurrentMilliSecond();
  strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&curTime_s));
  int res = (int)(curTime_ms - curTime_s*1000);
  sprintf(buf, ".%d", res);
  
  return string(strcat(tmp, buf));
}