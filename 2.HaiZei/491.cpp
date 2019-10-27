/*************************************************************************
	> File Name: 491.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月22日 星期二 20时27分26秒
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
long long dp[60];
int main() {
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
        if (i < m) {
            dp[i] = 2 * dp[i - 1];
        } else if (i == m) {
            dp[i] = 2 * dp[i - 1] - 1;
        } else {
            dp[i] = 2 * dp[i - 1] - dp[i - m - 1];
        }
    }
    cout << dp[n] << endl;
    
    
    
    return 0;
}
