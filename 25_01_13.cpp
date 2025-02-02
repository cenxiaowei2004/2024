//
// Created by cen on 2025/1/13.
//

#include <vector>

#include <bits/stdc++.h>

using namespace std;

//void swap(vector<int> &v, int x) {
//    int left = 0;
//    int right = v.size() - 1;
//    while (left < right) {
//        if (v[left] >= x && v[right] <= x)
//            swap(v[left++], v[right--]);
//        else if (v[left] < x)
//            left++;
//        else if (v[right] > x)
//            right--;
//        else {
//            right--;
//            left++;
//        }
//    }
//}

void testqueue() {
    queue<int> q;
    q.push(100);
    q.push(23);
    q.push(11);
    q.push(10330);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}


// 构建小堆
class Heap {

public:
    vector<int> v;
    int size;

    // 向下调整算法
    void adjustdown(int root, int n);

    // 向上调整算法
    void adjustup(int child);

    explicit Heap(vector<int> &nums) : v(nums), size(nums.size()) {
        initHeap(size);
    }

    // 构建小堆
    void initHeap(int n);

    // 增
    void push(int x);

    // 删
    void pop();

    // 打印数组
    void printv();

    // 堆顶数据
    int top();

    // 判空
    bool empty() const;

    // topk问题
    void topk(vector<int> &arr, int k) {
        vector<int> top(arr.begin(), arr.begin() + k);
        Heap temp(top);
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] > temp.top()) {
                temp.v[0] = arr[i];
                adjustdown(0, k);
            }
        }
        temp.printv();
    }
};


// 小堆的向下调整算法:前提是左右子堆是小堆，来构建小堆
void Heap::adjustdown(int root, int n) {
    int parent = root;
    int child = 2 * parent + 1;  // 子堆中的较小值(默认左子树较小)
    while (child < n) {
        if (child + 1 < n && v[child] > v[child + 1])
            child++;
        if (v[parent] > v[child]) {
            swap(v[parent], v[child]);
            parent = child;
            child = 2 * parent + 1;
        } else
            break;
    }
}

void Heap::adjustup(int child) {
    while (child > 0) {
        int parent = (child - 1) / 2;
        if (v[child] < v[parent]) {
            swap(v[child], v[parent]);
            child = parent;
        } else {
            break;
        }
    }
}

void Heap::initHeap(int n) {
    for (int i = (int) ((n - 2) / 2); i >= 0; i--) {
        adjustdown(i, n);
    }
}

void Heap::push(int x) {
    v.push_back(x);
    size++;
    adjustup(size - 1);
}

// 删除堆顶元素
void Heap::pop() {
    if (size <= 0) {
        cout << "当前堆中无数据！" << endl;
        return;
    }
    size--;
    swap(v[0], v[v.size() - 1]);
    adjustdown(0, size - 1);
}

void Heap::printv() {
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
}

int Heap::top() {
    return v[0];
}

bool Heap::empty() const {
    return size == 0;
}


//int main() {
//    int k = 6;
//    vector<int> arr = {47, 83, 12, 65, 34, 98, 27, 100};
//    vector<int> topk(arr.begin(),arr.begin() + k);
//    Heap h(arr);
//    h.topk(arr,k);
//
//    return 0;
//}




class Sort {
private:
    vector<int> nums;

    // 堆：下滤操作(大根堆)
    void Down(int root) {
        int parent = root;
        int child = 2 * parent + 1;
        // 默认左孩子为较大值
        while (child < nums.size()) {
            if (child + 1 < nums.size() && nums[child] < nums[child + 1])
                child++;
            if (nums[parent] < nums[child]) {
                swap(nums[parent], nums[child]);
                parent = child;
                child = 2 * parent + 1;
            } else {
                break;
            }
        }
    }

public:
    explicit Sort(vector<int> &v) : nums(v) {}

    // 打印数组
    void printnums() {
        for (int i: nums) {
            cout << i << " ";
        }
    };

