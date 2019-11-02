/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 19时01分16秒
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
#define MAX_N 100
int flag[MAX_N + 5];

int main() {
    vector<int> vec;
    int tmp;
    while (cin >> tmp) {
        vec.push_back(tmp);
    }
    
    queue<int> que;
    for (int i = 0; i < vec.size() / 2; i++) que.push(i), flag[i] = i;
    int step = 1;
    int cnt = vec.size() / 2;
    int ansflag = 0;
    while (!que.empty()) {
        int tmpcnt = 0;
        for (int i = 0; i < cnt; i++) {
            int f = que.front();
            if (f + vec[f] >= vec.size()) {
                que.pop();
            } else if (f + vec[f] == vec.size() - 1) {
                ansflag = 1;
                break;
            } else {
                que.push(f + vec[f]);
                tmpcnt += 1;
                que.pop();
            }
        }
        step += 1;
        cnt = tmpcnt;
        if (ansflag) break;
    }
    if (ansflag) cout << step << endl;
    else cout << -1 << endl;
    return 0;
}
