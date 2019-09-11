/*************************************************************************
	> File Name: 3.succeed.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月09日 星期一 09时31分08秒
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
    int a;
    A() = default;
};

struct B : A {
    int x, y, z;
    B(int _x) : x(_x), y(_x), z(_x) {};
    B() = default;
};


int main() {
    B b;
    b.a = 100;
    cout << b.a << endl;
    B bb(1);
    B b2(2);


}
