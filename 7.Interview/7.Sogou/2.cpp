/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月08日 星期日 16时48分02秒
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
#define MAX_N 1000000
typedef struct Node {
    int start;
    int childnum;
    vector<int> next;
} Node;

Node node[MAX_N + 5];
int flag[MAX_N + 5];
bool cmp(const int &a, const int &b) {
    return (node[a].childnum > node[b].childnum);
}
void my_sort(int root) {
    sort(node[root].next.begin(), node[root].next.end(), cmp);
    for (int i = 0; i < node[root].next.size(); i++) {
        my_sort(node[root].next[i]);
    }
}
int main() {
    int k, resline, tmp, father, son;
    cin >> k >> resline;
    for (int i = 0; i < resline; i++) {
        cin >> tmp;
        cin >> father;
        for (int i = 1; i < tmp; i++) {
            cin >> son;
            node[father].next.push_back(son);
            node[father].childnum += 1;
            //cout << "father : " << father << " son : " << son << endl;
        }
    }
    my_sort(0);
    //cout << "after insert" << endl;
    
    queue<int> que;
    que.push(0);
    int cnt = 1, step = 0;
    while (!que.empty()) {
        int tmpcnt = 0;
        int push_flag = 0;
        for (int i = 0; i < cnt; i++) {
            int qf = que.front();
            flag[qf] = 0;
            //cout  << "qf : " << qf;
            int max_son = node[qf].next.size();
            for (int j = node[qf].start; j < max_son; j++) {
                if (flag[qf] >= k) {
                    que.push(qf);
                    node[qf].start = j;
                    tmpcnt += 1;
                    break;
                } 
                flag[qf] += 1;
                que.push(node[qf].next[j]);
            push_flag = 0;
                //cout << " push : " << node[qf].next[j] <<" ";
                push_flag = 1;
                tmpcnt += 1;
            }
            //cout << endl;
            que.pop();
        }
        if (push_flag) {
            step += 1;
            //cout << "step + 1" << endl;
        } 
        //cnt = que.size();
        cnt = tmpcnt;
    }
    cout << step << endl;
    
    return 0;
}
