/*************************************************************************
	> File Name: 07.operator.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月22日 星期二 20时58分09秒
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

struct Data {
    Data(int x) : x(x) {}
    Data(int x, int y) : x(x), y(y) {}
    int x, y;
    Data operator+(Data &obj) {
        cout << "in" << endl;
        return Data(x + obj.x, y + obj.y);
    }
    void operator()(int a, int b) { cout << a << b << endl; }
    int operator*(int b) {
        return 100;
    }
    int operator,(int a) {}
};
/*
Data operator+(Data &a, Data &obj) {
    cout << "out" << endl;
    return Data(a.x + obj.x, a.y + obj.y);
}
*/
ostream &operator<<(ostream &out, Data &obj) {
    out << obj.x << " " << obj.y;
    return out;
}

int main() {
    Data a(2, 3), b(5, 6);
    Data c = a + b;
    cout << a + b << endl;
    cout << (a * 9) << endl;
    return 0;
}