    // 插入排序
    void InsertSort() {
        if (nums.size() <= 1)
            return;
        for (int i = 1; i < nums.size(); i++) {
            int j = i;
            // 因为前面已经有序
            while (j >= 0 && nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
    }

    // 希尔排序
    void ShellSort() {
        int gap = nums.size();
        while (gap > 0) {
            gap /= 2;
            for (int i = 0; i < nums.size(); i++) {
                int j = i;
                while (j - gap >= 0 && nums[j] < nums[j - gap]) {
                    swap(nums[j], nums[j - gap]);
                    j -= gap;
                }
            }
        }
    }

    // 选择排序(每次选出最小值)
    void SelectSort_single() {
        for (int i = 0; i < nums.size(); i++) {
            int min = i;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }
    }

    // 选择排序(每次选出最小值和最大值)
    void SelectSort_double() {
        int min = 0;
        int max = nums.size() - 1;
        while (min < max) {
            int minindex = min;
            int maxindex = min;
            for (int i = min; i <= max; i++) {
                if (nums[minindex] > nums[i])
                    minindex = i;
                if (nums[maxindex] < nums[i])
                    maxindex = i;
            }
            swap(nums[maxindex], nums[max]);
            if (min == maxindex) {
                maxindex = minindex;
            }
            swap(nums[minindex], nums[min]);
            min++;
            max--;
        }
    }

    // 堆排序(升序：建立大根堆)
    void HeapSort() {
        for (int i = (int) ((nums.size() - 1) / 2); i >= 0; i--) {
            Down(i);
        }
    }

    // 冒泡排序
    void BubbleSort() {
        bool flag = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    flag = false;
                }
            }
            if (flag)
                break;
        }
    }

    // 坑位法
    int QuickPartSort(int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] > pivot)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] < pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    //三数取中
    int GetMidIndex(int left, int right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[left]) {
            if (nums[mid] < nums[right])
                return mid;
            else if (nums[left] > nums[right])
                return left;
            else
                return right;
        } else {
            if (nums[mid] > nums[right])
                return mid;
            else if (nums[left] > nums[right])
                return right;
            else
                return left;
        }
    }

    // 快速排序(以nums[0]为pivot)
    void QuickSort(int left, int right) {
        if (left < right) {
            int midindex = GetMidIndex(left, right);
            swap(nums[midindex], nums[left]);
            int index = QuickPartSort(left, right);
            QuickSort(left, index - 1);
            QuickSort(index + 1, right);
        }
    }


    void MergePartSort(int left, int right, vector<int> &temp) {
        if (left >= right)
            return;
        int i = left;
        // 分割
        int mid = left + (right - left) / 2;    // 防止整型溢出
        MergePartSort(left, mid, temp);
        MergePartSort(mid + 1, right, temp);
        // 合并
        int begin1 = left, end1 = mid;
        int begin2 = mid + 1, end2 = right;
        while (begin1 <= end1 && begin2 <= end2) {
            if (nums[begin1] < nums[begin2])
                temp[i++] = nums[begin1++];
            else
                temp[i++] = nums[begin2++];
        }
        while (begin1 <= end1)
            temp[i++] = nums[begin1++];
        while (begin2 <= end2)
            temp[i++] = nums[begin2++];
        // 将临时数组中的排序结果复制回原数组
        for (int j = left; j <= right; ++j) {
            nums[j] = temp[j];
        }
    }

    // 归并排序
    void MergeSort(int left, int right) {
        vector<int> temp(right + 1);
        MergePartSort(left, right, temp);
    }

    // 计数排序
    void CountSort() {
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i: nums) {
            if (i > max)
                max = i;
            if (i < min)
                min = i;
        }
        vector<int> Countarr(max - min + 1);
        for (int i: nums) {
            Countarr[i - min]++;
        }
        int index = 0;
        for (int i = 0; i < Countarr.size(); i++) {
            while (Countarr[i] > 0) {
                nums[index++] = i + min;
                Countarr[i]--;
            }
        }
    }


};

//BSTree结点类
template<class K>
class BSTreeNode {
public:
    K key;                 //结点值
    BSTreeNode<K> *left;   //左指针
    BSTreeNode<K> *right;  //右指针
public:
    //构造函数
    explicit BSTreeNode(const K &key = 0) : key(key), left(nullptr), right(nullptr) {}
};

