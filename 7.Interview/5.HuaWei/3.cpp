/*************************************************************************
	> File Name: 3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 10时00分10秒
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
#define MAX_N 1000
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    int flag[MAX_N + 5] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        flag[arr[i]] = 1;
    } 
    for (int i = 1; i <= MAX_N; i++) {
        if (flag[i] == 0) continue;
        cout << i << endl;
    }
    
    
    return 0;
}
