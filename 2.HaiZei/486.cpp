/*************************************************************************
	> File Name: 486.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月22日 星期二 18时17分32秒
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
const int MODE = 12345;
int ret[1000] = {0};
int get_ans(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (ret[n] != 0) return ret[n];
    int ans = 0;
    ans += get_ans(n - 1);
    ans %= MODE;
    ans += (get_ans(n - 2) % MODE) * 2;
    ans %= MODE;
    return ret[n] = ans;
}

int main() {
    int n;
    cin >> n;

    int ans = get_ans(n);
    cout << ans << endl;
    
    return 0;
}
