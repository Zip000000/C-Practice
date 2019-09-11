/*************************************************************************
	> File Name: 03.inherit.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月04日 星期日 15时39分43秒
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
public :
    Data() {}
    Data(const string &data) {
        cout << data << endl;
    }
};

class Animal {
public:
    Animal(const string &name, int x = 0) : 
    d2("I'm d2"), d1("I'm d1"), _name(name), _x(x) {
        cout << "Animal Constructor" << endl;
    }
    //Animal(const string &name, int x) : _name(name), _x(x) {}
    Animal(const Animal &a) : _x(a._x + 1), _name(a._name) {}
    int x() { return this->_x; }
    string name() {return this->_name;}
    void run() {
        cout << "I am " << this->name();
        printf("I can run!\n");
    }
    ~Animal() {
        cout << "Animal Destructor" << endl;
    }
private:
    Data d1, d2;
    string _name;
    int _x;
};

class Cat : public Animal {
public:
    Cat() : Animal("cat-1") {
        cout << "Cat Constructor" << endl;
    }
    Cat(const Cat &obj) : Animal(obj), _y(obj._y) {}
    Cat(string name, int x, int y) : Animal(name, x), _y(y) {} 
    int y() {return this->_y;}
    void run() {
        printf("[Cat Run]I can run like a cat\n");

    }
    ~Cat() {
        cout << "Cat Destructor" << endl;
    }
private:
    int _y;
};

ostream &operator<<(ostream &out, Cat &a) {
    out << "<Class Cat> ";
    out << a.name() <<" " << a.x() << " " << a.y();
    return out;
}

int main() {
    Cat c1("HelloKitty", 0, 54);
    Cat c2(c1);
    cout <<c1.name()<<endl;
    cout << c1 <<endl;
    cout << c2 <<endl;

    Animal a("ani");
    a.run();
    c1.run();
    cout << "-------------" << endl;
    Animal *x = &c1;
    x->run();

    return 0;
}
