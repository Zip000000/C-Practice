/*************************************************************************
	> File Name: 471.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月13日 星期日 14时51分10秒
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

class BigInt {
public:    
    void operator=(const string &str) {
        num.clear();
        for (int i = str.size() - 1; i >= 0; i--) {
            num.push_back(str[i] - '0');
        }
        return ;
    }
    
    BigInt operator*(const BigInt &a) {
        BigInt c;
        vector<int> &ret = c.num;
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < a.num.size(); j++) {
                if (i + j == ret.size()) ret.push_back(0);
                ret[i + j] += num[i] * a.num[j];
            }
        }
        c.proccess_digit();
        return c;
    }

    BigInt() {
        num.push_back(0);
    }
    void proccess_digit() {
        while (num.size() > 1 && num[num.size() - 1] == 0) num.pop_back();
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) {
                if (i + 1 == num.size()) num.push_back(0);
                else num[i + 1] = 0;
            }
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    vector<int> num;
};
ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.num.size() - 1; i >= 0; i--) {
        out << a.num[i];
    }
    return out;
}

int main() {
    BigInt a, b;
    string str_a, str_b;
    cin >> str_a >> str_b;
    a = str_a;
    b = str_b;
    cout << (a * b) << endl;
    
    return 0;
}
