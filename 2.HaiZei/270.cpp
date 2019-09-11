/*************************************************************************
	> File Name: 270.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月27日 星期二 19时59分27秒
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
#define MAX_N 300000
int s[MAX_N + 5];
deque<int> q;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    q.push_back(0);
    int ans = s[0];
    for (int i = 0; i <= n; i++) {
        if (s[i] - s[q.front()] > ans) ans = s[i] - s[q.front()];
        while (!q.empty() && s[q.back()] > s[i]) q.pop_back();
        q.push_back(i);
        if (i - q.front() >= m) q.pop_front();
    }
    cout << ans << endl;

    
    
    
    return 0;
}
