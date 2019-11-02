/*************************************************************************
	> File Name: 1.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月25日 星期三 21时08分31秒
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
#define MAX_N 1024
char n[MAX_N + 5] = {0};
char *a_x_b(const char *a, int len1, const char *b, int len2) {
    char *ret = (char *)calloc(sizeof(char), MAX_N + 5);

}
bool more_than_n(char *k, int digit) {
    
}
int main() {
    char k[MAX_N + 5] = {1};   
    int digit = 0;
    scanf("%s", n);
    
    while (!more_than_n(k, digit)) {
        k[digit] = '0';
        k[++digit] = '1';
    }
    k[digit] = '0';
    k[--digit] = '1';

    
    return 0;
}
