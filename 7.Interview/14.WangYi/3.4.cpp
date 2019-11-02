/*************************************************************************
	> File Name: 3.3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月21日 星期六 16时36分35秒
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

int main() {
    int times;
    cin >> times;
    while (times--) {
        int n;
        cin >> n;
        int *arr = new int[n + 5];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        int cnt = 1, ans = 0x80000000, lasti = 0;
        for (int i = 1; i < n; i++) {
            int sum = 0;
            //for (int j = lasti; j < i; j++) sum += arr[j];
            sum = arr[i] - arr[lasti - 1];
            if (arr[i] >= sum) cnt += 1;
            else cnt = 1, lasti = i;
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
