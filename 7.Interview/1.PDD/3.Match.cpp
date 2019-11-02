/*************************************************************************
	> File Name: 3.Match.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 11时41分09秒
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
int arr[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int max = -2147483648;
    int min = 2147483647;

    for (int i = 0, I = n / 2; i < I; i++) {
        int tmp = arr[n - i - 1] + arr[i];
        if (tmp > max) max = tmp;
        if (tmp < min) min = tmp;
    }
    cout << max - min << endl;
    
    return 0;
}
