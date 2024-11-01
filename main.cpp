#include <iostream>

// #include "stu.cpp"
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <forward_list>
// #include <priority_queue>

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

//int main() {
//    string s1("asd");
//    string s2("dddd");
//    s1.swap(s2);
//    cout << s2;
//    return 0;
//}


void fun01() {
    vector<int> v;
    v.push_back(100);
    v.push_back(44);
    v.push_back(2);
    v.push_back(678);
    v.push_back(678);
    v.push_back(678);
//    for(vector<int>:: const_reverse_iterator it = v.rbegin();it != v.rend();it++) {
//        cout << *it << " ";
//    }
//    for(auto i : v) {
//        cout << i << endl;
//    }
    // v.push_back()

    // iterator
    // const_iterator
    // reverse_iterator
    // const_reverse_iterator
    cout << v.size() << v.capacity();
}


void singleNumber(vector<int>& nums) {
    int arr[32] = {0};
    for(int i : nums) {
        for(int n = 0;n < 32;n++) {
            arr[n] += ((i >> n) & 1);
        }
    }
    for(int i : arr) {
        cout << i << " ";
    }
    // cout << ((6 >> 0)&1);
}

//int main() {
//    // fun01();
////    string name = "afshighd";
////    int pos = name.find('g');
////    name.erase(name.begin() + pos);
////    cout << name;
//
//    vector<int>v = {1,1};
////    v.push_back(2);
////    v.push_back(2);
////    v.push_back(2);
////    v.push_back(3);
//    //singleNumber(v);
//    cout << v[0];
//    cout << v[1];
//    return 0;
//}


//int main() {
//    vector<int> v;
//    vector<int>::iterator it = v.begin();
//    v.push_back(100);
//    v.push_back(3);
//    v.push_back(5);
//    v.push_back(10);
//    v.push_back(1);
//
//    while(it != v.end()) {
//        if(*it%2 == 0)
//            v.erase(it);
//        it++;
//    }
//    for(auto i : v) {
//        cout << i << " ";
//    }
//
//    return 0;
//}


// 既然有了vector，为什么还会有list
// vector缺点：
// 1、头部和中部的插入和删除数据效率较低（因为需要挪动数据）
// 2、空间不够，需要开辟空间，其中会重新拷贝数据，消耗较大
// vector优点：
// 支持下标随机访问，进而很好地支持了二分查找、排序等
//
// list优点：
// 1、与vector相反，插入和删除的效率较高，直接插入节点即可
// list缺点：
// 1、不支持下标随机访问

//int main() {
//    list<int> l;
//    l.push_back(100);
//    l.push_back(23);
//    l.push_back(1);
//    l.push_back(10);
//    l.push_front(99);
//
//    l.sort();
////    for(int i : l) {
////        cout << i << " ";
////    }
////    cout << l.empty();
//    forward_list<int>fl;
////    fl.push_front(100);
////    for(int i : l) {
////        cout << i << " ";
////    }
////
////    cout << l.front();
//    list<int>::iterator it = l.begin();
//    while(it != l.end()) {
//        cout << *it << endl;
//        it++;
//    }
//
//
//
//    return 0;
//}

bool deleteOddNumber(int& i) {
    return i % 2 != 0;
}

//int main() {
//    list<int> l;
//    list<int> li;
//    li.push_back(200);
//    li.push_back(2);
//    l.push_back(100);
//    l.push_back(23);
//    l.push_back(1);
//    l.push_back(10);
//    l.push_front(99);
//    l.reverse();

//    l.remove(99);
//    l.remove_if(deleteOddNumber);
//    l.splice(l.begin(),li);
//    for(int i : l) {
//        cout << i << " ";
//    }
//    cout << endl;
//    for(int i : li) {
//        cout << i << " ";
//    }
//    return 0;
//
//}

// tasks:
// 1. 离散数学
// 2. codeint main() {
//    stack<int>s;
//    栈没有迭代器
//    int a = INTMAX_MAX;
//    cout << a;
//    stack<int>s;
//    s.push(100);
//    s.push(200);
//    s.push(1);
//    s.push(10);
//    while(!s.empty()) {
//        cout << s.top() << " ";
//        s.pop();
//    }
//    queue<int,vector<int>>q;
//    q.push(100);
//    q.push(2);
//    q.push(4);
//    q.push(10);
//    q.push(300);
//    while(!q.empty()) {
//        cout << q.front() << " ";
//        q.pop();
//    }
//    deque<int>d;
//    priority_queue<int>q;
//    q.push(100);
//    q.push(200);
//
//
//    return 0;
//}
//int main() {
//    priority_queue<int,vector<int>> p;
//    p.push(100);
//    p.push(10);
//    p.push(22);
//    p.push(34);
//    p.push(1);
//    // 100 34 22 10 1
//    while(!p.empty()) {
//        cout << p.top() << " ";
//        p.pop();
//    }
//    return 0;
//}

