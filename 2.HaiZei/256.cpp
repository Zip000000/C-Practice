/*************************************************************************
	> File Name: 256.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月08日 星期二 20时43分05秒
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

struct Data {
    int a, b;
    bool operator<(const Data &obj) const { return a * b < obj.a * obj.b; }
};
vector<Data> d;

struct BigInt {
    BigInt(int x) {
        num.push_back(x);
        process_digit();
    }
    BigInt(vector<int> &ret) : num(ret) {}
    void operator*=(int x) {
        for (int i = 0; i < num.size(); i++) num[i] *= x;
        process_digit();
    }
    bool operator>(const BigInt &obj) {
        if (num.size() - obj.num.size()) return num.size() > obj.num.size();
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] == obj.num[i]) continue;
            return num[i] > obj.num[i];
        }
        return false;
    }
/*
    */
    bool operator<(const BigInt &obj) {
        if (num.size() - obj.num.size()) return num.size() < obj.num.size();
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] == obj.num[i]) continue;
            return num[i] < obj.num[i];
        }
        return false;
    }
    BigInt operator/(int x) {
        int i = num.size(), temp = 0;
        while (i && temp * 10 + num[i - 1] < x) temp = temp * 10 + num[i - 1], i -= 1;
        if (i == 0) return BigInt(0);
        vector<int> ret(i);
        while (i) {
            i--;
            temp = temp * 10 + num[i];
            ret[i] = temp / x;
            temp %= x;
        }
        return BigInt(ret);
    }
    void process_digit() {
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        return ;
    }
    
    vector<int> num;
};

ostream &operator<<(ostream &out, const BigInt &obj) {
    for (int i = obj.num.size() - 1; i >= 0; i--) {
        out << obj.num[i];
    }
    return out;
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a >> b;
        d.push_back({a, b});
    }

    sort(d.begin() + 1, d.end());
    BigInt p = d[0].a, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p / d[i].b > ans) ans = p / d[i].b;
        p *= d[i].a;
    }
    cout << ans << endl;
    
    return 0;
}
