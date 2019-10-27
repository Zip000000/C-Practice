/*************************************************************************
	> File Name: 487.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月22日 星期二 18时49分17秒
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
long long re[50];
long long get_ans(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (re[n] != 0) return re[n];
    long long ret = 0;
    ret += get_ans(n - 1);
    ret += get_ans(n - 2);
    return re[n] = ret;
}

int main() {
    long long n;
    cin >> n;
    long long ans = get_ans(n - 1);
    cout << ans * 2 << endl;
    return 0;
}
