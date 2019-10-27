/*************************************************************************
	> File Name: 492.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月25日 星期五 13时40分26秒
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
long long dp[30];
int main() {
    int n;
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 2; i <= n; i++) {
        if (i & 1) dp[i] = dp[i - 1];
        else dp[i] = 2 * dp[i - 1] + 1;
    }
    cout << dp[n] << endl;
    
    return 0;
}
