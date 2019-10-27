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
    virtual int operator()(int k) { return k % _size; } //defalt;
    virtual ~HashFunc() {} ;
};
static HashFunc defaulthash;

class HashA : public HashFunc {
public:
    int operator()(int k) { return (3 * k + 5) % _size; }
};
class HashTable {
using PII = pair<int, int>;
public:
    HashTable(int size) : _size(size), hash(defaulthash) {
        vec.resize(size);
        hash._size = this->_size;
    }
    HashTable(int size, HashFunc &hf) : _size(size), hash(hf) {
        vec.resize(size);
        hash = hf;
        hf._size = this->_size;
    }
    void insert(int key) {
        if (_cnt == _size) return;
        int k = hash(key);
        int i = 1;
        while (1) {
            if (vec[k] == 0) {
                vec[k] = k;
                _cnt += 1;
                return ;
            } else {
                k = hash(k + i);
                i++;
            }
        }
    }
    int query(int key) {
        int k = hash(key);
        int i = 1;
        while (1) {
            if (vec[k] == k) {
                return 1;
            } else {
                k = hash(k + i);
                i += 1;
                if (i > _size) { return -1; }
            }
        }
    }
private:
    int _size, _cnt;
    HashFunc &hash;
    vector<int> vec;
};

int main() {
    HashA hashfunc;
    HashTable h(1000, hashfunc);
    srand(time(0));
    for (int i = 0; i < 500; i++) {
        int key = rand() % 100000;
        h.insert(key);
        cout << "key = " << key << "   query[key] = " << h.query(key) << endl;
    }
    return 0;
}

/*
class HashBKDR : public HashFunc {
public:
    unsigned int operator() (char *str) {
        unsigned int seed = 131313;
        unsigned int hash = 0;
        while (*str) {
            hash = hash * seed + (*str++);
        }
        return hash % 0x7fffffff;
    }
};
*/
