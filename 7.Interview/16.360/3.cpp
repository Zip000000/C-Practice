/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月26日 星期四 20时19分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <deque>
using namespace std;
#define MAX_N 100000
double arr[MAX_N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <+ n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    double ans = 0;
    for (int i = m; i <= n; i++) {
        for (int j = 0; j < i - m + 1; j++) {
            double ind = (arr[i] - arr[j]) / (double)(i - j);
            ans = (ind > ans ? ind : ans);
        }
    }
    printf("%.3lf\n", ans);
    
    
    return 0;
}
