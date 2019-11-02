/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月20日 星期五 19时57分41秒
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

int get_lesstmp(int mark, int tmp) {
    int i = 1;
    for (i = 1; i <= 10; i++) {
        if ((mark * 20 + i) * i > tmp) break; 
    }
    cout << "itis : " << (mark * 20 + i) * i << endl;
    cout << "less = " << i - 1 << endl;
    return i - 1;
}
int get_min(int n, int *mark) {
    for (int i = 1; i <= 10; i++) {
        if (i * i > n) {
            i -= 1;
            *mark = i;
            return i * i;
        }
    }
}

int get_sqr(int num) {
    int arr[5] = {0};
    int tmpnum = num, cnt = -1;
    while (tmpnum) {
        arr[++cnt] = tmpnum % 100;
        tmpnum /= 100;
    }
    int mark = 0;
    int flag = 1;
    int first = 1;
    while (flag) {
        arr[cnt] -= get_min(arr[cnt], &mark);
        int tmp = arr[cnt] * 100; 
        if (first) arr[cnt] = mark, first = 0;
        //cout << cnt <<  " : arr[cnt] = " << arr[cnt] << endl;
        if (cnt - 1 >= 0) {
            tmp += arr[--cnt];
        } else flag = 0;
        arr[cnt] = get_lesstmp(mark, tmp);
        if (cnt == 0) break;
    }
    int ret = 0;
    for (int i = 4; i >= 0; i--) {
        ret *= 10;
        ret += arr[i];
    }

    return ret;

}

int main() {
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        //cout << "cin : " << num << endl;
        /*
        i == 0 || cout << " ";
        cout << get_sqr(num);
        */
        cout << "my : " << get_sqr(num) << "   :   " <<  sqrt(num) << endl;
    }
    cout << endl;
    return 0;
}
