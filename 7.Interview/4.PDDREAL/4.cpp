/*************************************************************************
	> File Name: 4.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月01日 星期日 16时12分36秒
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
    long long n, m, k;
    cin >> n >> m >> k;
    
    int min = (n > m ? m : n);
    
    int tmp_k = k, cnt = 0;
    while (tmp_k - cnt > 0) {
        tmp_k -= cnt;
        if (cnt < 3) cnt++;
        else cnt--;
    }
    //cnt 表示 最后去掉的那层
    vector<long long> v;

    for (int i = n - cnt; i <= n; i++) {
        for (int j = n; j >= n - cnt; j--) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }

    
    
    
    
    return 0;
}
