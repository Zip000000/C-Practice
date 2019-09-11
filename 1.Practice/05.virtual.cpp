/*************************************************************************
	> File Name: 05.virtual.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月05日 星期一 12时20分47秒
 ************************************************************************/
#include <stdio.h>
#include <typeinfo>
#include<iostream>
#include<cstddef>
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
    Animal(string name) : _name(name) {}
    virtual void run() {
        cout << _name << " : Don't Know how to run" << endl;
    }
    string name() {
        return this->_name;
    }
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
private:
    string _name;
};

class Cat : public Animal {
public:
    Cat() : Animal("cat-1") {}
    void run() {
        cout << name() << " : Cat Run" << endl;
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
private:
};

class Bat : public Animal {
public:
    Bat() : Animal("bat-2") {}
    void run() {
        cout << name() << " : Bat Fly" << endl;
    }
    ~Bat() {
        cout << "Bat destructor" << endl;
    }
private:
};

class Dog : public Animal {
public:
    Dog() : Animal("Dog-3") {}
    void run() {
        cout << name() << " : Dog Rush" << endl;
    }
    ~Dog() {
        cout << "Dog destructor" << endl;
    }
private:
};

Animal *getAnimal () {
    int val = rand() % 3;
    switch (val) {
        case 0: return new Cat();
        case 1: return new Bat();
        case 2: return new Dog();
    }
    return nullptr;
}


int main() {
    srand(time(0));
    Animal **arr = new Animal*[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = getAnimal();
    }
    for (int i = 0; i < 20; i++) {
        arr[i]->run();
    }
    for (int i = 0; i < 20; i++) {
        delete arr[i];
    }
    
    
    
    return 0;
}
