/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月15日 星期日 14时01分39秒
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

typedef struct Data {
    int w, h, s;
    double ind;
} Data;

bool cmp(const Data &a, const Data &b) {
    if (a.s == b.s) {
        if (a.ind == b.ind) {
            return a.w < b.w;
        }
        return a.ind > b.ind;
    } else {
        return a.s < b.s;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Data> vec;
    for (int i = 0; i < n; i++) {
        Data d;
        cin >> d.w >> d.h;
        d.s = d.w * d.h;
        double ind1 = (double)d.w/(double)d.h, ind2 = (double)d.h / (double)d.w;
        d.ind = (ind1 < ind2 ? ind1 : ind2);
        vec.push_back(d);
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < vec.size(); i++) {
        i == 0 || cout << " ";
        cout << vec[i].w << " " << vec[i].h;
    }
    cout << endl;
    return 0;
}
