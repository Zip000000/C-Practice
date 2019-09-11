/*************************************************************************
	> File Name: 13.move.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 19时22分57秒
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

class Point {
public :
    Point(int x, int y) : x(x), y(y) {}
private :
    int x, y;
};

template<typename T>
class Array {
public:
    Array(size_t n = 100) : size(n) {
        cout << "Constructor" << endl;
        this->data = (T *)calloc(sizeof(T), size);
    }
    //原地构造 O(n)
    Array(const Array<T> &obj) : size(obj.size) {
        cout << "Copy Constructor" << endl;
        this->data = (T *)calloc(sizeof(T), size);
        for (int i = 0; i < size; i++) {
            new(this->data + i) T(obj.data[i]); //原地构造
        }   
    }
    //移动构造，你也不需要了就直接给我吧，反正你是右值。O(1)
    Array(Array<T> &&obj) : size(obj.size) {
        cout << "Move Constructor" << endl;
        this->data = obj.data;
        obj.data = nullptr;
        obj.size = 0;
    }
    T &operator[](size_t ind) {
        return this->data[ind];
    }
    Array<T> operator+(const Array<T> &obj) {
        Array<T> ret(this->size + obj.size);
        for (int i = 0; i < this->size; i++) {
            ret.data[i] = this->data[i];
        }
        for (int i = this->size; i < this->size + obj.size; i++) {
            ret.data[i] = obj.data[i - this->size];
        }
        return ret;
    }
    void output() {
        cout << "Array(" << size << ") = [";
        for (int i = 0; i < this->size; i++) cout << " " << this->data[i];
        cout << "]" << endl;
    }
    ~Array() {
        cout << "Destructor" << endl;
        delete[] this->data;
    }
private:
    T *data;
    size_t size;
};



int main() {
    Array<int> a(20), b(20);
    for (int i = 0; i < 20; i++) a[i] = i, b[i] = i;
    Array<int> c(a + b);

    return 0;
}
