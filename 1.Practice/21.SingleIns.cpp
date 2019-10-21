/*************************************************************************
	> File Name: 21.SingleIns.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月15日 星期二 19时35分11秒
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

class SingleIns {
public:
    static SingleIns *get_Ins() {
        if (SingleIns::p != nullptr) return SingleIns::p;
        p = new SingleIns;
        return p;
    }
    ~SingleIns() { cout << "DES" << endl; }
private:
    SingleIns() { cout << "Ins Constructor" << endl; }
    SingleIns(SingleIns &s) {}
    SingleIns &operator=(const SingleIns &) {}
    static SingleIns *p;
};

SingleIns * SingleIns::p = nullptr;

int main() {
    {
    SingleIns *a = SingleIns::get_Ins();
    SingleIns *b = SingleIns::get_Ins();
    SingleIns *c = SingleIns::get_Ins();
    
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    }
    cout << "END" << endl;
    return 0;
}
