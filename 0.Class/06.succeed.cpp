/*************************************************************************
	> File Name: 06.succeed.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月13日 星期日 18时26分16秒
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
    Animal(string name) : _name(name) {}
    const string &name() const { return this->_name; }
    virtual void func() {}
private:
    string _name;
};

class Cat : public Animal {
    
};

class Dog : public Animal {

};

class Monkey : public Animal {
    
};

string func(const Cat &a) {
    return a.name();
}

int main() {
    //Monkey m("haizei");
    //m.name();
        
    Cat c;
    cout << sizeof(c) << endl;
    
    string a;
    cout << sizeof(a) << endl;
    

    return 0;
}
