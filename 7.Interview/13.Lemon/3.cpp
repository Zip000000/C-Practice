/*************************************************************************
	> File Name: 3.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月20日 星期五 19时03分16秒
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
int arr[7][7];

int get_ans(int i, int j) {
    if (i > 5 || j > 5) return 0;
    if (i == 5 && j == 5) return arr[i][j];
    int ans1 = get_ans(i + 1, j);
    int ans2 = get_ans(i, j + 1);
    return max(ans1, ans2) + arr[i][j];

}

int main() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    ans = get_ans(0, 0);
    cout << ans << endl;
    return 0;
}
