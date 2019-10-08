/*************************************************************************
	> File Name: 17.single.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月07日 星期一 20时57分11秒
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

class SingleClass {
public:
    static SingleClass *getInstance() {
        static SingleClass *obj = nullptr;
        if (obj) return obj;
        obj = new SingleClass;
        return obj;
    };
private:
    SingleClass() {}  //默认构造
    SingleClass(SingleClass &obj) {} // 拷贝构造
};

int main() {
    SingleClass *a = SingleClass::getInstance();
    //SingleClass b(SingleClass::getInstance()); 防止这种情况发生           
    
    return 0;
}



