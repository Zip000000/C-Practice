/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月01日 星期日 15时01分27秒
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

#define MAX_N 100
long long num[MAX_N  + 5];
long long ansnum;

bool cmp(const long long a, const long long b) {
    return (a > b);
}

int main() {
    string input = ",";
    string str;
    cin >> str;
    input += str;
    int cnt = 0;
    int flag = 0;
    for (int i = 0; i < input.size(); ) {
        switch (input[i]) {
            case ',': {
                i++;
                while (input[i] != ',' && input[i] != ';') {
                    num[cnt] *= 10;
                    num[cnt] += (input[i] - '0');
                    i++;
                }
                cnt++;
            } break;
            case ';' : {
                i++;
                while (i < input.size()) {
                    ansnum *= 10;
                    ansnum += (input[i] - '0');
                    i++;
                }
                flag = 1;
            } break;
        }
        if (flag) break;
    }
    vector<long long> v1;
    vector<long long> v2;
    for (int i = 0; i < cnt; i++) {
        if (num[i] & 1) v2.push_back(num[i]);
        else v1.push_back(num[i]);
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    int coutnum = 0;
    for (int i = 0; i < v1.size() && coutnum < ansnum; coutnum++, i++) {
        i == 0 || cout << ",";
        cout << v1[i];
    }

    for (int i = 0; i < v2.size() && coutnum < ansnum; coutnum++, i++) {
        cout << "," << v2[i];
    }
    cout << endl;

    
    return 0;
}
