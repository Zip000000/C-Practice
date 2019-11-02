/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月18日 星期三 17时15分03秒
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
#define IND(a) (a - 'A')
int edge[7][7];
void set_edge(char a, char b, int d) {
    edge[IND(a)][IND(b)] = d;
    edge[IND(b)][IND(a)] = d;
    cout << "INDa = " << IND(a) << endl;
}
int main() {
    for (int i = 0; i < 7; i++) for(int j = 0; j < 7; j++) edge[i][j] = 0x7fffffff;
    set_edge('A', 'B', 12);
    set_edge('C', 'D', 3);
    set_edge('B', 'C', 10);
    set_edge('D', 'E', 4);
    set_edge('C', 'F', 6);
    set_edge('F', 'A', 16);
    set_edge('E', 'F', 2);
    set_edge('B', 'F', 7);
    set_edge('C', 'E', 5);
    for (int i = 'A'; i <= 'F'; i++) {
        set_edge(i, i, 0);
    }
    
    char tmp;
    int start, end;
    cin >> tmp;
    start = IND(tmp);
    cin >> tmp;
    end = IND(tmp);

    queue<int> que;
    que.push(start);
    step = 0;
    while (1) {
        step += 1;
        for (int i = 0; i <= cnt; i++) {
            int now = que.front();
            for (int j = 0; j <= 6; j++) {
                if (edge[now][j])
            }
        }

    }

    
    return 0;
}
