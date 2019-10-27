/*************************************************************************
	> File Name: 08.HashFunc.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月26日 星期六 16时24分26秒
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
class HashFunc {
public:
    int _size = 1;
    virtual int operator()(int) = 0;
};
class HashDefault : public HashFunc {
public:
    int operator()(int k) { return k % _size; } //defalt;
};
static HashDefault default_hash;

class HashA : public HashFunc {
public:
    int operator()(int k) { return (3 * k + 5) % _size; }
};

class HashTable {
using PII = pair<int, int>;
public:
    explicit HashTable(int size) : _size(size), hash(default_hash)  {
        vec.resize(size);
        hash._size = this->_size;
    }
    HashTable() : HashTable(1000) {}
    HashTable(int size, HashFunc &hf) : _size(size), hash(hf) {
        vec.resize(size);
        hash = hf;
        hf._size = this->_size;
    }
    int &operator[] (int key) {
        int k = hash(key);
        int i = 1;
        while (1) {
            if (vec[k].first == 0) { //可插入
                vec[k].first = key;
                _cnt += 1;
                return vec[k].second;
            } else if (vec[k].first == key) { //已存在
                vec[k].first = key;
                return vec[k].second;
            } else {
                k = hash(k + i);
                i++;
                if (i > _size) {
                    return tmp; 
                }
            }
        }
    }
private:
    int _size, _cnt;
    HashFunc &hash;
    vector<PII> vec;
    int tmp = -1;
};

int main() {
    HashA hashfuncA;
    HashTable h(1000, hashfuncA);
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int key = rand() % 100000;
        int val = key + 1;
        h[key] = val;
        cout << "key = " << key << "   h[key] = " << h[key] << endl;
    }
    return 0;
}
