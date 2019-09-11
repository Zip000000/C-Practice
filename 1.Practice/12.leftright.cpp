/*************************************************************************
	> File Name: 12.leftright.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 19时03分35秒
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

#define P(func, x) { \
    cout << #func << " (" << #x << ") "; \
    func(x); \
}

void judge(int &x) {
    cout << "left value" << endl;
}
void judge2(int &x) {
    cout << "left value" << endl;
}

void judge(int &&x) {
    cout << "right value" << endl;
    P(judge2, x);
}

int main() {
    int a = 1, b = 2;
    P(judge, a);
    P(judge, b);
    P(judge, a + b);
    P(judge, 123);
    
    return 0;
}
