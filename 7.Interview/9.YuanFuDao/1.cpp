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
#define MAX_N 1000
#define MAX_M 1000
#define LTOR 1
#define RTOL 2
#define UTOD 4
#define DTOU 8
long long arr[MAX_N + 5][MAX_M + 5];

inline void out(int ind, int begin, int end, int flag) {
    switch(flag) {
        case LTOR: {
            for (int i = begin; i <= end; i++) {
                printf("%lld ", arr[ind][i]);
            }
        } break;
        case RTOL: {
            for (int i = begin; i >= end; i--) {
                printf("%lld ", arr[ind][i]);
            }
        } break;
        case UTOD: {
            for (int i = begin; i <= end; i++) {
                printf("%lld ", arr[i][ind]);
            }
        } break;
        case DTOU: {
            for (int i = begin; i >= end; i--) {
                printf("%lld ", arr[i][ind]);
            }
        } break;
    }
}
void output_circle(int l, int r, int up, int down) {
    out(l, up, down, UTOD);
    out(down, l + 1, r, LTOR);
    out(r, down - 1, up, DTOU);
    out(up, r - 1, l + 1, RTOL);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", arr[i] + j);
        }
    }

    int l = 0, r = m - 1, up = 0, down = n - 1;
    while (l <= r && up <= down) {
        output_circle(l, r, up, down);
        l += 1;
        r -= 1;
        up += 1;
        down -= 1;
    }
    printf("\n");
    return 0;
}
