/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月08日 星期日 16时30分26秒
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
typedef pair<int, string> PII;
int main() {
    int n;
    cin >> n;
    map<PII, unsigned int> ma;
    map<string, PII> msi;
    string str;
    unsigned int val;
    int cnt = 0;
    while (cin >> str) {
        cin >> val;
        if (msi.find(str) != msi.end()) {
            if (ma[msi[str]] < val) ma[msi[str]] = val;
        } else {
            if (ma.size() < n) {
                PII now = PII(cnt++, str);
                msi[str] = now;
                ma[now] = val;
            } else {
                ma.erase(ma.begin());
                PII now = PII(cnt++, str);
                msi[str] = now;
                ma[now] = val;
            }
        }
    }
    
    
    return 0;
}
