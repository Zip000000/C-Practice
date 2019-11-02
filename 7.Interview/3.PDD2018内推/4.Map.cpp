/*************************************************************************
	> File Name: 4.Map.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 21时03分07秒
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

struct node {
    int x, y;
    node(int x, int y) : x(x), y(y) {}
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> v;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    node *start;
    for (int i = 0; i < m; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '2') {
                start = new node(i, j);
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    int keyflag[128] = {0};
    queue<node *> q;
    node *nd = new node(0, 0);
    q.push(nd);
    int num = 1;
    while (!q.empty()) {
        node *now = q.front();
        q.pop();
        int tmp_num = 0;
        for (int i = 0; i < num; i++) {

        }
    }

    
    return 0;
}
