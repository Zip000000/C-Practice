/*************************************************************************
	> File Name: 44.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月12日 星期四 21时46分50秒
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

int get_ans(vector<int> &nums, int n) {

}

int main() {
    vector<int> nums;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }

    int ans = get_ans(nums, 0);
    cout << ans << endl;
    
    
    return 0;
}