// 后续内容： 模板进阶 + 继承多态 + 二叉树 + set + map + C++ 11 + 复习

template<typename T, int N>
T add(T x,T y) {
    int arr[N];
    return x + y;
}
#include<string.h>

template<typename T>
bool isEqual(T t1,T t2) {
    return t1 == t2;
}
template<>
bool isEqual(char* ch1,char* ch2) {
    return strcmp(ch1,ch2) == 0;
}

// 类原模版
template<class T1,class T2>
class A {
private:
    T1 t1;
    T2 t2;
public:
    A(T1 _t1,T2 _t2) : t1(_t1),t2(_t2) {
        cout << "A <T1, T2>" << endl;
    };
};
// 类模板的特化
template<>
class A<int, double> {
private:
    int t1;
    double t2;
public:
    A(int _t1,double _t2) : t1(_t1),t2(_t2) {
        cout << "A <int, double>" << endl;
    };
};

// 类模板的偏特化
// 特化部分参数
template<class T2>
class A<int, T2> {
private:
    int t1;
    T2 t2;
public:
    A(int _t1,T2 _t2) : t1(_t1),t2(_t2) {
        cout << "A <int, T2>" << endl;
    };
};

// 对参数进行限制
template<class T1,class T2>
class A<T1&, T2&> {
private:
    T1 t1;
    T2 t2;
public:
    A(T1 _t1,T2 _t2) : t1(_t1),t2(_t2) {
        cout << "A <T1&, T2&>" << endl;
    };
};

//    int main() {
//    cout << isEqual<int>(100,200);      // 0
//    cout << isEqual<double>(3.14,3.14); // 1
//    char ch1[] = "asdf";
//    char ch2[] = "asdf";
//    cout << isEqual<char*>(ch1,ch2); // ?
//    }

//int main() {
//    A<int,string> a1(12,"wewf");    //A <T1, T2>
//    A<int,double> a2(12, 3.111);    //A <int, double>
//    return 0;
//}


// 学习继承
// 人类、学生类、老师类

//class person {
//private:
//    string name;
//    string gender;
//    int age;
//public:
//    // 构造函数
//    person(string _name = " ",string _gender = " ",int _age = 0 ) : name(_name),gender(_gender),age(_age) {}
//    // 拷贝构造函数
//    person(const person& p) {
//        name = p.name;
//        gender = p.gender;
//        age = p.age;
//    }
//    // 赋值运算符重载函数
//    person& operator=(const person& p) {
//        if(this != &p) {
//            name = p.name;
//            gender = p.gender;
//            age = p.age;
//        }
//        return *this;
//    }
//    // 析构函数
//    ~person() {}
//};
//
//class student : public person{
//private:
//    int stuid;  // 学号
//public:
//    // 构造函数
//    student(const string& name,string gender,int age,int _stuid) : person(name,gender,age),stuid(_stuid) {}
//    // 拷贝构造函数
//    student(const student& s) : person(s), stuid(s.stuid) {}
//    // 赋值运算符重载函数
//    student& operator=(const student& s) {
//        if(this != &s) {
//            person::operator=(s);
//            stuid = s.stuid;
//        }
//        return *this;
//    }
//    // 析构函数
//    ~student() {}
//};
//
//class teacher : public person{
//private:
//    int jobid;  // 工号
//public:
//    // ...
//};

// 10/27 tasks
// 1.继承的完结
// 2.线代、离散、概率...
// 3.英语六级

// 多态的学习与认识

// 买票的场景，普通人买票是全价，学生买票是半价，而军人允许优先买票。
// 不同身份的人去买票，所产生的行为是不同的，这就是所谓的多态。

class person {
public:
    virtual void buyTicket(int a = 1) = 0;
};

class student : public person {
    virtual void buyTicket(int a = 0) override {
        cout << "学生半价车票"  << a << endl;
    }
};

class soldier : public person {
//    virtual void buyTicket() override {
//        cout << "军人优先购票" << endl;
//    }
};
void func(person& p) {
    p.buyTicket();
}

//int main() {
//    person p;
//    student stu;
//    soldier sol;
//    func(stu);
//    func(sol);
//    func(p);
//    // 学生半价车票
//    // 军人优先购票
//    // 普通人全价购票
//    return 0;
//}

// 8：25 ~ 10：25




class Base {
public:
    virtual void Func1() {
        cout << "Func1()" << endl;
    }
private:
    int _b = 1;
};

//int main() {
//    Base b;
//    cout << sizeof(b) << endl;
//    return 0;
//}


// 数据结构的开始（C++）
// 2024/10/30

//一、学习时间复杂度和了解空间复杂度

// 顺序表的模拟实现（静态），固定大小，容易实现
// ...

// 顺序表的模拟实现（动态），大小可变

#include <memory>

