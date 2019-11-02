/*************************************************************************
	> File Name: 6.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 11时44分47秒
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

int main() {
    long n;
    cin >> n;
    
    long *is_prime = new long[n + 5];
    long *prime = new long[n + 5];

    for (long M = 2; M < n + 5; M++) {
        if (!is_prime[M]) prime[++prime[0]] = M;
        for (int j = 1; j < prime[0]; j++) {
            if (M * prime[j] > n + 5) break;
            is_prime[M * prime[j]] = 1;
            if (M % prime[j] == 0) break;
        }
    }
    int k = 1;
    while (n != 1 && k <= prime[0]) {
        while (n % prime[k] == 0) {
            cout << prime[k] << " ";
            n /= prime[k];
        }
        k++;
    }
    cout << endl;
    
    
    return 0;
}
