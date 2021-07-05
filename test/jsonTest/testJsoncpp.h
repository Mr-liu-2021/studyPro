//
// Created by Acer on 2021/04/09.
//

#ifndef STUDYPRO_TESTJSONCPP_H
#define STUDYPRO_TESTJSONCPP_H


#include <json/json.h>
#include <string>

/*
{
    "encoding" : "UTF-8",
    "plug-ins" : [
        "python",
        "c++",
        "ruby"
        ],
    "indent" : { "length" : 3, "use_space": true}
}
*/

/**
 * 生成一个json
 * @return
 */
std::string getJsonStr() {
    Json::Value root;
    Json::Value child;
    std::ostringstream os;

    root["encoding"] = "UTF-8";
    root["plug-ins"].append("python");
    root["plug-ins"].append("c++");
    root["plug-ins"].append("ruby");
    child["length"] = 3;
    child["use_space"] = true;
    root["indent"] = child;
    std::unique_ptr<Json::StreamWriter> jsonWriter(Json::StreamWriterBuilder().newStreamWriter());
    jsonWriter->write(root, &os);

    return os.str();
}


/**
 * 解析json
 * @param jsonStr
 * @return
 */
bool analyzeJson(const std::string &jsonStr) {
    if (jsonStr.empty()) {
        return false;
    }

    bool res;
    JSONCPP_STRING errs;
    Json::Value root, child, indent;
    std::unique_ptr<Json::CharReader> jsonReader(Json::CharReaderBuilder().newCharReader());
    res = jsonReader->parse(jsonStr.c_str(), jsonStr.c_str() + jsonStr.length(), &root, &errs);
    if (!res || !errs.empty()) {
        std::cout << "parseJson errlog: " << errs << std::endl;
    }

    std::cout << "encoding : " << root["encoding"] << std::endl;
    std::cout << "plug-ins : ";
    child = root["plug-ins"];
    for (int i = 0; i < child.size(); i++) {
        std::cout << child[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "length : " << root["indent"]["length"].asInt() << std::endl;
    std::cout << "use_space : " << root["indent"]["use_space"].asBool() << std::endl;

    return true;
}


#endif //STUDYPRO_TESTJSONCPP_H
