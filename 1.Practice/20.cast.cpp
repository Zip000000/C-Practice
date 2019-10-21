/*************************************************************************
	> File Name: 20.cast.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月15日 星期二 13时50分39秒
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
class Dog;
class Animal;

class Animal {
public:
    Animal() : _name("Default Name") { cout << "Animal cons" << endl; }
    //Animal(const Dog &d) : _name(d.name()) {}
    void say() { cout << "i am a animal" << endl; }
    int a = 2;
    string _name;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog() {
        this->_name = "golfee";
    }
    string name() const { return this->_name; }
    void say() { cout << "Wang wang ~~" << endl; }
};


int main() {
    /*
    static_cast
    dynamic_cast
    const_cast
    reinterpret_cast
    */
    Animal ani;
    Dog dog;
    Animal *a = dynamic_cast<Animal *>(&dog);
    Animal *p = &ani;
    Dog *d = dynamic_cast<Dog *>(p);
    if (d == nullptr) cout << "nullptr" << endl;
    return 0;
}


/*
 *
 *
 *
 *
    int i = 1;
    char c = static_cast<double>(i + 'A');
    cout << c << endl;

*/

