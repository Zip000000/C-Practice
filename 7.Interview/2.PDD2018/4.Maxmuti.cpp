/*************************************************************************
	> File Name: 4.Maxmuti.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 14时45分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <climits>
using namespace std;


int main() {
    int n;
    cin >> n;
    int *arr = new int[n + 5];
    int poscnt = 0, negcnt = 0, zerocnt = 0;
    int pos_max[3] = {INT_MIN, INT_MIN, INT_MIN}, neg_max[3] = {INT_MAX, INT_MAX, INT_MAX};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            zerocnt += 1;
        } else if (arr[i] < 0) {
            negcnt += 1;
            if (arr[i] < neg_max[0]) neg_max[2] = neg_max[1], neg_max[1] = neg_max[0], neg_max[0] = arr[i];
            else if (arr[i] < neg_max[1]) neg_max[2] = neg_max[1], neg_max[1] = arr[i];
            else if (arr[i] < neg_max[2]) neg_max[2] = arr[i];
        } else {
            poscnt += 1;
            if (arr[i] > pos_max[0]) pos_max[2] = pos_max[1], pos_max[1] = pos_max[0], pos_max[0] = arr[i];
            else if (arr[i] > pos_max[1]) pos_max[2] = pos_max[1], pos_max[1] = arr[i];
            else if (arr[i] > pos_max[2]) pos_max[2] = arr[i];
        }
    }
    /*
    for (int i = 0; i < 3; i++) {
        cout << pos_max[i] << " " << neg_max[i] << endl;
    }
    */
    int ans = 0;
    if (poscnt == 2 && negcnt == 1 || poscnt == 0 && negcnt == 3) {
        if (zerocnt > 0) ans = 0;
        else {
            switch (negcnt) {
                case 1: ans = (pos_max[0] * pos_max[1] * neg_max[0]); break;
                case 3: ans = (neg_max[0] * neg_max[1] * neg_max[2]); break;
            }
        }
    } else {
        int ans1 = 1;
        for (int i = 0; i < 3; i++) ans1 *= pos_max[i];
        int ans2 = pos_max[0];
        for (int i = 0; i < 2; i++) ans1 *= neg_max[i];
        ans = max(ans1, ans2);
    }
    cout << ans << endl;
    
    return 0;
}
