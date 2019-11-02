/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月29日 星期日 09时44分39秒
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
#define MAX_N 20
int arr[MAX_N + 5];
int flag[MAX_N + 5][MAX_N + 5];
struct Node {
    string route;
    int id;
    int sum;
    Node() : id(0), sum(0) {}
};
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> flag[i][j];
        }
    }
    queue<Node *> que;
    Node *nd = new Node;
    nd->route += '1';
    nd->sum = arr[0];
    que.push(nd);
    int cnt = que.size();
    Node *ans = new Node;
    while (!que.empty()) {
        for (int i = 0; i < cnt; i++) {
            Node *nownode = que.front();
            int id = nownode->id;
            int ansflag = 1;
            for (int j = id + 1; j < n; j++) {
                if (flag[id][j] == 0) continue;
                ansflag = 0;
                Node *newnode = new Node(*nownode);
                newnode->id = j;
                newnode->route += ' ';
                newnode->route += to_string(j + 1);
                newnode->sum += arr[j];
                que.push(newnode);
            }
            if (ansflag) {
                if (nownode->sum >= ans->sum) {
                    if (nownode->sum == ans->sum) {
                        if (nownode->route < ans->route) *ans = *nownode;
                    } else {
                        *ans = *nownode;
                    }
                }
            }
            que.pop();
        }
        cnt = que.size();
    }
    cout << ans->sum << endl;
    cout << ans->route << endl;
    
    return 0;
}
