/*************************************************************************
	> File Name: 000.test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 13时04分49秒
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
private:
    Point(int x, int y) : x(x), y(y) {}
    int x, y;
};
template<typename T>
class Array {
public :
    Array(size_t n = 100) : size(n) {
       this->data = new T[this->size];
        //this->data = (T *)calloc(sizeof(T), size);
    }
    Array(const Array<T> &obj) : size(obj.size) {
       this->data = new T[this->size];
        //this->data = (T *)calloc(sizeof(T), size);
        for (int i = 0; i < size; i++) {
            new(this->data + i) T(obj.data[i]);
            this->data[i] = obj.data[i];
        }
    }
    T &operator[](size_t ind) {
        return this->data[ind];
    }
    void output() {
        cout << "Array(" << this->size << ") = [";
        for (int i = 0; i < this->size; i++) {
            cout << " " << this->data[i];
        }
        cout << "]" <<endl;
    }
    ~Array() {
        delete[] this->data;
    }
private:
    T* data;
    size_t size;
};

int main() {
    Array<int> arr(20);
    for (int i = 0; i < 20; i++) arr[i] = i;
    Array<int> arr2(arr);
    arr[2] = 100;   
    arr.output();
    arr2.output();
    Array<Point> arr3;
    
    return 0;
}
