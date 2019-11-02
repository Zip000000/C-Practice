/*************************************************************************
	> File Name: 4.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月16日 星期一 22时10分32秒
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

#define MAX_N 10000000
long long arr[MAX_N + 5];
int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    if (n <= 2) cout << n << endl;
    sort(arr, arr + n + 1);
    
    int d = arr[2] - arr[1];
    int max = 0;
    int cnt = 2;
    for (int i = 3; i <= n; i++) {
        //cout << arr[i] << " ";
        if (arr[i] - arr[i - 1] == d) {
            cnt += 1;
            //cout << "cnt = " << cnt << endl;
            if (cnt > max) max = cnt;
            continue;
        }
        d = arr[i] - arr[i - 1];
       // cout << "ther d = =" << d << endl;
        cnt = 2;
    }
    cout << max << endl;
}
