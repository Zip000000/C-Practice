/*************************************************************************
	> File Name: 5.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 10时49分59秒
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
    int code[128] = {0};
    for (int i = '0'; i <= '9'; i++) {
        code[i] = i - '0';
    }
    for (int i = 'A'; i <= 'F'; i++) {
        code[i] = i - 'A' + 10;
    }
    for (int i = 'a'; i <= 'f'; i++) {
        code[i] = i - 'a' + 10;
    }
    int n;

    string str;
    int ans = 0;
    while (cin >> str) {
        for (int i = 2; str[i]; i++) {
            ans *= 16;
            ans += code[str[i]];
            cout << str[i] << " : " << code[str[i]] << endl;
        }
        cout << ans << endl;
    }
        
    
    return 0;
}
