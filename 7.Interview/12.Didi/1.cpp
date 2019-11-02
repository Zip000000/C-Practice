/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月19日 星期四 19时35分10秒
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
int root;
int red[2] = {0};
struct UnionSet {
    int *fa, *val;
    void init(int n) {
        fa = new int[n + 5];
        val = new int[n + 5];
        for (int i = 1; i <= n; i++) fa[i] = i, val[i] = 0;
    }

    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }

    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) {
            red[val[aa]] += 1;
            return;
        }
        fa[aa] = bb;
        root = bb;
        val[aa] = (1 + val[b] - val[a] + 2) % 2;
        return;
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        u.merge(a, b);
    }
    int cnt = 0, cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        if (i == root) {
            if (u.val[i] == 0) cnt0 += 1;
            else cnt1 += 1;
            continue;
        }
        if (u.get(i) == i) cnt += 1;
        else if (u.val[i] % 2 == 0) cnt0 += 1;
        else cnt1 += 1;
    }

    int ans = 0;
    cnt1 -= red[1];
    cnt0 -= red[0];
    int min = (cnt1 > cnt0 ? cnt0 : cnt1);
    int max = (cnt1 > cnt0 ? cnt1 : cnt0);
    ans = ((min + cnt > max) ? 2 * max : 2 * (min + cnt));
    cout << ans << endl;
    
    return 0;
}
