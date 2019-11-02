/*************************************************************************
	> File Name: 4.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月15日 星期日 16时16分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <climits>
using namespace std;
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}
double f(double x) {
    if (x == 1) return 0;
    double cnt = 1.0;
    for (int i = 2; i <= x; i++) {
        if (gcd(i, x) == 1) cnt += 1;
    }
    return (cnt)/(x);
}

int main() {
    int n;
    cin >> n;
    double min = 0x7fffffff;
    for (int i = 2; i <= n; i++) {
        double ind = f(i);
        min = min < ind ? min : ind;
    }
    cout << min << endl;
    printf("%.6lf\n", min); 
    return 0;
}
