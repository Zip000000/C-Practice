/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月13日 星期日 20时48分37秒
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

inline int get_sum(int i, int x) {
    int sum = 0;
    while (i) {
        if (i % 10 == x) sum += 1;
        i /= 10;
    }
    return sum;
}

int main() {
    int m, n;
    cin >> m >> n;
    int x;
    cin >> x;
    int sum = 0;
    for (int i = m; i <= n; i++) {
        sum += get_sum(i, x);
    }
    cout << sum << endl;
    
    return 0;
}
