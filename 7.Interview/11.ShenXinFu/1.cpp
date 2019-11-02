/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 16时28分37秒
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

struct Node {
    int data;
    struct Node *l, *r;
    Node(int c) : data(c), l(NULL), r(NULL) {}
};

inline Node *getNewNode(int c) {
    return new Node(c);
}
inline int tonum(string &s) {
    if (s[0] == '#') return -1;
    return (atoi(s.c_str()));
}
void pre_order(Node *root) {
    int ind = root->data;
    if (ind == -1) cout << "#" << endl;
    else cout << ind << endl;
    if (root->l) pre_order(root->l);
    if (root->r) pre_order(root->r);
    return ;
}

int main() {
    queue<Node *> que;
    Node *root = NULL;
    int n;
    cin >> n;
    string input;
    cin >> input;
    root = getNewNode(tonum(input));
    que.push(root);
    int cnt = 1;
    int cincnt = 1;
    int tmp = 0; 
    while (cincnt < n) {
        //cout << "cincnt = " << cincnt << endl;
        for (int i = 0; i < cnt; i++) {
            Node *now = que.front();
            cin >> input;
            //cout << "cincnt = " << cincnt << "  input = " << input << endl;
            cincnt += 1;
            now->l = getNewNode(tonum(input));
            if (now->l->data != -1) que.push(now->l);
            cin >> input;
            cincnt += 1;
            //cout << "cincnt = " << cincnt << "  input = " << input << endl;
            now->r = getNewNode(tonum(input));
            if (now->r->data != -1) que.push(now->r);
            que.pop();
        }
        cnt = que.size();
    }
    while (!que.empty()) {
        Node *now = que.front();
        now->l = getNewNode(-1);
        now->r = getNewNode(-1);
        que.pop();
    }
    pre_order(root);
    
    return 0;
}
