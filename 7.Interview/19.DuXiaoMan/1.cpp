/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月29日 星期日 18时59分54秒
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
int main() {
    long long n, m;
    cin >> n >> m;
    int flag = 0;
    if (n & 1) flag += 1;
    if (m & 1) flag += 2;
    long long ans = 0;
    if (flag == 3) ans = m * n + 2;
    else ans = m * n;
    cout << ans << endl;
    return 0;
}

