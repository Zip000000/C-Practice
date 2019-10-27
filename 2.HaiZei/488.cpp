/*************************************************************************
	> File Name: 488.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月25日 星期五 14时17分17秒
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
#define MAX_N 100000
long long arr[MAX_N + 5][2];
long long dp[MAX_N + 5][2];
int main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 1; i < n; i++) {
        int dis = abs(arr[i][0] - arr[i - 1][0]) + abs(arr[i][1] - arr[i - 1][1]);
        dp[i][1] = dp[i - 1][1] + dis;
    }
    for (int i = 1; i < n - 1; i++) {
        int dis = abs(arr[i + 1][0] - arr[i - 1][0]) + abs(arr[i + 1][1] - arr[i - 1][1]);
        dp[i][0] = dp[i - 1][1] + dp[n - 1][1] - dp[i + 1][1] + dis;
    }
    long long ans = 0x7fffffff;
    for (int i = 1; i < n - 1; i++) {
        //cout << dp[i][0] << endl;
        ans = min(ans, dp[i][0]);
    }
    cout << ans << endl;
    
    return 0;
}
