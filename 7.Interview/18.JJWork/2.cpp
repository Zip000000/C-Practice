/*************************************************************************
	> File Name: 2.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年09月29日 星期日 10时25分46秒
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
void read(vector<int> &vec1, vector<int> &vec2) {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    //cout << str1 << endl << str2 << endl;
    int tmp = 0;
    int offset = 0;
    while (offset < str1.size()) {
        if (str1[offset] == ' ') offset += 1;
        offset += sscanf(str1.c_str() + offset, "%d ", &tmp);
        vec1.push_back(tmp);
    }
    offset = 0;
    while (offset < str2.size()) {
        if (str2[offset] == ' ') offset += 1;
        offset += sscanf(str2.c_str() + offset, "%d ", &tmp);
        vec2.push_back(tmp);
    }
}
int main() {
    vector<int> vec1, vec2;
    read(vec1, vec2);

    int sum = vec1.size() + vec2.size();
    int key = sum >> 1;
    if (sum & 1 == 0) key -= 1;
    int l1 = 0, r1 = vec1.size() - 1, l2 = 0, r2 = vec2.size() - 1;
    int mid1 = (l1 + r1) >> 1;
    int mid2 = (l2  + r2) >> 1;
    int drop = 0;
    while (drop != key) {
        if (l1 <= r1 && vec1[mid1] < vec2[mid2]) {
            drop += mid1 - l1 + 1;
            l1 = mid1 + 1;
        } else if (l2 <= r2 && vec1[mid1] > vec2[mid2]) {
            drop += mid2 - l2 + 1;
            l2 = mid2 + 1;
        } else {
            if (drop < key) {
                if (l1 <= r1) l1++;
                if (l2 <= r2) l2++;
            }
        }
        mid1 = (l1 + r1) >> 1;
        mid2 = (l2  + r2) >> 1;
    }
    if (sum & 1) {
        cout << vec1[l1] << endl;
    } else {
        cout << (vec1[l1] + vec2[l2] >> 1) <<endl;
    }


    return 0;
    
}
