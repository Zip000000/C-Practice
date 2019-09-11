/*************************************************************************
	> File Name: 08.Template.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月15日 星期四 11时27分55秒
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

template<typename T>
T add(const T &a, const T &b) {
    return a + b;
}


template<typename T>
void print(T &a) {
    cout << a << endl;
    cout << "endl" << endl;
    return ;
}
template<typename T, typename ...ARGS>
void print(T &a, ARGS...args) {
    cout << a << endl;
    printf(args...);
    return;
}

int main() {
    
    print(1, 2.2, "hello"); 
    
    return 0;
}
