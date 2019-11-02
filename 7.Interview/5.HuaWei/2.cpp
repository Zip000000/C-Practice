/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 09时36分37秒
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

    string str;
    cin >> str;
    for (int i = 0; str[i]; i++) {
        code[str[i]] += 1;
    }
    cin >> str;
    int ans = 0;
    ans += code[str[0]];

    if (str[0] >= 'a') ans += code[str[0] - ('a' - 'A')];
    if (str[0] < 'a') ans += code[str[0] + ('a' - 'A')];
    cout << ans << endl;

    return 0;
}
