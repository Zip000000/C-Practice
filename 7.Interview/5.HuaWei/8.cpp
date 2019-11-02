/*************************************************************************
	> File Name: 8.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月07日 星期六 14时08分54秒
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
    int n;
    cin >> n;
    unordered_map<int, int> hash;
    int key, val;
    for (int i = 0; i < n; i++) {
        cin >> key >> val;
        hash[key] += val;
    }
    
    
    return 0;
}
