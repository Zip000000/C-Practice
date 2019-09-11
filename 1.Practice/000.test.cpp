/*************************************************************************
	> File Name: 000.test.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 13时04分49秒
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

class Animal {
public:
    Animal() {
        cout << "Animal construct" << endl;
    }
};

class Cat : Animal {
public:
    Cat() {
        cout  << "Cat constructor" << endl;
    }
};


int main() {
    Cat a;



    return 0;
}
