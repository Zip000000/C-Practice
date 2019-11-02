/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月29日 星期日 20时02分01秒
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
int arr[1000];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int ans  = 0;
    for (int i = 1; i <= n; i++) {
        while (arr[i] > 0) {
            ans += 1;
            arr[i] -= 1;
            arr[2 * i] -= 1;
            arr[2 * i + 1] -= 1;
        }
        
        while (arr[2 * i] > 0 && arr[2 * i + 1] > 0) {
            ans += 1;
            arr[2 * i] -= 1;
            arr[2 * i - 1] -= 1;
        }
    }
    cout << ans << endl;
    
    
    
    return 0;
}
