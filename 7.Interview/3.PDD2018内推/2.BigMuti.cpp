/*************************************************************************
	> File Name: 2.BigMuti.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 17时02分30秒
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
    string a, b;
    cin >> a >> b;
    vector<int> ans(a.size() + b.size() + 10);
    int ind, flag;
    for (int i = b.size() - 1; i >= 0; i--) {
        for (int j = a.size() - 1; j >= 0; j--) {
            int numa = a[j] - '0';
            int numb = b[i] - '0';
            int indi = b.size() - i - 1, indj = a.size() - j - 1; 
            ind = indi + indj;
            ans[ind] += numa * numb;
            flag = 0;
            if (ans[ind] >= 10) {
                ans[ind + 1] += ans[ind] / 10;
                ans[ind] %= 10;
                flag = 1;
            }
        }
    }
    
    while (flag) {
        ind++;
        if (ans[ind] >= 10) {
            ans[ind + 1] += ans[ind] / 10;
            ans[ind] %= 10;
            continue;
        }
        break;
    }
    
   for (int i = ind; i >= 0; i--) cout << ans[i];
    cout << endl;
    
    
    
    return 0;
}
