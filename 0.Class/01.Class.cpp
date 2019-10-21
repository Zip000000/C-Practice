/*************************************************************************
	> File Name: 1.Class.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月10日 星期四 20时11分58秒
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

class Point {
public:
    Point() : _x(0), _y(0), _z(0) { this->_cnt += 1; }
    int x() const { this->_z += 1; return _x; }
    int y() { return _y; }
    int z() { return _z; }
    int cnt() { return Point::_cnt; }
private:
    int _x;
    int _y;
    mutable int _z;
    static int _cnt;
};

int Point::_cnt = 0;
int main() {
    Point p;

    cout << p.cnt() << endl;
    p.x();
    p.x();
    p.x();
    p.x();
    p.x();
    p.x();
    cout << p.z() << endl;

    return 0;
}
