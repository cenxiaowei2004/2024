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
#include<algorithm>


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
    s.insert(2, "111");
    s.insert(2, 5, '2');
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
    const char *str = s.c_str();
    // cout << str;
//    int ret = s.find('a');
//    cout << ret;
    string url("https://legacy.cplusplus.com/reference/string/string/find/");
    int pos = url.find(':');
    if (pos != string::npos) {
        string http(url.substr(0, pos));
        cout << http << endl;
    }
    int pos1 = url.find('/', pos + 3);
    if (pos1 != string::npos) {
        string web(url.substr(pos + 3, pos1 - pos - 3));
        cout << web;
    }
}

void test03() {
    string str;
    getline(cin, str);
    //string str = "aaaaa ss d";
    // ret = 4
    int pos = str.rfind(' ');
    cout << str.size() - 1 - pos;
}


class Solution01 {
public:
    int switchInt(string s) {
        int ret = 0;
        for (auto c: s) {
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
    int end1 = num1.size(), end2 = num2.size();
    while (end1 >= 0 || end2 >= 0) {
        int n1 = 0, n2 = 0;
        if (end1 >= 0)
            n1 = num1[end1] - '0';
        if (end2 >= 0)
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
    string s3(10, 'c');
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
    while (it != s.end()) {
        cout << *it << " ";
        it++;
    }
}

void fun2() {
    string s("abcdef");
    // string::reverse_iterator it = s.begin();
    auto it = s.rbegin();
    while (it != s.rend()) {
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


void singleNumber(vector<int> &nums) {
    int arr[32] = {0};
    for (int i: nums) {
        for (int n = 0; n < 32; n++) {
            arr[n] += ((i >> n) & 1);
        }
    }
    for (int i: arr) {
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

bool deleteOddNumber(int &i) {
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
T add(T x, T y) {
    int arr[N];
    return x + y;
}

#include<string.h>

template<typename T>
bool isEqual(T t1, T t2) {
    return t1 == t2;
}

template<>
bool isEqual(char *ch1, char *ch2) {
    return strcmp(ch1, ch2) == 0;
}

// 类原模版
template<class T1, class T2>
class A {
private:
    T1 t1;
    T2 t2;
public:
    A(T1 _t1, T2 _t2) : t1(_t1), t2(_t2) {
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
    A(int _t1, double _t2) : t1(_t1), t2(_t2) {
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
    A(int _t1, T2 _t2) : t1(_t1), t2(_t2) {
        cout << "A <int, T2>" << endl;
    };
};

// 对参数进行限制
template<class T1, class T2>
class A<T1 &, T2 &> {
private:
    T1 t1;
    T2 t2;
public:
    A(T1 _t1, T2 _t2) : t1(_t1), t2(_t2) {
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
        cout << "学生半价车票" << a << endl;
    }
};

class soldier : public person {
//    virtual void buyTicket() override {
//        cout << "军人优先购票" << endl;
//    }
};

void func(person &p) {
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
    void insert(T t, int pos);

    // 数据删除
    void erase(int pos);

    // 检查空间是否需要扩容
    void checkSpace() {
        if (size > capacity) {
            // 开辟规则：按照原来的1.5 ~ 2倍进行开辟(此过程并非唯一)
            // 并且进行数据迁移,使用realloc / 智能指针 + new
            capacity *= 2;
            dataList = (T *) realloc(dataList, sizeof(T) * capacity);
        }
    }

    ~SeqList() {
        size = 0;
        capacity = 0;
        // 销毁dataList
        delete[] dataList;
    }

private:
    T *dataList;
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
    for (int i = 0; i < size; i++) {
        cout << dataList[i] << " ";
    }
}

template<class T>
void SeqList<T>::push_front(T t) {
    // 容量不够的情况下：
    checkSpace();
    // 容量够的情况下：
    int end = size - 1;
    while (end >= 0) {
        dataList[end + 1] = dataList[end];
        end--;
    }
    dataList[0] = t;
    size++;
}

template<class T>
void SeqList<T>::pop_front() {
    int start = 0;
    while (start < size) {
        dataList[start] = dataList[start + 1];
        start++;
    }
    size--;
}

template<class T>
void SeqList<T>::insert(T t, int pos) {
    // 插入，在pos - (size - 1)的数据往后挪
    // 下标错误排查
    if (pos < 0 || pos > size)
        return;
    int end = size - 1;
    checkSpace();
    while (end >= pos) {
        dataList[end + 1] = dataList[end];
        end--;
    }
    dataList[pos] = t;
    size++;
}

template<class T>
void SeqList<T>::erase(int pos) {
    // 下标错误排查
    if (pos < 0 || pos > size)
        return;
    // 删除数据，[ pos - (size - 1) ]的数据往前挪,将数据覆盖
    int start = pos + 1;
    while (start < size) {
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
    sl.insert(999, 3);
    // 1 100 200 999 300 400 400 400 0
    sl.erase(3);
    // 1 100 200 300 400 400 400 0
    sl.printSL();
}


// 链表的实现

// 单链表的实现 2024/11/01


// 今日话题：为什么二者不可兼得？
// 考研 or 工作 or 保研（没实力，已经pass了）
// 考研：英语、数学、政治、专业、关注目标院校
// 工作：C++、数据结构、操作系统、Linux网络编程、做项目、找实习、关注行业动态
// 外部压力：父母催赶、大环境、赚钱money、创业（头发保命）
// 内心方向：以高中的努力，应该不会太差，211硕士没问题[狗头]
//

template<class T>
class SLList {
public:
    // 构造函数
    SLList() : head(nullptr) {}

    // 打印链表元素
    void printSLList();

    // 增删成员函数
    // 尾插
    void push_back(T t);

    // 前插
    void push_front(T t);

    // 尾删
    void pop_back();

    // 前删
    void pop_front();

    // 在第一个指定位置后插入一个数据（后插）
    void insert(T pos, T t);

    // 在第一个指定位置删除一个数据
    void erase(T pos);

    // 析构函数
    ~SLList() {
        ListNode *node = head;
        while (node != nullptr) {
            ListNode *temp = node->next;
            delete node;
            node = temp;
        }
    }

    class ListNode {
    public:
        ListNode *next; // 指针域
        T data;         // 数据域
        ListNode(T x) : next(nullptr), data(x) {}
    };

    void append(SLList<T> &l) {
        if (!l.head) return; // 如果l为空，则什么也不做
        // 找到当前链表的最后一个节点
        ListNode *node = head;

        while (node->next != nullptr) {
            node = node->next;
        }
        // 将当前链表的最后一个节点的下一个指向l的第一个节点
        node->next = l.head;
    }

private:
    ListNode *head;
};

template<class T>
void SLList<T>::printSLList() {
    ListNode *node = head;
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr";
}

template<class T>
void SLList<T>::push_back(T t) {
    ListNode *node = head;
    ListNode *newnode = new ListNode(t);
    // 检查头节点是否为空
    // 头节点为空
    if (node == nullptr)
        head = newnode;
        // 头节点非空
    else {
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = newnode;
    }
}

template<class T>
void SLList<T>::push_front(T t) {
    // 与尾插类似
    ListNode *node = head;
    ListNode *newnode = new ListNode(t);
    if (head != nullptr) {
        newnode->next = node;
    }
    head = newnode;
}

template<class T>
void SLList<T>::pop_back() {
    ListNode *node = head;
    if (node == nullptr || node->next == nullptr) {
        head = nullptr;
        return;
    }
    while (node->next->next != nullptr) {
        node = node->next;
    }
    delete node->next;
    node->next = nullptr;
}

template<class T>
void SLList<T>::pop_front() {
    ListNode *node = head;
    if (node == nullptr || node->next == nullptr) {
        head = nullptr;
        return;
    }
    head = head->next;
    delete node;
}

template<class T>
void SLList<T>::insert(T pos, T t) {
    ListNode *node = head;
    ListNode *newnode = new ListNode(t);
    if (head == nullptr)
        return;
    if (head->data == pos) {
        newnode->next = head->next;
        head->next = newnode;
        return;
    }
    while (node->next != nullptr) {
        node = node->next;
        if (node->data == pos)
            break;
    }
    newnode->next = node->next;
    node->next = newnode;
}

template<class T>
void SLList<T>::erase(T pos) {
    // 指定位置数据
    ListNode *node = head;
    if (head == nullptr || head->data == pos)
        return;
    while (node->next->next != nullptr) {
        node = node->next;
        if (node->next->data == pos)
            break;
    }
    ListNode *tempnode = node->next;
    node->next = tempnode->next;
    delete tempnode;
}


void testSLList() {
    SLList<int> slList;
    // slList.push_back(100);
    // slList.push_back(200);
    slList.push_back(999);
    slList.push_back(888);
    slList.push_back(777);
    slList.insert(999, 666);
    // 999 -> 666 -> 888 -> 777 -> nullptr
    slList.erase(888);
    SLList<int> l;
    l.push_back(1222);
    l.push_back(123);
    l.push_back(12222);
    l.push_back(3333);
    slList.append(l);
    slList.printSLList();

}


//int main() {
//    testSLList();
//}


void getBinary(int n) {
    for (int i = 0; i < 32; i++) {
        cout << ((n >> i) & 1) << " ";
    }
}

// 力扣 206 27 26 989

namespace N {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class Solution_206 {
    public:
        ListNode *reverse(ListNode *cur, ListNode *prev) {
            if (cur == nullptr)
                return prev;
            ListNode *temp = cur->next;
            cur->next = prev;
            // prev = cur;
            // cur = temp;
            // return reverse(cur, prev);
            return reverse(temp, cur);
        }

        ListNode *reverseList(ListNode *head) {
            // 递归怎么写？
            // 仿照一下，二叉树的遍历，这是一个经典递归问题
            // 迭代总是可以转换为递归
            // 先把过程想清楚，然后想一想如何让复用，即那个过程是重复的
            return reverse(head, nullptr);
        }
    };

}

//int main() {
//    // testSeqList();
//    // testSLList();
//    getBinary(4);
//
//    return 0;
//}

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
                                         #cen
*/

// 上面实现的是无头单向链表

// 快捷键： Ctrl + Alt + L = 格式化代码










// 下面实现带头双向循环链表
template<class T>
class DLList {
public:
    class Listnode {
    public:
        Listnode *prev;
        Listnode *next;
        T data;

        // Listnode() : prev(nullptr), next(nullptr) {}
        Listnode(T t) : prev(nullptr), next(nullptr), data(t) {}
    };

    DLList() {
        phead = new Listnode(0);
    }

    // 尾插
    void push_back(T t);

    // 头插
    void push_front(T t);

    // 尾删
    void pop_back();

    // 头删
    void pop_front();

    // 指定位置插入：指定位置之前插入一个结点
    void insert(T pos, T t);

    // 指定位置删除：
    void erase(T pos);

    // 打印链表
    void printList();

    // 构造函数
    ~DLList() {
        Listnode *node = phead;
        while (node != nullptr) {
            Listnode *temp = node;
            node = node->next;
            delete temp;
        }
    }

private:
    Listnode *phead;
};

template<class T>
void DLList<T>::push_back(T t) {
    Listnode *newnode = new Listnode(t);
    Listnode *node = phead;
    if (phead->next == nullptr) {
        newnode->prev = phead;
        phead->next = newnode;
        return;
    }
    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = newnode;
    newnode->prev = node;
}

template<class T>
void DLList<T>::push_front(T t) {
    Listnode *newnode = new Listnode(t);
    if (phead->next == nullptr) {
        phead->next = newnode;
        newnode->prev = phead;
        return;
    }
    newnode->next = phead->next;
    newnode->prev = phead;
    phead->next = newnode;
}

// Siuuuuuu~

template<class T>
void DLList<T>::printList() {
    Listnode *node = phead->next;
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr";
}

template<class T>
void DLList<T>::pop_back() {
    Listnode *node = phead;
    if (phead->next == nullptr) {
        return;
    }
    while (node->next->next != nullptr) {
        node = node->next;
    }
    Listnode *temp = node->next;
    delete temp;
    node->next = nullptr;
}

template<class T>
void DLList<T>::pop_front() {
    if (phead->next == nullptr)
        return;
    Listnode *temp = phead->next->next;
    delete phead->next;
    phead->next = temp;
    temp->prev = phead;
}

template<class T>
void DLList<T>::insert(T pos, T t) {
    Listnode *node = phead;
    Listnode *newnode = new Listnode(t);
    while (node->next != nullptr) {
        if (node->next->data == pos) {
            break;
        }
        node = node->next;
    }
    Listnode *temp = node->next;
    node->next = newnode;
    newnode->prev = node;
    newnode->next = temp;
    temp->prev = newnode;
}

template<class T>
void DLList<T>::erase(T pos) {
    // 删除pos
    Listnode *node = phead;
    if (node->next == nullptr)
        return;
    while (node->next != nullptr) {
        if (node->next->data == pos) {
            // 删除
            Listnode *temp = node->next;
            node->next = temp->next;
            temp->prev = node;
            delete temp;
            return;
        }
        node = node->next;
    }
}

void testSDList() {
    DLList<int> dlList;
    dlList.push_back(100);
    dlList.push_back(233);
    dlList.push_back(3);
    dlList.push_back(13);
    dlList.push_back(33);
    dlList.push_front(10);
    dlList.pop_back();
    // 10 -> 100 -> nullptr
    dlList.pop_front();
    // 100 -> 233 -> 3 -> 13 -> nullptr
    dlList.insert(3, 50);
    dlList.erase(13);
    // 100 -> 233 -> 50 -> 3 -> nullptr
    dlList.printList();
}


int getMin(vector<int> &nums) {
    int minret = INT32_MAX; // 或者max
    // 数组排序
    sort(nums.begin(), nums.end());
    // 双指针
    int left = 0, right = nums.size() - 1;
    int sum1 = nums[left], sum2 = nums[right];
    left++;
    right--;
    // sum1 记录左队之和,sum2 记录右队之和
    while (left <= right) {
        if (sum1 < sum2) {
            sum1 += nums[left++];
        } else if (sum1 > sum2) {
            sum2 += nums[right--];
        }
        minret = min(minret, abs(sum1 - sum2));
    }
    // cout << sum1 << " " << sum2 << endl;
    return minret;
}

// 栈的模拟实现

template<class T>
class Stack {
private:
    int size;
    int capacity;
    T *arr;

    void checkSpace();

public:
    Stack() : size(0), capacity(0) {
        arr = new T[5];
    }

    ~Stack() {
        size = 0;
        capacity = 0;
        arr = nullptr;
    }

    void push(T t);

    void pop();

    int getSize() {
        return size;
    }

    T top() {
        return arr[size - 1];
    }

    bool empty() {
        return size == 0;
    }
};

template<class T>
void Stack<T>::checkSpace() {
    if (size > capacity) {
        // 扩容
        capacity *= 2;
        arr = (T *) realloc(arr, sizeof(T) * capacity);
    }
}

template<class T>
void Stack<T>::push(T t) {
    checkSpace();
    arr[size] = t;
    size++;
}

template<class T>
void Stack<T>::pop() {
    if (size > 0)
        size--;
}

void testStack() {
    Stack<int> stack;
    stack.push(100);
    stack.push(23);

    cout << stack.top();
    cout << endl;
    cout << stack.getSize();

}

// 后续内容：Linux

// 对于使用数组来实现队列，会出现假溢出的情况，因此出现了环形数组实现栈
// 以至于充分利用空间
// 有front和rear表示队头和队尾
// front = (front + 1) % max_size
// rear  = (rear  + 1) % max_size

// 前置知识：

// 0 1 2 3 4 5 6
// 受不了，好强啊

void test() {

}

// 优才计划

// 脑子在boom~

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;   // max_size

public:
    CircularQueue() : front(0), rear(0), capacity(5) {
        arr = new int[5];
    }

    // 判断队空
    bool empty() {
        return front == rear;
    }

    // 判断队满
    bool full() {
        return (rear + 1) % capacity == front;
    }

    void push(int t) {
        if (full() || rear != 0) {
            cout << "队列已满,不能入队~" << endl;
            return;
        }
        arr[rear] = t;
        rear = (rear + 1) % capacity;
    }

    int pop() {
        if (empty()) {
            cout << "队列已空,不能出队~" << endl;
            return 0;
        }
        int temp = arr[front];
        front = (front + 1) % capacity;
        return temp;
    }

    int getfront() {
        if (empty()) {
            cout << "队列已空,不能出队~" << endl;
            return 0;
        }
        return arr[front];
    }

    int getrear() {
        if (empty()) {
            cout << "队列已空,不能出队~" << endl;
            return 0;
        }
        return arr[rear];
    }

    int getsize() {
        return (rear - front + capacity) % capacity;
    }

};

// 摸鱼：看小会儿Linux
// 瞎玩一会儿，hhh

void testCircleQueue() {
    CircularQueue cirqueue;
    cirqueue.push(100);
    cirqueue.push(200);
    cirqueue.push(300);
    cirqueue.push(499);
    cirqueue.push(444);
    cirqueue.push(222);

    cout << cirqueue.getfront() << endl;
}


// 二叉树的实现

class BinaryTreeNode {
public:
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    int data;

    BinaryTreeNode(int val) : left(nullptr), right(nullptr), data(val) {}
};

class BinaryTree {
public:
    BinaryTreeNode *root;

    BinaryTree() : root(nullptr) {}

    BinaryTree(BinaryTreeNode *newroot) : root(newroot) {}

    // 插入
    void insert_left(BinaryTreeNode *root, int value);

    void insert_right(BinaryTreeNode *root, int value);

    // 遍历：
    // 前中后、层序遍历
    // 前序：中左右
    void preOrder(BinaryTreeNode *node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << "->";
        preOrder(node->left);
        preOrder(node->right);
    }

    // 中序：左中右
    void inOrder(BinaryTreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        cout << node->data << "->";
        inOrder(node->right);
    }

    // 后序：左右中
    void postOrder(BinaryTreeNode *node) {
        if (node == nullptr) {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << "->";
    }

    // 获取树的节点数
    int getNodeSize(BinaryTreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + getNodeSize(node->left) + getNodeSize(node->right);
    }

    // 层序遍历
    // 使用队列queue
    void levelOrder(BinaryTreeNode *node) {
        queue<BinaryTreeNode *> q;
        // 1、根节点进队列
        // 2、队列不为空，出队头节点，并且把左右节点入队
        // 3、直到队列为空结束
        if (node == nullptr)
            return;
        q.push(node);
        while (!q.empty()) {
            cout << q.front()->data << "->";
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    }

    // 销毁二叉树
    void destory(BinaryTreeNode *node) {
        if (node == nullptr)
            return;
        destory(node->right);
        destory(node->left);
        delete node;
    }

    ~BinaryTree() {
        destory(root);
    }
};

void BinaryTree::insert_left(BinaryTreeNode *root, int value) {
    if (root == nullptr)
        return;
    BinaryTreeNode node(value);
    root->left = &node;
}

void BinaryTree::insert_right(BinaryTreeNode *root, int value) {
    if (root == nullptr)
        return;
    BinaryTreeNode node(value);
    root->right = &node;
}

void testTree() {
    BinaryTreeNode *root = new BinaryTreeNode(123);
    BinaryTreeNode *A = new BinaryTreeNode(12);
    BinaryTreeNode *B = new BinaryTreeNode(11);
    BinaryTreeNode *C = new BinaryTreeNode(4);
    BinaryTreeNode *D = new BinaryTreeNode(3);
    BinaryTree binaryTree(root);
    root->left = A;
    root->right = B;
    B->right = C;
    A->right = D;

    // binaryTree.preOrder(root);
    // cout << endl;
    // binaryTree.inOrder(root);
    // cout << endl;
    // binaryTree.postOrder(root);
    // cout << endl;
    // cout << binaryTree.getNodeSize(root);
    binaryTree.levelOrder(root);
}

// 二叉树的概念题目及一些结论

// 根据遍历顺序来重建二叉树


// 算法实验报告
// 图书管理系统



class Book {
private:
    double price;
    string name;
    string author;
    int isbn;
    bool isBorrowed;
public:
    Book(double _price, string _name, string _author, int _isbn) :
            price(_price), name(_name), author(_author), isbn(_isbn), isBorrowed(false) {}

    string getName() { return name; }

    string getAuthor() { return author; }

    double getprice() { return price; }

    double getIsbn() { return isbn; }

    void setBorrowStatue(bool b) { isBorrowed = b; }
    // ...
};

struct Library {
private:
    vector<Book> books;

    // double price, string name, string author, int isbn
    bool checkBook(Book &mybook) {
        for (auto &book: books) {
            if (book.getIsbn() == mybook.getIsbn() || book.getName() == mybook.getName()) {
                return false;
            }
        }
        return true;
    }

public:
    void addBook(Book &book) {
        // 特殊情况
        // isbn、书名相同的情况下怎么处理
        if (checkBook(book)) {
            books.push_back(book);
        }
    }

    Book deleteBook_isbn(int isbn) {
        for (auto &book: books) {
            if (book.getIsbn() == isbn) {
                return book;
            }
        }
    }

    Book deleteBook_name(string name) {
        for (auto &book: books) {
            if (book.getName() == name) {
                return book;
            }
        }
    }

    void findBook_name(string name) {
        for (auto &book: books) {
            if (book.getName() == name) {
                cout << "为您找到了" << name << endl;
                printBookInfo(book);
            }
        }
    }

    Book findBook_isbn(int isbn) {
        for (auto &book: books) {
            if (book.getIsbn() == isbn) {
                return book;
            }
        }
    }

    void printBookInfo(Book &book) {
        cout << "书名：" << book.getName() << endl;
        cout << "作者：" << book.getAuthor() << endl;
        cout << "价格：" << book.getprice() << endl;
        cout << "ISBN：" << book.getIsbn() << endl;
    }

};



//根据位置查询图书信息
//根据图书ID查询图书信息
//根据图书名称查询图书信息
//根据位置删除图书信息
//根据图书ID删除图书信息
//根据图书名称删除图书信息



//int main() {
//    Library library;
//    Book* book = new Book(23.1,"《毛泽东选集》","毛泽东",120384);
//
//    library.addBook(*book);
//    library.findBook_name("《毛泽东选集》");
//
//    return 0;
//}

// 寒假任务：做一个图书管理系统（结合C++作为基础语言(C++11 学完之后)、使用Qt制作图形化界面(花费1~2天进行进行基础的学习)）
// 可以模拟该项目：
// https://hzgdemo.app.hzgcloud.cn/library/%E7%AE%A1%E7%90%86%E5%91%98%E9%A6%96%E9%A1%B5




class Solution {
public:
    // 暴力做法
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        // 对一个二维数组进行操作
        // 如果一个单元格周围存在单元格缺失的情况，
        // 则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4
        // 个单元格的平均值）
        // 通过双层循环得到每一个点，来充当中心点
        vector<vector<int>> imgtemp = img;
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                centersSmooth(imgtemp, img, i, j);
            }
        }
        return img;
    }

    void centersSmooth(const vector<vector<int>> imgtemp, vector<vector<int>> &img, int i, int j) {
        // 判断是否为有效位置
        int range = img.size();
        int sum = 0;
        int count = 0;
        for (int index1 = i - 1; index1 <= i + 1; index1++) {
            for (int index2 = j - 1; index2 <= j + 1; index2++) {
                if (index1 > 0 && index1 < range && index2 > 0 &&
                    index2 < range) {
                    sum += imgtemp[index1][index2];
                    cout << index1 << " " << index2 << endl;
                    count++;
                }
            }
        }
        int average = sum / count;
        // cout << sum << " " << average << endl;
        img[i][j] = average;
    }
};


// 左闭右开的二分查找算法
// [left,right)
int binarysearch(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int middle = left + (right - left) / 2;     // 重要，防止溢出
        if (nums[middle] > target)
            right = middle;
        else if (nums[middle] < target)
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

// 由于进行小型比赛，为了提前适应，接下来对C++中的STL进一步熟悉，并且掌握一些小技巧（万能头文件...）

void testSTL() {
    vector<int> v;

}

// pair<string,int>p("aaa",1);



//int main() {
//    vector<int>v = {2,8,7,3,5,4};
//    for(int i : v) {
//        cout << i << " ";
//    }
//
//    return 0;
//}

// 学习竞赛的基础知识：软件的操作、程序的简化方式...
// 例如： #include <bits/stdc++.h> ：该头文件可以...

// 概率论的第五章节需要完成
// 英语六级单词

#include <bits/stdc++.h>


#include <cmath>  // 包含 log2 函数

int binaryDigitsCount(int n) {
    if (n == 0) return 1;  // 特殊情况处理：0的二进制表示为1位
    return static_cast<int>(std::floor(std::log2(n))) + 1;
}

class Solution100 {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        // 写道算法题醒醒脑😁
        // 白色的车：'R'
        // 还可能会有白色的象：'B',黑色的卒：'p'
        // 空方快：'.'
        int ans = 0;
        int R_x, R_y = 0;
        vector<vector<int>> goalgrid;
        vector<vector<int>> elepgrid;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'p')
                    goalgrid.push_back({i, j});
                else if (board[i][j] == 'R') {
                    R_x = i;
                    R_y = j;
                } else if (board[i][j] == 'B')
                    elepgrid.push_back({i, j});
            }
        }
        // 现在将卒、象和车都分离开来了~

        return ans;
    }
};

class Solution200 {
public:
    int recursion(vector<int> &nums, int begin, int end) {
        // 我要1在前，n在后的正常情况
        int n = nums.size();
        return begin + n - 1 - end;
    }

    int semiOrderedPermutation(vector<int> &nums) {
        int n = nums.size();
        int begin, end = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                begin = i;
            } else if (nums[i] == n) {
                end = i;
            }
        }
        if (begin > end) {
            int ans = begin - end;
            return min(ans + recursion(nums, end, end + 1),
                       ans + recursion(nums, end + 1, begin));
        }
        return recursion(nums, begin, end);
    }
};

class Solution120 {
public:
    int minAnagramLength(string s) {
        // 将s的同位字符串输出
        // 分成两截，如果相互不是t和t'的关系的话，返回s的原长
        // 否则，返回s的（1/2）原长
        // 怎么判断是否成关系呢？
        // 也就是如果按照字典序排列的话，若二者相同则是，否则不是
        int n = s.size();
        string str1 = s.substr(0, n / 2 - 1);
        string str2 = s.substr(n / 2, n - 1);
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        cout << str1 << " " << str2;
        if (str1 == str2)
            return n / 2;
        else
            return n;
    }
};

class Solution10 {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        // 会产生(n - 1)个长度为2的子字符串
        vector<string> strarr(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                return true;
            string str = "";
            str += s[i];
            str += s[i + 1];
            for (auto t: strarr) {
                string temp = str;
                reverse(temp.begin(), temp.end());
                if (temp == t) {
                    return true;
                }
            }
            strarr.push_back(str);
        }
        return false;
    }
};

//int main() {
//    int number = 10;  // 给定的整数
//    vector<int>v(number,0);
//
//
//    Solution10 s;
//    cout << s.isSubstringPresent("abcba");

//    std::cout << "Number of binary digits in " << number << " is: " << binaryDigitsCount(number) << std::endl;
//    vector<int>v;
//    priority_queue<int>pq;
//    map<string,int> m;
//    m.insert(make_pair("sss",222));

//    vector<vector<int>> goalgrid;
//    goalgrid.push_back({1,2});

// set不允许元素重复，如果有重复就会被忽略，但multiset允许
// sort(v.begin(),v.end());
// cout << pow(10,0.49);

//    string s = "adaghhdg";
//    string temp;
//    for(auto i : s) {
//        if(temp.find(i) == string::npos) {
//            temp += i;
//        }
//    }
//    cout << temp;
// string temp = "adgh"
//    for(int i = 1;i <= 40;i++) {
//        if(i++ % 5 == 0) {
//            if(++i % 8 == 0) {
//                cout << i;  // 打印 i
//            }
//        }
//    }


// Solution120 s;
// cout << s.minAnagramLength("abba");
//    string s = "asfgh";
//    string t = s.substr(0,2);
//    cout << t;


// 编译器，你好好~


//    return 0;
//}

#include <chrono>

// 快速排序
int partition(vector<int> &nums, int left, int right) {
    int base = nums[left];
    while (right > left) {
        while (right > left && nums[right] >= base) {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= base) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = base;
    return left;    // 返回base的索引
}

void quickSort(vector<int> &nums, int left, int right) {
    if (left < right) {
        int pos = partition(nums, left, right);
        quickSort(nums, left, pos - 1);
        quickSort(nums, pos + 1, right);
    }
}

void printArray(vector<int> &v) {
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
}

void caluTime_quick_sort() {
    auto start = std::chrono::high_resolution_clock::now();

    // 要计时的代码段放在这里
    vector<int> v = {3, 4, 6, 1, 2, 4, 7};
    quickSort(v, 0, v.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "quick_sort runned time: " << elapsed.count() << " s.\n";
    printArray(v);
}

void insertSort(vector<int> &nums) {
    int temp = 0;
    int n = nums.size();
    int index = 0;
    // 个数 == 1/0 直接退出
    if (n == 1 || n == 0) {
        return;
    }
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            temp = nums[i];
            // 插入 + 向后移动
            for (index = i - 1; nums[index] > temp && index >= 0; index--) {
                nums[index + 1] = nums[index];
            }
            nums[index + 1] = temp;
        }
    }
}

void caluTime_insert_sort() {
    auto start = std::chrono::high_resolution_clock::now();

    // 要计时的代码段放在这里
    vector<int> v = {3, 4, 6, 1, 2, 4, 7};
    insertSort(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "insert_sort runned time: " << elapsed.count() << " s.\n";
    printArray(v);
}

void bubbleSort(vector<int> &nums) {
    for (int i = nums.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

void caluTime_bubble_sort() {
    auto start = std::chrono::high_resolution_clock::now();

    // 要计时的代码段放在这里
    vector<int> v = {3, 4, 6, 1, 2, 4, 7};
    bubbleSort(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "bubble_sort runned time: " << elapsed.count() << " s.\n";
    printArray(v);
}

// difficult
// 希尔排序是直接插入排序的改进
void shellSort(vector<int> &nums) {
    int index = 0;
    for (int d = nums.size() / 2; d >= 1; d /= 2) {
        for (int i = d; i < nums.size(); i += d) {
            if (nums[i] < nums[i - d]) {
                // 进行移动
                // swap(nums[i],nums[i - d]);
                int temp = nums[i];
                // 此方式借鉴了直接插入排序，节约代码，方便使用
                for (index = i - d; nums[index] > temp && index >= 0; index -= d) {
                    nums[index + d] = nums[index];
                }
                nums[index + d] = temp;
            }
        }
    }
}


void caluTime_shell_sort() {
    auto start = std::chrono::high_resolution_clock::now();

    // 要计时的代码段放在这里
    vector<int> v = {3, 4, 6, 1, 2, 4, 7};
    shellSort(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "shell_sort runned time: " << elapsed.count() << " s.\n";
    printArray(v);
}

//int main() {
//    // 进行快排、计算时间、打印结果
//    caluTime_quick_sort();
//    cout << endl;
//    // 进行冒泡排序、计算时间、打印结果
//    caluTime_bubble_sort();
//    cout << endl;
//    caluTime_insert_sort();
//    cout << endl;
//    // 进行希尔排序、计算时间、打印结果
//    caluTime_shell_sort();
//    cout << endl;
//
//    return 0;
//}
//    sort可以让字符串按照字典序排序
//    vector<string> votes = {"abs", "asc", "abd"};
//    sort(votes.begin(), votes.end());
//    for (auto i: votes) {
//        cout << i << " ";
//    }


// 链表的增删查改


// 实现二分查找
// 1.递归
int binarySearch_recursion(vector<int> &nums, int left, int right, int targrt) {
    if (left <= right) {
        int mid = left + (right - left) / 2;    // 遇到数值较大的情况，相减可以防止超出范围
        if (nums[mid] == targrt)
            return mid;
        else if (nums[mid] > targrt)
            return binarySearch_recursion(nums, left, mid - 1, targrt);
        else
            return binarySearch_recursion(nums, mid + 1, right, targrt);
    }
    return -1;
}

// 2.迭代
int binarySearch_iterate(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;    // 遇到数值较大的情况，相减可以防止超出范围
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    // 表示无该数字
    return -1;
}

void createNext(vector<int> &next, string t) {
    // 0 0 ? ? ? ? ?
    int j = 0;
    next[2] = 1;
    for (int i = 2; i < next.size(); i++) {
        while (t[i] != t[j] && j > 0) {
            j = next[j + 1];
            if (t[i] == t[j])
                j++;
        }
        next[i] = j;
    }
}

//bool KMP(string s, string t) {
//    // 进行字符串的匹配
//    // s : 主串
//    // t : 字串
//    int n = t.size();
//    vector<int> next(n + 1, 0);
//    createNext(next, t);
//
//
//}

// 字符串T=“aabaaf”，我们求一下T的前缀表(用一个数组名为next的数组表示)
// next:


string binary(int x) {
    string s;
    while (x) {
        s.push_back('0' + (x & 1));
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}


typedef struct Lnode {
    Lnode *next;
    int data;

    Lnode(int value) : data(value), next(nullptr) {}
} Lnode;

typedef Lnode *Linklist;
// Linklist 是 node结构体的指针

// 设计一个算法delminnode(Linklist* &L)，
// 在带头结点的单链表L中删除所有结点值最小的结点(可能有多个结点值最小的结点）
// 此方法较为复杂，可能还有简化的余地~
void delminnode(Linklist &head) {
    if (!head || !(head->next)) {
        return;
    }
    // 中间变量 node，防止污染 head
    Lnode *node = head->next;
    int minvalue = node->data;
    // 找到最小结点（遍历）
    while (node != nullptr) {
        minvalue = min(minvalue, node->data);
        node = node->next;
    }
    node = head;
    while (node->next != nullptr) {
        if (node->next->data == minvalue) {
            // 删除操作
            Linklist temp = node->next;
            node->next = temp->next;
        } else {
            node = node->next;
        }
    }
}

void insertNode(Linklist &head, int value) {
    Lnode *newnode = new Lnode(value);
    if (!head || !head->next) { // 如果链表为空（包括头结点），则创建头结点
        if (!head) {
            head = new Lnode(0); // 创建一个带头结点的空链表
        }
        head->next = newnode;
    } else {
        Lnode *node = head;
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = newnode;
    }
}

void print(Linklist &head) {
    Lnode *node = head->next;
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

//int main() {
//    Linklist L = new Lnode(0);
//    insertNode(L, 100);
//    insertNode(L, 22);
//    insertNode(L, 46);
//    insertNode(L, 1);
//    insertNode(L, 99);
//    insertNode(L, 1);
//    print(L);
//    cout << endl;
//    delminnode(L);
//    print(L);
//    return 0;
//}

//int main() {
//    string ans = "";
//    ans = ans + 'c' + 'c';
//    return 0;
//}

//int main() {
//    string s = "aaa";
//    // 创建字符串
//    cout << s[2];
//    return 0;
//}


// 1.返回值为A和A&的区别
// 2.this指针的含义


// 日期类
class Date {
private:
    int year;
    int month;
    int day;
    // 获取月份天数
    int montharr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int getMonthday(int _year, int _month) {
        if (_month == 2 && (((_year % 4 == 0) && (_year % 100 != 0)) || ((_year % 100 == 0) && (_year % 400 == 0))))
            // 闰年
            return 29;
        return montharr[_month];
    }

public:
    // 构造函数
    Date(int _year = 0, int _month = 0, int _day = 0) {
        if (_month > 0 && _day > 0 && _year > 0) {
            year = _year;
            month = _month;
            day = _day;
        } else {
            cout << "日期非法！" << endl;
        }
    }

    // 打印日期
    void printDate();

    // +/- 日期
    Date &operator-=(int _day);
    Date &operator+=(int _day);
    Date operator+(int _day);
    Date operator-(int _day);
    Date &operator--();
    Date &operator++();
    // 日期比较
    bool operator>(const Date &d);
    bool operator>=(const Date &d);
    bool operator<(const Date &d);
    bool operator<=(const Date &d);
    bool operator==(const Date &d);
    bool operator!=(const Date &d);
    // 日期 - 日期 : 返回相差天数
    int operator-(const Date& d);


};

void Date::printDate() {
    cout << year << "年" << month << "月" << day << "日" << endl;
}


// 如何调整 + 日期？
// 1.若日已满，则日减去当前月的天数，月加一。
// 2.若月已满，则将年加一，月置为1。
// 反复执行1和2，直到日期合法为止。

Date &Date::operator+=(int _day) {
    // 负数：复用operator-=
    if (_day < 0) {
        *this -= _day;
    } else {
        day += _day;
        int curmonth = getMonthday(year, month);
        while (day > curmonth) {
            day -= curmonth;
            month++;
            if (month > 12) {
                year++;
                month = 1;
            }
        }
    }
    return *this;
}

Date Date::operator+(int _day) {
    Date temp(year, month, day);
    temp += _day;
    return temp;
}

Date &Date::operator++() {
    *this += 1;
    return *this;
}

// 如何调整 - 日期：
// 1.若日为负数，则月减一。
// 2.若月为0，则年减一，月置为12。
// 3.日加上当前月的天数。
Date &Date::operator-=(int _day) {
    if (_day < 0) {
        *this += -day;
    } else {
        day -= _day;
        while (day < 0) {
            month--;
            day += getMonthday(year, month);
            if (month < 1) {
                year--;
                month = 12;
            }
        }
    }
    return *this;
}

Date Date::operator-(int _day) {
    Date temp(*this);
    temp -= _day;
    return temp;
}

Date &Date::operator--() {
    *this -= 1;
    return *this;
}

bool Date::operator==(const Date &d) {
    return year == d.year && month == d.month && day == d.day;
}


bool Date::operator>(const Date &d) {
    if (year > d.year)
        return true;
    else {
        if (month > d.month)
            return true;
        else {
            if (day > d.month)
                return true;
        }
    }
    return false;
}

bool Date::operator>=(const Date &d) {
    return *this > d || *this == d;
}

bool Date::operator<(const Date &d) {
    if (year < d.year)
        return true;
    else {
        if (month < d.month)
            return true;
        else {
            if (day < d.month)
                return true;
        }
    }
    return false;
}

bool Date::operator<=(const Date &d) {
    return *this < d || *this == d;
}

bool Date::operator!=(const Date &d) {
    return !(*this == d);
}

int Date::operator-(const Date& d) {
    Date min = d;
    Date max = *this;
    int n = 0;
    if(*this < d) {
        min = *this;
        max = d;
    }
    while (min != max) {
        ++min;
        n++;
    }
    return n;
}


//int main() {
//    // B = C & (~A)
//    cout << (118 & (~22));
//    // 22 | 100 = 118
//    return 0;
//}


//int main() {
//    Date date1(2024, 12, 4);
//    Date date2(2025, 1, 13);
//    cout << (date1 > date2) << endl;
//    date1 -= 12;
//    cout << (date1 - date2);
//    return 0;
//}





