/*************************************************************************
	> File Name: 10.virtual.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月30日 星期五 15时14分01秒
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
    Animal() {}
    Animal(const string name) { this->_name = name; }
    virtual void run() = 0;
    virtual ~Animal() {
        cout << "Animal Destructor" << endl;
    }
private:
    string _name;
};

class Cat : public Animal {
public:
    Cat() {}
    Cat(const string name) : Animal(name) {}
    void run() override {
        cout << "Cat run" << endl;
    }
    ~Cat()  {
        cout << "Cat Destructor" << endl;
    }
private:

};

class Dog : public Animal {
public:
    Dog() {}
    Dog(const string name) : Animal(name) {}
    void run() override {
        cout << "Dog run" << endl;
    }
    ~Dog()  {
        cout << "Dog Destructor" << endl;
    }
};

class Bat : public Animal {
public:
    Bat() {}
    Bat(const string name) : Animal(name) {}
    void run() override {
        cout << "Bat run" << endl;
    }
    ~Bat() {
        cout << "Bat Destructor" << endl;
    }
};

int main() {
    Cat *c = new Cat("cat-1");
    Dog d("dog-1");
    Bat b("bat-1");
    
    c->run();
    d.run();
    b.run();
    
    Animal **a = new Animal*[3];
    a[0] = c;
    a[1] = &d;
    a[2] = &b;
    for (int i = 0; i < 3; i++) {
        a[i]->run();
        //delete a[i];
    }
    delete a[0];
    
    
    return 0;
}
