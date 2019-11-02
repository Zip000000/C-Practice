/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月20日 星期五 19时01分14秒
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

int digit(long long x) {
    if (x == 0) return 1;
    return floor(log10(x)) + 1;
}

long long check(long long oldans, long long sum) {
    for (int i = -1; i <= 1; i++) {
        long long chec = 0;
        long long tmpans = oldans + i;
        //cout << "tmp ans = " << tmpans << endl;
        while (tmpans != 0) {
            chec += tmpans;
            tmpans /= 10;
        }
        //cout << "check = " << chec << endl;
        if (chec == sum) return oldans + i;
    }
    return -1;
}

int main() {
    
    long long sum;
    cin >> sum;
    
    long long ans = 0, ans2 = 0;
    int n = digit(sum);
    int n2 = digit(sum) - 1;
    
    //ans = sum / 10 * 9;
    ans = (double)sum / (pow(10, n + 1) - 1) * pow(10, n) * 9;
    //ans = sum * pow(10, n) * 9 / (pow(10, n + 1) - 1);
    //ans2 = sum * pow(10, n2) * 9 / (pow(10, n2 + 1) - 1);
    //cout << "ans1 = " << ans << endl;
    int ret1 = check(ans, sum);
    if (ret1 != -1) {
        cout << ret1 << endl;
    } else {
        ans2 = (double)sum / (pow(10, n2 + 1) - 1) * pow(10, n2) * 9;
        //cout << "ans2 = " << ans2 << endl;
        cout << check(ans2, sum);    
    }
    
    return 0;
}
