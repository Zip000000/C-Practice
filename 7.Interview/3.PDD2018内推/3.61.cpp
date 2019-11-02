/*************************************************************************
	> File Name: 3.61.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 17时34分13秒
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
    int n;
    cin >> n;
    int *h = new int[n + 5];

    for (int i = 0; i < n; i++) cin >> h[i];
    int m;
    cin >> m;
    int *w = new int[m + 5];
    
    for (int i = 0; i < m; i++) cin >> w[i];

    sort(h, h + n);
    sort(w, w + m);
    
    int ans = 0, jj = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = jj; j >= 0; j--) {
            if (w[i] < h[j]) continue;
            ans += 1;
            jj = j - 1;
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}
