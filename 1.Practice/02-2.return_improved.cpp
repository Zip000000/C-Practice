/*************************************************************************
	> File Name: 02-2.return_improved.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 12时43分31秒
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

class A {
public:
    /*
    A() {
        cout << "默认 construct" << endl;
    }
    A(const A &a) {
        cout << "拷贝 construct" <<endl;
    }
    ~A() {
        cout << "析构" << endl;
    }
    */
    void set(int n) { this->data = n; }
    int get() { return this->data; }
private:
    int data;
};

A func() {
    A tmp_a;
    tmp_a.set(100);
    return tmp_a;
}

int main() {
    
    A a(func());
    A b(a);
    cout << "a : " << a.get() << endl;
    cout << "b : " << b.get() << endl;
    return 0;
}
