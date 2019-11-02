/*************************************************************************
	> File Name: 3.triangle.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 14时23分53秒
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

typedef struct point {
    int x, y;
} point;

bool in_line(point **p, int i, int j, int k) {
    int xi = p[i]->x, xj = p[j]->x, xk = p[k]->x;
    int yi = p[i]->y, yj = p[j]->y, yk = p[k]->y;
    return ((p[i]->x == p[j]->x && p[i]->x == p[k]->x) || (p[i]->y == p[j]->y && p[i]->y == p[k]->y) || ((yj - yi) * (xk - xi) == (xj - xi) * (yk - yi)));
}

int main() {
    int n;
    cin >> n;
    point **p = (point **)calloc(sizeof(point *), (n + 5));
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p[i] = (point *)malloc(sizeof(point) * 1);
        p[i]->x = x;
        p[i]->y = y;
    }
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (!in_line(p, i, j, k)) ans += 1;
            }
        }
    }
    cout << ans << endl;
    
    
    return 0;
}
