/*************************************************************************
	> File Name: 01.return_improve.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月23日 星期二 13时29分24秒
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
public :
    A() {
        cout << "constructor" << endl;
    }
    A(const A &obj) {
        cout << "copy constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
private :


};

A func() {
    A temp;
    cout << &temp << endl;
    return temp;
}

int main() {
    A a(func());
    cout << &a << endl;
    
    return 0;
}
