/*************************************************************************
	> File Name: 17.AST.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月07日 星期一 20时14分29秒
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

class BaseNode {
public:
    using pNode = BaseNode *;
    BaseNode(pNode lchild = nullptr, pNode rchild = NULL) : _lchild(lchild), _rchild(rchild) {}
    pNode lchild() { return this->_lchild; }
    pNode rchild() { return this->_rchild; }
private:
    BaseNode *_lchild, *_rchild;

};

class NumberNode : public BaseNode {
public:
    NumberNode(int val) : _val(val) {}
    int getVal() { return this->_val; }
private:
    int _val;
};

enum class operatorType {
    PLUS,
    SUB,
    MUTIPLY,
    DIVISION,
    POW
};

class operatorNode : public BaseNode {
public:
    using pNode = BaseNode *;
    operatorNode(pNode lchild, pNode rchild, char ch) {
        switch (ch) {
            case '+':this->_type = operatorType::PLUS; break;
            case '-':this->_type = operatorType::SUB; break;
            case '*':this->_type = operatorType::MUTIPLY; break;
            case '/':this->_type = operatorType::DIVISION; break;
            case '^':this->_type = operatorType::POW; break;
        }
    }
private:
    operatorType _type;
};

BaseNode *_build(const string &str, int l, int r) {
    int pos = -1, pri = INF - 1, temp = 0;
    for (int i = l; i <= r; i++) {
        int cur_pri = INF;
        switch(str[i]) {
            case '(':
        }
    }
}
BaseNode *build(const string &str) {
    return _build(str, 0, str.length() - 1);
}




int main() {
    
    
    
    return 0;
}