// BSTree类
template<class K>
class BSTree {
public:
    // 根结点
    BSTreeNode<K> *root;
public:
    //构造函数
    BSTree() : root(nullptr) {}

    //拷贝构造函数
    BSTree(const BSTree<K> &tree) {
        if (tree == nullptr)
            return;
        BSTreeNode<K> newroot = new BSTreeNode<K>(tree.root->key);
        newroot.left = tree.root->left;
        newroot.right = tree.root->right;
        this->root = newroot;
    }

    //赋值运算符重载函数:深拷贝
    //现代写法
    BSTree<K> &operator=(BSTree<K> tree) //编译器接收右值的时候自动调用拷贝构造函数
    {
        swap(root, tree.root);  //交换这两个对象的二叉搜索树
        return *this;           //支持连续赋值
    }

    //释放树中结点
    void destory(BSTreeNode<K> *rt) {
        if (rt == nullptr) //空树无需释放
            return;
        destory(rt->left); //释放左子树中的结点
        destory(rt->right); //释放右子树中的结点
        delete rt; //释放根结点
    }

    //析构函数
    ~BSTree() {
        destory(root);
        delete root;
    }

    bool insertPart(const K &key, BSTreeNode<K> *&rt) {
        if (rt == nullptr) {
            rt = new BSTreeNode<K>(key);
            return true;
        } else if (key < rt->key)
            return insertPart(key, rt->left);
        else if (key > rt->key)
            return insertPart(key, rt->right);
        else
            return false;
    }

    //插入函数
    bool insert(const K &key) {
        return insertPart(key, root);
    }

    bool erasePart(const K &key, BSTreeNode<K> *&rt) {
        if (rt == nullptr) {
            return false;
        } else if (key < rt->key)
            return erasePart(key, rt->left);
        else if (key > rt->key)
            return erasePart(key, rt->right);
            // 找到了该结点
        else {
            if (rt->left == nullptr && rt->left == nullptr) {
                delete rt;
                rt = nullptr;
            } else if (rt->left != nullptr && rt->left == nullptr) {
                BSTreeNode<K> *temp = rt;
                rt = rt->left;
                delete temp;
            } else if (rt->left == nullptr && rt->right != nullptr) {
                BSTreeNode<K> *temp = rt;
                rt = rt->right;
                delete temp;
            } else {
                // 重要
                // 寻找右子树中最小的节点（即后继节点）
                BSTreeNode<K> *minright = rt->right;
                BSTreeNode<K> *minparent = rt;
                while (minright->left != nullptr) {
                    minparent = minright;
                    minright = minright->left;
                }
                // 将后继节点的数据复制到当前节点
                rt->key = minright->key;
                // 删除后继节点
                // 此时minRight的_left为空
                if (minright == minparent->left) {
                    minparent->left = minright->right;

                } else {
                    minparent->right = minright->right;
                }
                delete minright;
            }
            return true;
        }
    }

    //删除函数
    bool erase(const K &key) {
        return erasePart(key, root);
    }

    BSTreeNode<K> *searchPart(const K &key, BSTreeNode<K> *&rt) {
        if (rt == nullptr || rt->key == key)
            return rt;
        else if (key < rt->key)
            return searchPart(key, rt->left);
        else if (key > rt->key)
            return searchPart(key, rt->right);
    }

    //查找函数
    BSTreeNode<K> *search(const K &key) {
        return searchPart(key, root);
    }

    //中序遍历
    void inorderPart(BSTreeNode<K> *&rt) {
        if (rt == nullptr)
            return;
        inorderPart(rt->left);
        cout << rt->key << " ";
        inorderPart(rt->right);
    }

    void inOrder() {
        inorderPart(root);
        cout << endl;
    }

};

// AVLTree结点类
template<class K>
class AVLTreeNode {
private:
    K key;                  // 结点值
    AVLTreeNode<K> *left;   // 左指针
    AVLTreeNode<K> *right;  // 右指针
    int balance;            // 平衡因子 = -1/0/1
public:
    //构造函数
    explicit AVLTreeNode(const K &key = 0) : key(key), left(nullptr), right(nullptr), balance(0) {}
};

template<class K>
class AVLTree {
private:
    AVLTreeNode<K> *root;
public:
    explicit AVLTree() : root(nullptr) {}

