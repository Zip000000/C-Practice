/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月26日 星期四 20时38分26秒
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
#define MAX_N 10000
struct Data {
    double a, t;
} Data[MAX_N + 5];

bool cmp(const struct Data &a, const struct Data &b) {
    return a.a > b.a;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Data[i].a >> Data[i].t;
    }
    sort(Data, Data + n, cmp);
    double ans = 0;
    double v0 = 0;
    for (int i = 0; i < n; i++) {
        double t = Data[i].t, a = Data[i].a;
        ans += (v0 * t + (a) * t * t * 0.5);
        v0 += a * t;
    }
    printf("%.1f\n", ans);
    return 0;
}
