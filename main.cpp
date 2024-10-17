#include <iostream>

// #include "stu.cpp"
#include <string>

//int main() {
//    // std::cout << "Hello, World!" << std::endl;
//    stu <int>s(22,"lisi");
//
//    s.showInfo();
//    return 0;
//}
//int main() {
//    //int arr[3] = {1, 2, 3};
//    // cout << sizeof(arr);
//    string s1("aaa");
//    string s2("hello",2);
//    // cout << sizeof(s)/sizeof(s[0]);
//    // cout << s1.size();
//    // cout << s2;
//    s2 += "111111";
//    for(char c : s2) {
//        cout << c << " ";
//    }
//    for(int i = 0;i < s2.size();i++) {
//        s2[i] = '0';
//    }*/
//    for(char c : s2) {
//        cout << c << " ";
//    }
// string::iterator// 可以用 auto 简化// 长期快乐,真香~
//    auto i = s2.begin();
//    while(i != s2.end()) {
//        *i = 'a';
//        i++;
//   }
//
//    auto ri = s2.rbegin();
//    while(ri != s2.rend()) {
//        cout << *ri << " ";
//        ri++;
//    }
//
//
//    cout << s2.size() << endl;
//    cout << s2.capacity() << endl;
//    return 0;
//}

using namespace std;
// using namespace cxw;

void test01() {
    string s = "aaa";
    s.insert(2,"111");
    s.insert(2,5,'2');
    cout << s << endl;
    cout << s.size() << endl;
    cout << s[0] << endl;
    cout << s[s.size() - 1] << endl;
    // Leetcode : 917
}

void test02() {
//    string s = "aaa";
//    s += '\0';
//    s +="222";
//    cout << s;
    string s = "vvvvvvaa";
    const char* str = s.c_str();
    // cout << str;
//    int ret = s.find('a');
//    cout << ret;
    string url("https://legacy.cplusplus.com/reference/string/string/find/");
    int pos = url.find(':');
    if(pos != string::npos) {
        string http(url.substr(0, pos));
        cout << http << endl;
    }
    int pos1 = url.find('/',pos + 3);
    if(pos1 != string::npos) {
        string web(url.substr(pos + 3, pos1 - pos - 3));
        cout << web;
    }
}

void test03() {
    string str;
    getline(cin,str);
    //string str = "aaaaa ss d";
    // ret = 4
    int pos = str.rfind(' ');
    cout << str.size() - 1 - pos;
}


class Solution01 {
public:
    int switchInt(string s) {
        int ret = 0;
        for (auto c : s) {
            ret = ret * 10 + (c - '0');
        }
        return ret;
    }
    string addStrings(string num1, string num2) {
        int n1 = switchInt(num1);
        int n2 = switchInt(num2);
        return to_string(n1 + n2);
    }
};

string addStrings(string num1, string num2) {
    int next = 0; // 进位
    string s;
    int sum = 0;
    int end1 = num1.size(),end2 = num2.size();
    while(end1 >= 0 || end2 >= 0) {
        int n1 = 0,n2 = 0;
        if(end1 >= 0)
            n1 = num1[end1] - '0';
        if(end2 >= 0)
            n2 = num2[end2] - '0';
        sum = n1 + n2 + next;
        next = sum / 10;
        sum = sum % 10;
        s += (sum + '0');
        end1--;
        end2--;
    }
    return s;
}


//void test04() {
//    mystring s1;
//    mystring s2("abafgmjh");
//    for(int i = 0;i < s2.size();i++) {
//        s2[i] = '1';
//        cout << s2[i] << " ";
//    }
//}


void test05() {
    string s1;
    string s2("aaa");
    string s3(10,'c');
    string s4(s2);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

}


//void test06() {
//    string s("cen's ");
//    s.insert(6,"blo");
//    s.insert(s.end(),'g');
//    cout << s;  // cen's blog
//}



//int main() {
//    string s("cen");
//    s += "'s ";
//    s += "blog";
//    s.pop_back();
//    cout << s;
//    return 0;
//}

//int main() {
//    string str = "oishbnsv;lkbds";
//    str.erase(str.begin() + 3);
//    str.erase(6,4);
//    cout << str;    // oisbnsbds
//    return 0;
//}

//int main() {
//    string str1("abcd");
//    string str2("abde");
//    cout << str1.compare(str2); // -1
//    return 0;
//}

void fun1() {
    string s("abcdef");
    // string::iterator it = s.begin();
    auto it = s.begin();
    while(it != s.end()) {
        cout << *it << " ";
        it++;
    }
}

void fun2() {
    string s("abcdef");
    // string::reverse_iterator it = s.begin();
    auto it = s.rbegin();
    while(it != s.rend()) {
        cout << *it << " ";
        it++;
    }
}

int main() {
    fun2();
    return 0;
}