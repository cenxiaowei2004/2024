//
// Created by cen on 2024/10/14.
//

#ifndef TEST_STU_H
#define TEST_STU_H

#include <iostream>
#include <cstring>
// using namespace std;

template<class T>
class stu {
public:
    stu(int _age, string _name) : age(_age),name(_name) {};
    void showInfo();
private:
    int age;
    string name;
};

namespace cxw {
    // 模拟实现string
    class mystring {
    private:
        //int size;
        char* ptr;
    public:
        mystring(char* p = nullptr) : ptr(p) {}
        char& operator[](int index) {
            return ptr[index];
        }
        int size() {
            return strlen(ptr);
        }
    };
}


#endif //TEST_STU_H