    int getheight(AVLTreeNode<K> *rt) {
        if (rt == nullptr)
            return 0;
        return max(getheight(rt->left), getheight(rt->right));
    }

    int getbalance(AVLTreeNode<K> *rt) {
        return getheight(rt->left) - getbalance(rt->right);
    }

    bool insertPart(AVLTreeNode<K> *rt, const K &key) {
        if (root == nullptr) {
            root = new AVLTreeNode<K>(key);
            return true;
        } else if (root->key < key)
            return insertPart(rt->right, key);
        else if (root->key > key)
            return insertPart(rt->left, key);
        else
            return false;
    }

    bool insert(const K &key) {
        return insertPart(root, key);
    }

};


//void testmap() {
//    map<string, int> mapcount;
//    mapcount.insert(make_pair("zhangsan",1));
//    mapcount.insert(make_pair("lisi",2));
//    mapcount.insert(make_pair("wangwu",3));
//    mapcount.insert(make_pair("zhaoliu",4));

//    auto it = mapcount.find("lisi");
//    if(it != mapcount.end())
//        cout << it->second << endl;
//    cout << endl;
//    for(auto m : mapcount) {
//        cout << m.first << ":" << m.second << endl;
//    }

//    vector<string> fruits = {"西瓜", "香蕉", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "哈密瓜", "西瓜"};
//    for (string fruit: fruits) {
//            mapcount[fruit]++;
//    }
//
//    for(auto i : mapcount) {
//        cout << i.first << ":" << i.second << endl;
//    }
//}

// 有意思的代码
class Solution {
public:
    string reverseStr(string s, int k) {
        return [&]() {
            for (int i = 0; i < s.size(); i += 2 * k)
                reverse(s.begin() + i, s.begin() + min(i + k, (int) s.size()));
            return s;
        }();
    }
};

//class A {
//public:
//    explicit A(int num) : a(num) {}
//    A(const A& a) : a = a.
//private:
//    int a;
//};


class Solution01 {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        // 问题等价于给一个二维数组ops，求重叠部分的面积
        if (ops.size() == 0)
            return m * n;
        int minc = ops[0][0];
        int minr = ops[0][1];
        for (int i = 1; i < ops.size(); i++) {
            // 4种情况：
            if (ops[i][0] < minc && ops[i][1] < minr) {
                minc = ops[i][0];
                minr = ops[i][1];
            } else if (ops[i][0] < minc && ops[i][1] > minr)
                minc = ops[i][0];
            else if (ops[i][0] > minc && ops[i][1] < minr)
                minr = ops[i][1];
            else
                continue;
        }
        return minc * minr;
    }
};


namespace cl {
    class string {
    public:
        typedef char *iterator;

        iterator begin() {
            return _str; //返回字符串中第一个字符的地址
        }

        iterator end() {
            return _str + _size; //返回字符串中最后一个字符的后一个字符的地址
        }

        //构造函数
        string(const char *str = "") {
            _size = strlen(str); //初始时，字符串大小设置为字符串长度
            _capacity = _size; //初始时，字符串容量设置为字符串长度
            _str = new char[_capacity + 1]; //为存储字符串开辟空间（多开一个用于存放'\0'）
            strcpy(_str, str); //将C字符串拷贝到已开好的空间
        }

        //交换两个对象的数据
        void swap(string &s) {
            //调用库里的swap
            ::swap(_str, s._str); //交换两个对象的C字符串
            ::swap(_size, s._size); //交换两个对象的大小
            ::swap(_capacity, s._capacity); //交换两个对象的容量
        }

        //拷贝构造函数（现代写法）
        string(const string &s)
                : _str(nullptr), _size(0), _capacity(0) {
            cout << "string(const string& s) -- 深拷贝" << endl;

            string tmp(s._str); //调用构造函数，构造出一个C字符串为s._str的对象
            swap(tmp); //交换这两个对象
        }

        //赋值运算符重载（现代写法）
        string &operator=(const string &s) {
            cout << "string& operator=(const string& s) -- 深拷贝" << endl;

            string tmp(s); //用s拷贝构造出对象tmp
            swap(tmp); //交换这两个对象
            return *this; //返回左值（支持连续赋值）
        }

