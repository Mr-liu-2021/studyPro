//
// Created by Acer on 2021/06/06.
//

#ifndef STUDYPRO_TEST1_H
#define STUDYPRO_TEST1_H

#include <iostream>
#include <string>

using namespace std;

int calcNum(const int &n, string str) {
    int index;
    cout << "Enter the starting position of the data string you want to delete:";
    cin >> index;
    if (n != str.size()) {
        cout << "input param is error, Exit!" << endl;
        return 0;
    } else if(index <= 0 || index > str.size() || index != 0 && str[index-1] == str[index-2]) {
        cout << "index is error, Exit!" << endl;
        return 0;
    }
    int num = 0;
    for (int i = index - 1; i < str.size(); i++) { //00110
        if(str[i] == str[index - 1]) {
            num++;
        }else {
            break;
        }
    }
    str.erase(index-1, num);
    cout << str << endl;

    int max_0 = 0, max_1 = 0;
    int num_0 = 0, num_1 = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '1') {
            if(max_0 < num_0) {
                max_0 = num_0;
                num_0 = 0;
            }
            num_1++;
            if(i+1 == str.size()) {
                if(max_1 < num_1) {
                    max_1 = num_1;
                    num_1 = 0;
                }
            }
        } else if(str[i] == '0'){
            if(max_1 < num_1) {
                max_1 = num_1;
                num_1 = 0;
            }
            num_0++;
            if(i+1 == str.size()) {
                if(max_0 < num_0) {
                    max_0 = num_0;
                    num_0 = 0;
                }
            }
        } else{
            cout<<"UNKNOWN ERROR!"<<endl;
        }
    }

    cout<<"max_0: "<<max_0<<endl;
    cout<<"max_1: "<<max_1<<endl;

    return 0;

}


#endif //STUDYPRO_TEST1_H
