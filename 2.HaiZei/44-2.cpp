/*************************************************************************
	> File Name: 44-2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月23日 星期三 15时30分23秒
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
#define MAX_N 1000000

int arr[MAX_N + 5];
int low[MAX_N + 5];

int binary_search(int low[], int l, int r, int key) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (low[mid] >= key) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int ans = 1;
    low[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        if (arr[i] > low[ans]) {
            low[++ans] = arr[i];
        } else {
            int ind = binary_search(low, 1, ans, arr[i]);
            low[ind] = arr[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}
