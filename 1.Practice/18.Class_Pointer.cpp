/*************************************************************************
	> File Name: 18.Class_Pointer.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月07日 星期一 21时11分54秒
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
    virtual void say() {}
    int ind;
};

void (A::*func[3])() = {&A::say};
int main() {
    A a;
    int *p = &a.ind;
    (a.*func[0])();
    a.say();
    void (A::*f)() = a.say;
    return 0;
}
