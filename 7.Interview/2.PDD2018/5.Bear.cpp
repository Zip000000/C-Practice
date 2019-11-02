/*************************************************************************
	> File Name: 5.Bear.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 15时28分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

#define MAX_M 100
#define MAX_N 10

bool cmp(const int *a, const int *b) {
    return (a[0] > b[0]);
}
int main() {
    int n, m;
    cin >> n >> m;
    int candy[100 + 5] = {0};
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        candy[tmp] += 1;
    }
    int last = 0;
    int bear[MAX_N + 5][2] = {0}; //战斗力  饥饿值
    for (int i = 0; i < n; i++) cin >> bear[i][0] >> bear[i][1];
    sort((int **)bear, (int **)(&bear[n  - 1]), cmp);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (bear[i][1] > 0) {
            int flag = 1;
            for (int j = bear[i][1]; j > 0; j--) {
                if (candy[j] == 0) continue;
                bear[i][1] -= j, candy[j] -= 1;
                flag = 0;
                break;
            }
            if (flag == 1) break;
        }
        ans += bear[i][1];
    }

    for (int i = 0; i < n; i++) {
        cout << bear[i][1] <<endl;
    }
    return 0;
}
