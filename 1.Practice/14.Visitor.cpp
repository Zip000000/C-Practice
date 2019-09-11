/*************************************************************************
	> File Name: 14.Visitor.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 20时20分25秒
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

struct Animal {
    virtual void say() = 0;
};

struct Cat : public Animal {
    void say() {
        cut << "miao~~~" << endl;
    }
}

struct Dog : public Animal {
    void say() {
        cut << "Wang Wang~~~" << endl;
    }
};

struct Cat : public Animal {
    void say() {
        cut << "I Love Haizei~~~" << endl;
    }
};

int main() {
    
    
    
    return 0;
}
