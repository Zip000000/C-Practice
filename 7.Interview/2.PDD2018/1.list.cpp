/*************************************************************************
	> File Name: 1.list.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 13时48分21秒
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
    int offset, n, l1, l2;
    cin >> offset >> n >> l1 >> l2;
    int l1begin = 0, l2begin = 0, l1end = 0, l2end = 0;
    int l1rest = l1 - offset;
    if (l1rest <= 0) {
        l1begin = l1end = l1;

        l2begin = (offset - l1);
        if (l2begin >= l2) {
            l2begin = l2end = l2;
        } else {
            l2end = l2begin + n;
            if (l2end > l2) l2end = l2;
        }
    } else {
        l2begin = 0;
        l1begin = offset;
        l1end = l1begin + n;
        if (l1end > l1) {
            l1end = l1;
            l2end = n - (l1end - l1begin) - l2begin;
            if (l2end > l2) l2end = l2;
        }
    }
    cout << l1begin << " "<< l1end << " " << l2begin << " " << l2end << endl;

    return 0;
}
