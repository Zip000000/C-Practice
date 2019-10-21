/*************************************************************************
	> File Name: 471-my.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月13日 星期日 16时25分41秒
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
    BigInt() {
        num.push_back(0);
    }
    BigInt(const string &str) {
        num.clear();
        for (int i = str.size() - 1; i >= 0; i--) {
            num.push_back(str[i] - '0');
        }
    }
    BigInt operator*(const BigInt &a) {
        BigInt ret;
        for (int i = 0; i < num.size(); i++) {
            for (int j = 0; j < a.num.size(); j++) {
                if (i + j == ret.num.size()) ret.num.push_back(0);
                ret.num[i + j] = num[i] * a.num[j];
            }
        }
        ret.process_digit();
        return ret;
    }
    void process_digit() {
        for (int i = 0; i < num.size(); i++) {
            if (i == num.size() - 1 && num[i] >= 10) num.push_back(0);
            else if (num[i] >= 10) num[i + 1] = 0;
            if (num[i] >= 10) num[i + 1] += num[i] / 10, num[i] %= 10;
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
    string str;
    cin >> str;
    BigInt a = str;
    cin >> str;
    BigInt b = str;
    cout << a << endl;
    cout << b << endl;
    cout << (a * b) << endl;
    
    
    
    return 0;
}
