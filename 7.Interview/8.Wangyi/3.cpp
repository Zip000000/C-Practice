/*************************************************************************
	> File Name: 3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月15日 星期日 14时40分48秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <queue>
using namespace std;

typedef struct Data {
    int start, cost, dead;
} Data;

struct quetmp1 {
    Data d;
    quetmp1(Data dd) : d(dd) {}
    bool operator<(const quetmp1 &a) const {
        if (d.cost == a.d.cost) return d.dead < a.d.dead;
        return d.cost > a.d.cost;
    }
};
struct quetmp2 {
    Data d;
    quetmp2(Data dd) : d(dd) {}
    bool operator<(const quetmp2 &a) const {
        if (d.start == a.d.start) return d.cost < a.d.cost;
        return d.start > a.d.start;
    }
};
priority_queue<quetmp1> early; //先处理
priority_queue<quetmp2> late;
int main() {
    int n;
    cin >> n;
    vector<Data> vec;
    for (int i = 0; i < n; i++) {
        Data d;
        cin >> d.dead >> d.cost;
        d.start = d.dead - d.cost;
        vec.push_back(d);
    }
    for (int i = 0; i < vec.size(); i++) late.push(vec[i]);
    int now = 0;
    int ans = 0;
    while (late.size() != 0) {
        int latetopstart = late.top().d.start;
        while (late.size() > 0 && latetopstart < now) {
            early.push(late.top().d);
            late.pop();
            latetopstart = late.top().d.start;
        }
        if (early.size() == 0) {
            early.push(late.top().d);
            late.pop();
        }
        int earlytopstart = early.top().d.start;
        if (now > earlytopstart) ans += now - earlytopstart;
        now += early.top().d.cost;
        early.pop();
    }
    
    while (early.size() != 0) {
        int earlytopstart = early.top().d.start;
        if (now > earlytopstart) ans += now - earlytopstart;
        now += early.top().d.cost;
        early.pop();
    }

    cout << ans << endl;
    return 0;
}

/*

bool cmp(const Data &a, const Data &b) {
    if (a.dead == b.dead) {
        return a.cost < b.cost;
    } else {
        return a.dead < b.dead;
    }
}
    //sort(vec.begin(), vec.end(), cmp);
    //
*/
