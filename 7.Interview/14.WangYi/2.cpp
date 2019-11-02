/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月21日 星期六 15时42分30秒
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
#define MAX_N 100000
long long arr[MAX_N + 5];
int main() {
    int times, n, m;
    cin >> times;
    while (times--) {
        cin >> n >> m;
        long long sum = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            //sum += tmp;
        }
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] > i) {
                m += (arr[i] - i);
            } else if (arr[i] < i) {
                if (arr[i] + m > i) {
                    cout << "NO" << endl;
                    flag = 0;
                    break;
                } else {
                    arr[i] = i;
                    m -= (i - arr[i]);
                }
            }
        }
        if (flag) cout << "YES" << endl;
    }
    return 0;
}
