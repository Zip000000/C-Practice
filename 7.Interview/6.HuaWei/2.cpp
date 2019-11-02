/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 19时42分46秒
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
#define MODE 1000000007
int ret[10000 + 1][20000 + 1] = {0};
long long get_ans(int num, int used, int level) {
    if (num - used == 0) return 1;
    if (level == 1) return 1;
    
    //long long ret = num - used + 1;
    long long sum = 0;
    for (int i = 0; i <= (num - used); i++) {
        if (ret[used + i][level - 1] != 0) {
            if (sum >= MODE) sum %= MODE;
            sum += ret[used + i][level - 1];
            if (sum >= MODE) sum %= MODE;
            continue;
        }
        if (sum >= MODE) sum %= MODE;
        sum  += get_ans(num, used + i, level - 1);
        if (sum >= MODE) sum %= MODE;
    }
    if (sum >= MODE) sum %= MODE;
    if (ret[used][level] == 0) ret[used][level]= sum;
    return sum;
}



int main() {
    int n, m;
    cin >> n >> m;

    cout << (get_ans(m, 0, n) % MODE) << endl;
        
    
    return 0;
}
