/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月27日 星期五 19时50分48秒
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
#define MAX_N 100
typedef struct Data {
    int score, time;
    double key;
} Data;
Data arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    if (a.key == b.key) return a.time > b.time;
    return a.key > b.key;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].score;
    }    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].time;
        arr[i].key = (double)arr[i].score / (double)arr[i].time;
    }
    int time;
    cin >> time;

    sort(arr, arr + n, cmp);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int t = arr[i].time;
        int s = arr[i].score;
        if (time < t) continue;
        ans += s;
        time -= t;
    }
    cout << ans << endl;
    return 0;
}
