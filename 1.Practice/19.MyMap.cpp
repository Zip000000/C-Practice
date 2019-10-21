/*************************************************************************
	> File Name: 19.Hash.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月14日 星期一 11时40分55秒
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
template<typename T, typename K>
struct mymap {
    using PII = pair<T, K>;
    PII arr[1000] = {};
    int hash(int k) {
        return (k) % 977;
    }
    int get_k(int key) {
        int k = hash(key);
        if (arr[k].first != 0) {
            int cnt = 0;
            while (arr[k].first != 0) {
                cnt += 1;
                if (arr[k].first == key) return -1;
                k = hash(cnt * k + cnt);
            }
        }
        return k;
    }
    int get_k_for_search(int key) {
        int k = hash(key);
        if (arr[k].first != 0) {
            int cnt = 0;
            while (arr[k].first != 0) {
                cnt += 1;
                if (arr[k].first == key) return k;
                k = hash(cnt * k + cnt);
            }
        }
        return -1;

    }
    int insert(T key, T val) {
        int k = get_k(key);
        if (k == -1) return -1;
        arr[k] = PII(key, val);
        cout << "key : " << key << "  k = " << k << "  val : " << val << endl; 
        return k;
    }

    int search(int key) {
        int k = get_k_for_search(key);
        if (k == -1) return -1;
        else return arr[k].second;
    }


};

int main()
{

    mymap<int, int> mp;

    srand(time(0));
    for (int i = 1; i <= 100; i++) {
        mp.insert(rand() % 10, rand() % 10000);
    }
    /*
    mp.insert(1, 9);
    mp.insert(3, 7);
    mp.insert(4, 6);
    mp.insert(4, 6);
    mp.insert(4865415, 100);
    mp.insert(12543, 101);
    */
    int key;
    while (cin >> key) {
        cout << mp.search(key) << endl;
    }
    return 0;
}
