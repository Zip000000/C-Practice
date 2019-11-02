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
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define MAX_N 100000
int arr[MAX_N + 5];
int f[MAX_N + 5];


int main() {
    int times;
    cin >> times;
    
    while (times--) {
        int n;
        cin >> n;
        memset(arr, (n + 1) * sizeof(int), 0);
        memset(f, (n + 1) * sizeof(int), 0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        
        for (int i = 1; i <= n; i++) {
            //f[i] = 1;
            for (int j = 1; j < i; j++) {
                if (arr[i] - arr[i - 1] >= arr[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
                cout << "i = " << i << " j = " << j << "fi = " << f[i] << endl;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
        cout << ans << endl;
    }

    return 0;
}
