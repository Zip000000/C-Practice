/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月16日 星期一 21时26分04秒
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

char code[11][5] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
vector<string> vecans;
void output(string &str, int l) {
    static string ans(25, 0);
    static int cnt = 0;
    int ind = str[l] - '0';
    for (int i = 0; code[ind][i] != 0; i++) {
        ans[l] = code[ind][i];
        if (l < str.size() - 1) output(str, l + 1);
        else {
            //cnt == 0 || cout << ", ";
            //for (char it : ans) cout << it;
            vecans.push_back(ans);
            //cnt += 1;
            ans[l] = 0;
        }
    }
    return;
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            str.erase(str.begin() + i);
            i--;
        } 
    }
    string ansans;
    ansans += "[";
    //cout << "[";
    output(str, 0);
    for (int i = 0; i < vecans.size(); i++) {
        if (i != 0) ansans += ", ";
        ansans += vecans[i];
    }
    ansans += "]";
    cout << ansans << endl;
    //cout << "]" << endl;
    return 0;
}
