/*************************************************************************
	> File Name: 09.succeed.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 13时35分56秒
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

class Data {
public:
    Data(int d) :_d(d) {
        cout << "Data " << this->_d << "is constructed over" << endl;
    }
private:
    int _d;
};

class Animal {
public :
    //Animal() {}
    Animal(const Animal &a) : _x(a._x + 1), _name(a._name) {}
    Animal(const string &name) : _name(name) {
        cout << "Animal Constructor" << endl;
    }
    Animal(const string &name, int x) : _name(name), _x(x) {}
    string name() { return this->_name; }
    ~Animal() {
        cout << "Animal Destructor" <<endl;
    }
    int x() { return this->_x; }
private :
    string _name;
    int _x;
};

class Cat : public Animal {
public :
    Cat() : Animal("cat-1") ,d1(100) ,d2(200) {
        cout << "Cat Constructor" << endl;
    }
    //Cat(string name, int x, int y) : Animal(name, x), _y(y) {}
    //Cat(const Cat &obj) : Animal(obj) ,_y(obj._y) {}
    ~Cat() {
        cout << "Cat Destructor" << endl;
    }
    int y() { return this->_y; }
private:
    int _y;
    Data d1, d2;
};

ostream &operator<<(ostream &out, Cat &a) {
    out << "<Class Cat> ";
    out << a.name() << " " << a.x() << " " << a.y() << endl;
    return out;
}
int main() {
    //Cat c1("hello kitty", 0, 54);
    //Cat c2(c1);
    Cat c1;
    cout << c1 << endl;
    //cout << c2 << endl;
    
    return 0;
}
