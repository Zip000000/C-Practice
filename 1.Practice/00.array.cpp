/*************************************************************************
	> File Name: 00.array.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月27日 星期二 20时39分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

template<typename T>
class Array {
public:
    Array() {
        this->__size = 10;
        this->__cnt = 0;
        this->data = new T[this->__size];
    }
    Array(int n) {
        this->size = 2 * n;
    }
    void push_back(const T &a) {
        this->data[(this->__cnt)++] = a;
    }
    int size() {
        return this->__cnt;
    }
    T &operator[] (const int i) {
        return this->data[i];
    }

private:
    T *data;
    int __size, __cnt;
};

int main() {
    Array<int> a;
    a.push_back(9);
    cout << a.size() << endl;
    a.push_back(9);
    cout << a.size() << endl;
    
    vector<int> v(10);
    for (int i = 0; i < 20; i++) {
        v.push_back(i);
    }
    for (int i = 0; i < 20; i++) {
        cout << v[i] << endl;
    }
    //cout << v[5] << endl;
    
    return 0;
}
