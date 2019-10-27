/*************************************************************************
	> File Name: 23.detect_ip.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月22日 星期二 17时57分29秒
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

#include <iostream>
using namespace std;

bool detect_ip4(string str) {
    int cnt = 0;
    int ip[4] = {-1, -1, -1, -1};
    if (str.size() == 0 || str[0] == '.') return false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') cnt += 1;
        if (!(str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))) return false;
        if (cnt >= 4) return false;
        if (i > 0 && i < str.size() - 1 && str[i - 1] == '.' && str[i] == '0' && str[i] != '.') return false;
        ip[cnt] *= 10;
        ip[cnt] += str[i] - '0';
    }
    for (int i = 0; i < 4; i++) {
        if (ip[i] == -1 || ip[i] > 255) return false;
    }
    return true;
}

int main() {
    string str = "192.168.0.1";
    if (detect_ip4(str)) cout << "true" << endl;
    else cout << "false" << endl;
}
