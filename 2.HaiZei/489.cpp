/*************************************************************************
	> File Name: 489.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月22日 星期二 19时24分15秒
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
    int dp[1000 + 5][2] = {0};
    int n;
    cin >> n;
    dp[1][0] = 8;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0] * 9) % 12345;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 9) % 12345;
    }
    cout << dp[n][0] % 12345 << endl;
    return 0;
}
