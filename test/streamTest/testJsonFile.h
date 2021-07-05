//
// Created by Acer on 2021/04/14.
//

#ifndef STUDYPRO_TESTJSONFILE_H
#define STUDYPRO_TESTJSONFILE_H

#include <string>
#include <fstream>
#include <json/json.h>

#define FILE_PATH "../test/streamTest/testFile/"

/*
{
    "description": "this is a JSON test",
    "version": "0.0.1",
    "list": {
        "listkey1": "listvalue1",
        "listkey2": "listvalue2",
        "listkey3": "listvalue3"
    },
    "words": [
        "apple",
        "banana",
        "cat"
    ]
}
*/

/**
 * 使用jsoncpp
 * @return
 */
bool productJsonFile() {
    Json::Value root;
    Json::Value child;
    std::ostringstream oss;
    std::fstream fw;


    /*root["description"] = "this is a JSON test";
    root["version"] = "0.0.1";
    child["listkey1"] = "listvalue1";
    child["listkey2"] = "listvalue2";
    child["listkey3"] = "listvalue3";
    root["list"] = child;
    root["words"].append("apple");
    root["words"].append("banana");
    root["words"].append("cat");
    std::unique_ptr<Json::StreamWriter> jsonWriter(Json::StreamWriterBuilder().newStreamWriter());
    jsonWriter->write(root, &oss);*/

    std::string jsonStr = "{\"description\":\"this is a JSON test\",\"list\":{\"listkey1\":\"listvalue1\",\"listkey2\":\"listvalue2\",\"listkey3\":\"listvalue3\"},\"version\":\"0.0.1\",\"words\":[\"apple\",\"banana\",\"cat\"]}";


    fw.open(FILE_PATH"jsonStr.json", std::ios::out);
    if (!fw.is_open()) {
        std::cout << "file open error..." << std::endl;
        return false;
    }
//    fw << oss.str();
    fw << jsonStr;

    return true;
}


bool getJsonFile() {
    Json::Value root;
    std::fstream fr;
    fr.open(FILE_PATH"jsonStr.json", std::ios::in);
    if (!fr.is_open()) {
        std::cout << "file open error..." << std::endl;
        return false;
    }
    std::string jsonStr;
    JSONCPP_STRING errs;
    std::getline(fr, jsonStr);
    std::unique_ptr<Json::CharReader> jsonReader(Json::CharReaderBuilder().newCharReader());
    bool res = jsonReader->parse(jsonStr.c_str(), jsonStr.c_str() + jsonStr.length(), &root, &errs);
    if (!res || !errs.empty()) {
        std::cout << "parseJson errlog: " << errs << std::endl;
    }
    std::cout<<"description : "<<root["description"]<<std::endl;
    std::cout<<"version : "<<root["version"]<<std::endl;
    std::cout<<"words : ";
    for(const auto &x : root["words"]){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;


    return true;
}


#endif //STUDYPRO_TESTJSONFILE_H
