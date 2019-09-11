/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月08日 星期日 19时03分39秒
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
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 2);
        cout << i * 2 << " " ;
    }
    cout << endl;

    for (auto i : vec) {
        cout << i << " ";
    }
    cout  << endl;
    return 0;
}
