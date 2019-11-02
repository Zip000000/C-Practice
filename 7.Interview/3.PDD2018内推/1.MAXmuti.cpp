/*************************************************************************
	> File Name: 1.MAXmuti.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 16时24分28秒
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
    long long  n;
    cin >> n;
    long long  zerocnt = 0, poscnt = 0, negcnt = 0;
    long long posmax[3], negmax[3];
    for (int i = 0; i < 3; i++) posmax[i] = INT_MIN, negmax[i] = INT_MAX;
    for (long long  i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            poscnt += 1;
            if (tmp > posmax[0]) posmax[2] = posmax[1], posmax[1] = posmax[0], posmax[0] = tmp;
            else if (tmp > posmax[1]) posmax[2] = posmax[1], posmax[1] = tmp;
            else if (tmp > posmax[2]) posmax[2] = tmp;
        } else if (tmp < 0) {
            negcnt += 1;    
            if (tmp < negmax[0]) negmax[2] = negmax[1], negmax[1] = negmax[0], negmax[0] = tmp;
            else if (tmp < negmax[1]) negmax[2] = negmax[1], negmax[1] = tmp;
            else if (tmp < negmax[2]) negmax[2] = tmp;
        } else {
            zerocnt += 1;
        }
    }
    long long ans = 1;
    if (negcnt + poscnt == 3) {
        if (negcnt  == 1 || negcnt == 3) {
            if (zerocnt > 0) ans = 0;
            else {
                for (int i = 0; i < poscnt; i++) ans *= posmax[i];
                for (int i = 0; i < negcnt; i++) ans *= negmax[i];
            }
        } else if (poscnt == 3) {
            for (int i = 0; i < 3; i++) ans *= posmax[i];
        } else {
            for (int i = 0; i < poscnt; i++) ans *= posmax[i];
            for (int i = 0; i < negcnt; i++) ans *= negmax[i];
        } 
    } else {
        if (negcnt < 2 ) {
            for (int i = 0; i < 3; i++) ans *= posmax[i];
        } else if (poscnt < 3) {
            for (int i = 0; i < 2; i++) ans *= negmax[i];
            ans *= posmax[0];
        } else {
            long long ind1 = 1, ind2 = 1;
            for (int i = 0; i < 3; i++) ind1 *= posmax[i];
            for (int i = 0; i < 2; i++) ind2 *= negmax[i];
            ind2 *= posmax[0];
            ans = max(ind1, ind2);
        }
    }
    cout << ans << endl;
    
    return 0;
}
