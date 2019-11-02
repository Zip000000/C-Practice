/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月16日 星期一 20时22分36秒
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
#define NO "Neither"
#define IP4 "IPv4"
#define IP6 "IPv6"
#define FIP4 1
#define FIP6 2
#define MAX_N 256


int main()  {
    string str;
    cin >> str;
    string::size_type ind1 = str.find(".");
    string::size_type ind2 = str.find(":");
    int ansflag = 0;
    int flag = 0;
    if (ind1 == str.npos && ind2 == str.npos) {
        cout << NO << endl;
        return 0;
    } else if (ind1 != str.npos) {
        flag = FIP4;
    } else {
        flag = FIP6;
    }
    char newstr[MAX_N] = {0};
    strcpy(newstr, str.c_str());
    if (flag == FIP4) {
        if (str.find(".0") != str.npos) {  //BUG
            cout << NO << endl;
            return 0;
        }
        int ip[4];
        sscanf(newstr, "%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
        for (int i = 0; i < 4; i++) {
            if (ip[i] >= 0 && ip[i] <= 255) continue;
            cout << NO << endl;
            return 0;
        }
        cout << IP4 << endl;
        return 0;
    } else {
        if (str.find("::") != str.npos) {  //BUG
            cout << NO << endl;
            return 0;
        }
        int num[8] = {0};
        for (int i = 0, cnt = 0; i < str.size(); i++) {
            if (str[i] == ':') cnt += 1;
            else num[cnt] += 1;
        }
        for (int i = 0; i < 6; i++) {
            if (num[i] != 0 && num[i] <= 4) continue;
            cout << NO << endl;
            return 0;
        }
        cout << IP6 << endl;
        return 0;
    }
    return 0;
}
