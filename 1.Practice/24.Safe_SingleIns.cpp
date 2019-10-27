/*************************************************************************
	> File Name: 24.Safe_SingleIns.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月23日 星期三 13时26分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <memory>
#include <mutex>
using namespace std;

class SingleIns {
public:
    ~SingleIns() { cout << "destruct" << endl; }
    static shared_ptr<SingleIns> get_Ins() {
        static shared_ptr<SingleIns> p;
        if (p == nullptr) {
            lock_guard<mutex> guard(SI_mutex);
            if (p == nullptr) p = shared_ptr<SingleIns> (new SingleIns);
        }
        return p;
    }

    static mutex SI_mutex;
private:
    SingleIns() { cout << "construct" << endl; }
    SingleIns(const SingleIns &) {}
    SingleIns& operator=(const SingleIns &) {}
};
mutex SingleIns::SI_mutex;

int main() {
    shared_ptr<SingleIns> p = SingleIns::get_Ins();
    shared_ptr<SingleIns> p1 = SingleIns::get_Ins();
    shared_ptr<SingleIns> p2 = SingleIns::get_Ins();

    return 0;
}
