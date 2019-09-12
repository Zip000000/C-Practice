/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月12日 星期四 09时18分20秒
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    int maxnum = max(vec[0], vec[vec.size() - 1]);
    int minnum = min(vec[0], vec[vec.size() - 1]);
    double midnum;
    if (vec.size() & 1) {
        midnum = vec[vec.size() / 2];
    } else {
        midnum = (vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2.0;
    }
    cout << maxnum << " " << midnum  << " " << minnum << endl;
    return 0;
}
