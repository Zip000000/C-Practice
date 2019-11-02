/*************************************************************************
	> File Name: 3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月13日 星期日 20时53分08秒
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

int *ret;
int get_sum(int m) {
    if (m == 0) return 1;
    if (m == 1) return 1;
    if (ret[m] != 0) return ret[m];
    return (ret[m] = get_sum(m - 1) + get_sum(m - 2));
}


int main() {
    int m;
    cin >> m;
    ret = new int[m + 5]();
    int sum = get_sum(m);
    cout << sum << endl;
    return 0;
}
