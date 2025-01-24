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
            int midindex = GetMidIndex(left,right);
            swap(nums[midindex],nums[left]);
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
    BSTreeNode<K>* left;   //左指针
    BSTreeNode<K>* right;  //右指针
public:
    //构造函数
    explicit BSTreeNode(const K& key = 0) : key(key), left(nullptr), right(nullptr) {}
};

// BSTree类
template<class K>
class BSTree {
public:
    // 根结点
    BSTreeNode<K>* root;
public:
    //构造函数
    BSTree() : root(nullptr) {}

    //拷贝构造函数
    BSTree(const BSTree<K>& tree) {
        if(tree == nullptr)
            return;
        BSTreeNode<K> newroot = new BSTreeNode<K>(tree.root->key);
        newroot.left = tree.root->left;
        newroot.right = tree.root->right;
        this->root = newroot;
    }

    //赋值运算符重载函数:深拷贝
    //现代写法
    BSTree<K>& operator=(BSTree<K> tree) //编译器接收右值的时候自动调用拷贝构造函数
    {
        swap(root, tree.root);  //交换这两个对象的二叉搜索树
        return *this;           //支持连续赋值
    }

    //释放树中结点
    void Destory(BSTreeNode<K>* rt)
    {
        if (rt == nullptr) //空树无需释放
            return;

        Destory(rt->left); //释放左子树中的结点
        Destory(rt->right); //释放右子树中的结点
        delete rt; //释放根结点
    }
    //析构函数
    ~BSTree() {
        Destory(root);
        delete root;
    }

    //插入函数
    bool Insert(const K& key) {

    }

    //删除函数
    bool Erase(const K& key) {

    }

    //查找函数
    BSTreeNode<K>* Find(const K& key) {

    }

    //中序遍历
    void inorderPaet(BSTreeNode<K>* rt) {
        if(rt == nullptr)
            return;
        inorderPaet(rt->left);
        cout << rt->key << " ";
        inorderPaet(rt->right);
    }
    void InOrder() {
        inorderPaet(root);
        cout << endl;
    }

};


int main() {
    auto root = new BSTreeNode<int>(100);
    auto node2 = new BSTreeNode<int>(200);
    auto node3 = new BSTreeNode<int>(300);
    auto node4 = new BSTreeNode<int>(500);
    auto node5 = new BSTreeNode<int>(600);

    root->right = node2;
    root->left = node3;
    node3->right = node4;
    node4->left = node5;

    BSTree<int> bstree;
    bstree.root = root;
    bstree.InOrder();

    delete root;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    // delete node;
    return 0;
}


// Linux + 数据库


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

