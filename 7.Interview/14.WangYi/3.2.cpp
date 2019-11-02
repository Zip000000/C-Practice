/*************************************************************************
	> File Name: 3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月21日 星期六 15时57分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];

int main() {
    int times;
    cin >> times;
    for (int ti = 0; ti < times; ti++) {
        int n;
        cin >> n;
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        int ans = 0x80000000;
        int cnt = 1, lasti = 0;
        for (int i = 2; i <= n; i++) {
            if (arr[i] - arr[i - 1] >= arr[i - 1] - arr[lasti - 1]) {
                cnt += 1;
            } else {
                cnt = 1, lasti = i;
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }

    return 0;
}
