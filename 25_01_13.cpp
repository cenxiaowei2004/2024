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
    void topk(vector<int>& arr,int k) {
        vector<int> top(arr.begin(),arr.begin() + k);
        Heap temp(top);
        for(int i = k;i < arr.size();i++) {
            if(arr[i] > temp.top()) {
                temp.v[0] = arr[i];
                adjustdown(0,k);
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


int main() {
    int k = 6;
    vector<int> arr = {47, 83, 12, 65, 34, 98, 27, 100};
    vector<int> topk(arr.begin(),arr.begin() + k);
    Heap h(arr);
    h.topk(arr,k);

    return 0;
}

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

