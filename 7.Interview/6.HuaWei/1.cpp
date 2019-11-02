/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 19时01分16秒
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
    vector<int> vec;
    int tmp;
    while (cin >> tmp) {
        vec.push_back(tmp);
    }





    int max_sub = 0;
    for (int i = 1; i < vec.size() / 2; i++) {
        max_sub = (0 + i + vec[0 + i] > max_sub + vec[max_sub] ? 0 + i : max_sub);
    }
    int i = max_sub;
    int step = 1;
    while (1) {
        for (int j = 1; j <= vec[i]; j++) {
            max_sub = (i + j + vec[i + j] > max_sub + vec[max_sub] ? i + j : max_sub);
        }
        if (i == max_sub) break;
        i = max_sub;
        step += 1;
        if (max_sub + vec[max_sub] >= vec.size() - 1) break;
    }
    step += 1;
    if (max_sub + vec[max_sub] >= vec.size() - 1) {
        cout << step << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
