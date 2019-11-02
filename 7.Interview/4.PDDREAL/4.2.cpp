/*************************************************************************
	> File Name: 4.2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月01日 星期日 16时50分01秒
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

bool cmp(const int a, const int b) {
    return a > b;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    
    vector<long long> v;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v.push_back(i * j);
        }
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[k - 1] << endl;
    
    
    
    return 0;
}
