/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月15日 星期日 15时37分35秒
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
typedef pair<int, int> PII;
struct Data {
    int x, y, z;
    int flag;
    PII l[3];
    vector<int> next;
    vector<int> line;
    Data() : flag(0) {}
};
inline void leftOnce(Data &d) {
    int __tmp = d.x;
    d.x = d.y, d.y = d.z, d.z = __tmp;
}
inline void directChange(Data &d) {
    int __tmp = d.y;
    d.y = d.z;
    d.z = __tmp;
}
inline void min_first(Data &d) {
    int min = (d.x < d.y ? d.x : d.y);
    min = (min < d.z ? min : d.z);
    while (d.x != min) leftOnce(d);
}

int judge(vector<Data> &vec, int n, int ln, int fa) {
    if (n != 0) {
        while (vec[n].y != vec[fa].)
    }
    flag = 1;
    for (int i = 0; i < vec[n].next.size(); i++) {
        judge(vec, vec[n].next[i], vec[n].line[i], n);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Data> vec;
    map<PII, int> ma;
    for (int i = 1; i <= m; i++) {
        Data d;
        cin >> d.x >> d.y >> d.z;
        d.l[0] = PII(d.x, d.y);
        d.l[1] = PII(d.y, d.x);
        d.l[2] = PII(d.x, d.z);
        d.l[3] = PII(d.z, d.x);
        d.l[4] = PII(d.y, d.z);
        d.l[5] = PII(d.z, d.y);
        for (int j = 0; j < 6; j++) {
            if (ma.find(d.l[j]) == ma.end()) {
                ma[d.l[j]] = m;
            } else {
                d.next.push_back(ma[d.l[j]]);
                d.line.push_back(j);
                vec[ma[d.l[j]]].next.push_back(m);
                int k = 0;
                for (;k <6; k++) {
                    if (d.l[j] == vec[ma[d.l[j]]].l[k]) break;
                }
                vec[ma[d.l[j]]].line.push_back(k);
                
            }
        }
        vec.push_back(d);
    }
    
    judge(vec, 0, -1, 0);
        
    return 0;
}
