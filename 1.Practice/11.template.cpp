/*************************************************************************
	> File Name: 11.template.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 16时47分01秒
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
    A(int x) : x(x) {}
    int operator+(const int y) {
        return this->x + y;
    }
    int operator+(const A &a) {
        return this->x + a.x;
    }
private:
     int x;
};

template<typename T, typename U>
auto add(T &a, U &b) -> decltype(a + b) {
    return a + b;
}

template<typename T>
struct Print {
    template<typename U>
    void operator()(const U &a) {
        cout << a << endl;
    }
};
template<typename T, typename ...ARGS>
void print(T &a, ARGS...args) {
    cout << a << endl;
    print(args...);
    return ;
}

template<typename T> {
    void print(T &a) {
        cout << a << endl;
        cout << "end" << endl;
    }
}
int main() {
    int a = 3, b = 4;
    A d(2);
    double c = 4.5;
    int n = 5;
    
    Print<int> plog;
    plog(a);
    plog(c);
    plog(add(a, b));

    cout << add(d, n) << endl; 
    cout << add(a, b) << endl;
    cout << add(a, c) << endl;
    //printf(1, 2, 3, "hello world");
    return 0;
}
