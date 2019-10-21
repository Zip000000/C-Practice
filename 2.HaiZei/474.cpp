/*************************************************************************
	> File Name: 474.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月13日 星期日 15时33分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <deque>
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
    void operator=(const int &a) {
        num.clear();
        *this = to_string(a);
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
    BigInt(const int &a) : BigInt() {
        *this = a;
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
class BigFloat;
ostream &operator<<(ostream&, const BigFloat&);
class BigFloat {
public:
    void  operator=(const BigInt &a) {
        lpart.clear();
        rpart.clear();
        for (int i = 0; i < a.num.size(); i++) {
            this->lpart.push_front(a.num[i]);
        }
    }
    void operator>>=(const int &n) {
        for (int i = 0; i < n; i++) {
            rpart.push_front(lpart.back());
            lpart.pop_back();
            if (lpart.size() == 0) lpart.push_front(0);
        }

        for (int i = rpart.size() - 1; i >= 0; i--) {
            if (rpart[i] == 0) rpart.pop_back();
            else break;
        }
    }
    BigFloat() {
        this->lpart.push_front(0);
    }
    BigFloat(const BigInt &a) : BigFloat() {
        *this = a;
    }

    deque<int> lpart;
    deque<int> rpart;
};

ostream &operator<<(ostream &out, const BigFloat &a) {
    for (int i = 0; i < a.lpart.size(); i++) {
        out << a.lpart[i];
    }
    if (a.rpart.size() == 0) return out;
    out << ".";
    for (int i = 0; i < a.rpart.size(); i++) {
        out << a.rpart[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int tmp[4];
    BigInt ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d%%", tmp + j);
        }
        BigInt t = tmp[str[i] - 'A'];
        ans = (ans * t);
    }
    BigFloat fans;
    fans = ans;
    fans >>= (str.size() * 2);
    cout << fans << endl;
    return 0;
}
