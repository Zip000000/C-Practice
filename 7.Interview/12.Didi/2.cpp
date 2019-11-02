/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月19日 星期四 19时55分31秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <queue>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int tail = m;
    int head = 0;
    int ans = 0x7fffffff;
    deque<int> que;
    que.push_back(0);
    for (; tail <= n; tail++) {
        while (!que.empty() && que.front() <= arr[head]) que.pop_back();
        que.push_back(arr[head]);
        int ind = arr[tail] - que.front();
        ans = (ans < ind ? ans : ind);
        head += 1;
    }
    cout << ans << endl;
    
    
    
    return 0;
}
