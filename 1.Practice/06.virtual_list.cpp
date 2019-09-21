/*************************************************************************
	> File Name: 06.virtual_list.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月05日 星期一 14时09分08秒
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
    virtual void run() {
        cout << "A run" << endl;
    }
    virtual void run2() {
        cout << "A2 run" << endl;
    }
};

class B : public A{
public:
    void run() {
        cout << "B RUN " << endl;
    }
    void run2() {
        cout << "B2 RUN " << endl;
    }

};

typedef void (*func)();

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    
    B b;
    ((func **)&b)[0][0]();

    return 0;
}
