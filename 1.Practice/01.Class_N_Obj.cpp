/*************************************************************************
	> File Name: 01.Class_N_Obj.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年07月22日 星期一 20时58分35秒
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
public :
    Point() : _x(0), _y(0), _cnt(0) {
        Point::total += 1;
    }
    //Point(int x, int y) : _x(x), _y(y), _cnt(0) {   //初始化列表
    Point(int x, int y) : Point() {   //委托构造
        this->_x = x;
        this->_y = y;
        //Point::total += 1;   因为委托构造 可以去掉这一行
        cout << "有参构造\n" << endl;
    }
    Point(const Point &b) : Point() {
        this->_x = b._x;
        this->_y = b._y;
        this->_cnt = b._cnt;
    }
    int getX() const {
        this->_cnt += 1;
        return this->_x; 
    }
    int getY() const {
        return this->_y; 
    }
    static int getTotal() {return Point::total;}

    ~Point() {
        this->total -= 1;
        printf("析构\n");
    }
private:
    int _x, _y;
    mutable int _cnt;
    static int total;
};

int Point::total = 0;

ostream& operator<<(ostream &out, const Point &p) {
    out << "(" <<   p.getX() << "," << p.getY() << ")" << endl;;
    return out;
}
void func2() {
    Point a, b, c;
}
int main() {
    Point p1(2, 3), p2(3, 4);
    cout << p1.getX() << " " << p1.getY() << endl;
    func2();
    cout << p1 << p2;
    cout << Point::getTotal() << endl;
    
    return 0;
}