template<class T>
class SeqList {
public:
    // 构造函数
    SeqList() : size(0), capacity(5) {
        dataList = new T[5];   // 堆区开辟5个空间,顺序表容量开辟为5
    }
    // 其他成员函数：尾插尾删，头插头删，插入元素，删除元素
    // 尾插
    void push_back(T t);
    // 尾删
    void pop_back();
    // 前插
    void push_front(T t);
    // 前删
    void pop_front();
    // 展示数据
    void printSL();
    // 数据插入
    void insert(T t,int pos);
    // 数据删除
    void erase(int pos);
    // 检查空间是否需要扩容
    void checkSpace() {
        if(size > capacity) {
            // 开辟规则：按照原来的1.5 ~ 2倍进行开辟(此过程并非唯一)
            // 并且进行数据迁移,使用realloc / 智能指针 + new
            capacity *= 2;
            dataList = (T*)realloc(dataList, sizeof(T) * capacity);
        }
    }
    ~SeqList() {
        size = 0;
        capacity = 0;
        // 销毁dataList
        delete[] dataList;
    }
private:
    T* dataList;
    // 顺序表中有效数据的个数
    int size;
    // 顺序表中总的开辟个数
    int capacity;
};

template<class T>
void SeqList<T>::push_back(T t) {
    // 容量不够的情况下：
    checkSpace();
    // 容量够的情况下：
    dataList[size] = t;
    size++;
}

template<class T>
void SeqList<T>::pop_back() {
    size--;
}

template<class T>
void SeqList<T>::printSL() {
    for(int i = 0;i < size;i++) {
        cout << dataList[i] << " ";
    }
}

template<class T>
void SeqList<T>::push_front(T t) {
    // 容量不够的情况下：
    checkSpace();
    // 容量够的情况下：
    int end = size - 1;
    while(end >= 0) {
        dataList[end + 1] = dataList[end];
        end--;
    }
    dataList[0] = t;
    size++;
}

template<class T>
void SeqList<T>::pop_front() {
    int start = 0;
    while(start < size) {
        dataList[start] = dataList[start + 1];
        start++;
    }
    size--;
}

template<class T>
void SeqList<T>::insert(T t,int pos) {
    // 插入，在pos - (size - 1)的数据往后挪
    // 下标错误排查
    if(pos < 0 || pos > size)
        return;
    int end = size - 1;
    checkSpace();
    while(end >= pos) {
        dataList[end + 1] = dataList[end];
        end--;
    }
    dataList[pos] = t;
    size++;
}

template<class T>
void SeqList<T>::erase(int pos) {
    // 下标错误排查
    if(pos < 0 || pos > size)
        return;
    // 删除数据，[ pos - (size - 1) ]的数据往前挪,将数据覆盖
    int start = pos + 1;
    while(start < size) {
        dataList[start - 1] = dataList[start];
        start++;
    }
    size--;
}

void testSeqList() {
    SeqList<int> sl;
    sl.push_back(100);
    sl.push_back(200);
    sl.push_back(300);
    sl.push_back(400);
    sl.push_back(400);
    sl.push_back(400);
    sl.push_back(0);
    sl.push_back(111);
    sl.pop_back();
    sl.push_front(1);
    sl.push_front(2);
    sl.pop_front();
    // 1 100 200 300 400 400 400 0
    sl.insert(999,3);
    // 1 100 200 999 300 400 400 400 0
    sl.erase(3);
    // 1 100 200 300 400 400 400 0
    sl.printSL();
}


// 链表的实现

// 单链表的实现 2024/11/01

void test10() {
    // ...
}

// 今日话题：为什么二者不可兼得？
// 考研 or 工作 or 保研（没实力，已经pass了）
// 考研：英语、数学、政治、专业、关注目标院校
// 工作：C++、数据结构、操作系统、Linux网络编程、做项目、找实习、关注行业动态
// 外部压力：父母催赶、大环境、赚钱money、创业😀（头发保命）
// 内心方向：以高中的努力，应该不会太差，211硕士没问题
//

template<class T>
class SLList {
public:
    // 构造函数
    SLList() : head(nullptr) {}
    // 打印链表元素
    void printSLList();
    // 尾插
    void push_back(T t);
private:
    class ListNode {
    public:
        ListNode* next; // 指针域
        T data;         // 数据域
        ListNode(T x) : next(nullptr), data(x) {}
    };
    ListNode* head;
};

template<class T>
void SLList<T>::printSLList() {
    ListNode* node = head;
    while(node != nullptr) {
        cout << node->data << endl;
        node = node->next;
    }
}

template<class T>
void SLList<T>::push_back(T t) {
    ListNode* node = head;
    ListNode* newnode = new ListNode(t);
    while(node != nullptr) {
        node = node->next;
    }
    newnode->next = nullptr;
    node->next = newnode;
}


void testSLList() {
    SLList<int> slList;
    slList.push_back(100);
    slList.push_back(100);
    slList.push_back(100);
    slList.push_back(100);
    slList.printSLList();
}


int main() {
    // testSeqList();

    testSLList();
    return 0;
}

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
*/


