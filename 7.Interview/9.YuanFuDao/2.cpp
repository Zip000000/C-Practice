/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月16日 星期一 16时59分20秒
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
#define MAX_N 1000000
int vec[MAX_N + 5];
int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", vec + i);
        vec[i] += vec[i - 1];
    }
    int ans = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            if (vec[j] - vec[i] > s) continue;
            int ind = j - i;
            if (ind < ans) break;
            ans = ind;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
