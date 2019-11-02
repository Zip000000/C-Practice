/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 19时00分38秒
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
int ret[100];
int f(int n) {
    if (n == 1 || n == 2) return n - 1; 
    if (ret[n] != 0) return ret[n];
    return ret[n] = (n - 1) * (f(n - 1) + f(n - 2));
}

int get_ans(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f(n - 1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << get_ans(n) << endl;
    return 0;
}
