/*************************************************************************
	> File Name: 10.HashFunc.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月27日 星期日 14时57分10秒
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

class Node {
public:
    char *get_str() { return this->str; }
    void set_str(const char *str) {
        this->str = strdup(str);
        return ;
    }
private:
    bool flag;
    char *str;
};

class HashFunc {
public:
    virtual int operator()(const char *str) const = 0;
};

class HashTable {
public:
    HashTable(const HashFunc &func);
    bool insert(const char *str);
    bool find(const char *str);
private:
    int _size;
    Node *data;
    const HashFunc *p_func;
};

int main() {

    
    
    return 0;
}

HashTable::HashTable(const HashFunc &func) : p_func(&func) {
    this->_size = 100;
    this->data = new Node[this->_size];
}
bool HashTable::insert(const char *str) {
}

class BKDRHash : public HashFunc {
public:
    int operator()(const char *str) const {
        int seed = 31; //种子  seed进制的数字
        int hash_value = 0;
        for (int i = 0; str[i]; i++) {
            hash_value = hash_value * seed + str[i];
        }
        return hash_value & 0x7fffffff;
    }
};
