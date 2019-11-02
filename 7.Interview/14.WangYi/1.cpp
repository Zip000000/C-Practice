/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月21日 星期六 14时58分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> ma;
    int key;
    for (int i = 0; i < n; i++) {
        cin >> key;
        ma[key] += 1;
    }
    int tmp;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        cout << ma[tmp] << endl;
    }
    
    
    
    return 0;
}
