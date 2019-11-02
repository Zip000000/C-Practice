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
    deque<int> que;
    que.push_back(0);
    double ans = 0;
    int j = 1;
    for (int i = m; i <= n; i++) {
        double ind = (arr[i] - arr[que.front()]) / (double)(i - que.front());
        ans = (ind > ans ? ind : ans);
        while (!que.empty() && arr[j] <= arr[que.back()]) que.pop_back();
        que.push_back(j);
        j++;
    }
    printf("%.3lf\n", ans);
    
    
    return 0;
}
