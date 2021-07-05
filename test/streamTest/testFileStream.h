//
// Created by Acer on 2021/04/14.
//

#ifndef STUDYPRO_TESTFILESTREAM_H
#define STUDYPRO_TESTFILESTREAM_H

#include <string>
#include <fstream>
#include <iomanip>

#define FILE_PATH "../test/streamTest/testFile/"

/**
 * 文件写入
 * @return
 */
bool testFileWrite() {
    std::fstream fw;
    fw.open(FILE_PATH"test.txt", std::ios::out);
    if (!fw.is_open()) {
        std::cout << "file open error..." << std::endl;
        return false;
    }
    std::string str = "string length 1000!";
    fw << "hello world!!!" << std::endl;
    fw << std::hex << 60 << std::endl;
    fw << std::setprecision(5) << 3.145926535 << std::endl;
    fw << str << std::endl;

    fw.close();
    return true;
}

/**
 * 文件读取
 * @return
 */
bool testFileRead() {
    std::fstream fr;
    char buf[1024];
    std::string str;
    fr.open(FILE_PATH"test.txt", std::ios::in);
    if (!fr.is_open()) {
        std::cout << "file open error..." << std::endl;
        return false;
    }
    /*while (!fr.eof()) {
        //如果一行的字符数量超过给定数值，此方法会出错
        fr.getline(buf, 1024);
        std::cout << buf << std::endl;
    }*/
    while(!fr.eof()){
        std::getline(fr, str);
        std::cout << str << std::endl;
    }
    return true;
}


#endif //STUDYPRO_TESTFILESTREAM_H
