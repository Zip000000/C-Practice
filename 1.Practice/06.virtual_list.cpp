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
    virtual void run() {}
};

class B : public A{
public:
    void run() {}

};


int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    return 0;
}
