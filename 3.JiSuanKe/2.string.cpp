/*************************************************************************
	> File Name: 2.string.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月08日 星期日 19时51分14秒
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
string a = "abcdefg";
    cout << a << endl;
    a.replace(a.begin() + 2, a.begin() + 5, "XYZW");
    cout << 
    "a.replace(a.begin() + 2, a.begin() + 5, \"XYZW\");"
     << endl;
    cout << a << endl;
    string b = "abcdefg";
    b.replace(b.begin() + 2, b.begin() + 5, "UV");
    cout << 
    "b.replace(b.begin() + 2, b.begin() + 5, \"UV\");"
     << endl;
    cout << b << endl;
}