        //析构函数
        ~string() {
            delete[] _str;  //释放_str指向的空间
            _str = nullptr; //及时置空，防止非法访问
            _size = 0;      //大小置0
            _capacity = 0;  //容量置0
        }

        //[]运算符重载
        char &operator[](size_t i) {
            assert(i < _size); //检测下标的合法性
            return _str[i]; //返回对应字符
        }

        //改变容量，大小不变
        void reserve(size_t n) {
            if (n > _capacity) //当n大于对象当前容量时才需执行操作
            {
                char *tmp = new char[n + 1]; //多开一个空间用于存放'\0'
                strncpy(tmp, _str, _size + 1); //将对象原本的C字符串拷贝过来（包括'\0'）
                delete[] _str; //释放对象原本的空间
                _str = tmp; //将新开辟的空间交给_str
                _capacity = n; //容量跟着改变
            }
        }

        //尾插字符
        void push_back(char ch) {
            if (_size == _capacity) //判断是否需要增容
            {
                reserve(_capacity == 0 ? 4 : _capacity * 2); //将容量扩大为原来的两倍
            }
            _str[_size] = ch; //将字符尾插到字符串
            _str[_size + 1] = '\0'; //字符串后面放上'\0'
            _size++; //字符串的大小加一
        }

        //+=运算符重载
        string &operator+=(char ch) {
            push_back(ch); //尾插字符串
            return *this; //返回左值（支持连续+=）
        }

        //返回C类型的字符串
        const char *c_str() const {
            return _str;
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity;
    };
}

//
//void test() {
//    vector<int> v{1, 2, 3, 5};
//    // 左值引用
//    int a = 100;
//    int &b = a;
//    // 右值引用
//    int &&c = 100;
//    const int &d = 100;
//    int &&e = move(a);
//}


//String operator+(const String &s) {
//    char *pTemp = new char[strlen(_str) + strlen(s._str) + 1];
//    strcpy(pTemp, _str);
//    strcpy(pTemp + strlen(_str), s._str);
//    String strRet(pTemp);
//    return strRet;
//}


int main() {

    int a = 100;
    int b = 200;
    decltype(a + b) c = 300;

    cout << typeid(c).name() << endl;   // i


    // test();

}

//int main() {
//    unordered_map<int,int> map;
//    set<int> s;
//    s.insert(100);
//    s.insert(23);
//    s.insert(55);
//    s.insert(11);
//    auto it = s.begin();
//    while(it != s.end()) {
//        cout << *it << " ";
//        it++;
//    }
//    return 0;
//}

//int main() {
//    BSTree<int> bsTree;
//    bsTree.insert(100);
//    bsTree.insert(23);
//    bsTree.insert(10);
//    bsTree.insert(56);
//    bsTree.insert(999);
//    bsTree.insert(1);
//    bsTree.insert(19);
//
//    bsTree.inOrder();
//    bsTree.erase(23);
//    bsTree.erase(999);
//    bsTree.inOrder();
//
//    if (bsTree.search(100) == nullptr)
//        cout << "未找到" << endl;
//    else
//        cout << "找到了" << endl;
//    return 0;
//}


// Linux + 数据库

//int main() {
//
//    return 0;
//}


// 树的不同种类
// 哈希...


// 😟

//int main() {
//    vector<int> v = {5, 2, 8, 4, 6, 99, 1};
//    Sort sort(v);
//    // sort.InsertSort();
//    // sort.ShellSort();
//    // sort.SelectSort_double();
//    // sort.HeapSort();
//    // sort.BubbleSort();
//    sort.QuickSort(0, v.size() - 1);
//    // sort.MergeSort(0, v.size() - 1);
//    sort.CountSort();
//    sort.printnums();
//    return 0;
//}

//void Heap::adjustdown(int root) {
//    int parent = root;
//    int child = 2 * parent + 1;  // 子堆中的较小值(默认左子树较小)
//    while (child < v.size()) {
//        if (v[child] > v[child + 1])
//            child++;
//        if (v[parent] > v[child]) {
//            swap(v[parent], v[child]);
//            adjustdown(child);
//        } else
//            break;
//    }
//}

