/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月13日 星期日 20时48分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>

#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    typedef pair<int, int> PII;
    set<PII> st;
    int tmp = 0, ii = 0;
    while (cin >> tmp) {
        st.insert(PII(tmp, ii++));
    }
    for (int i = 0; i < m; i++) {
        int a = st.begin()->first;
        st.erase(st.begin());
        int b = st.begin()->first;
        st.erase(st.begin());
        int cnt = 1;
        while (a == b) {
            cnt += 1;
            b = st.begin()->first;
            st.erase(st.begin());
        }
        if (cnt == 1) st.insert(PII(a + b, ii++)), cnt -= 1;
        while (cnt) {
            cnt -= 1;
            i += 1;
            if (i == m) {
                cout << a << endl;
                return 0;
            }
            st.insert(PII(a + b, ii++));
            if (!st.size()) b = st.begin()->first;
            if (cnt) st.erase(st.begin());
        }
    }
    cout << st.begin()->first << endl;
    return 0;
}
