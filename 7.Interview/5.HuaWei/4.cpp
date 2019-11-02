/*************************************************************************
	> File Name: 4.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 10时09分08秒
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
    string str;
    for (int i = 0; i < 2; i++) {
        cin >> str;
        int cnt = 0;
        while (str[cnt]) {
            if (!str[cnt]) break;
            for (int k = 0; k < 8; k++) {
                cout << (str[cnt] ? str[cnt++] : '0');
            }
            cout << endl;
        }
    }
    return 0;
}
