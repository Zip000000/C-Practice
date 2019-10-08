/*************************************************************************
	> File Name: 16.Visitor.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月07日 星期一 16时56分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <ctime>
using namespace std;
struct Cat;
struct Dog;
struct People;
struct Bat;

struct Animal {
    struct IVisitor {
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(People *) = 0;
        virtual void visit(Bat *) = 0;
    };
    virtual void say() = 0;
    virtual void Accept(IVisitor *) = 0;
};

struct Cat : Animal {
    void say() {
        cout << "miao miao miao" << endl;
    }
    virtual void Accept(IVisitor *vis) { vis->visit(this); }
};

struct Dog : Animal {
    void say() {
        cout << "Wang Wang Wang" <<endl;
    }
    virtual void Accept(IVisitor *vis) { vis->visit(this); }
};

struct People : Animal {
    void say() {
        cout << "I am a man" << endl;
    }
    virtual void Accept(IVisitor *vis) { vis->visit(this); }
};

struct Bat : Animal {
    void say() {
        cout << "Biu biu biu" << endl;
    }
    virtual void Accept(IVisitor *vis) { vis->visit(this); }
};

struct OutputVisitor : Animal::IVisitor {
    void visit(Cat *obj) {
        cout << "this is a Cat   from ov" << endl;
    } 
    void visit(Dog *obj) {
        cout << "this is a CDog   from ov" << endl;
    } 
    void visit(People *obj) {
        cout << "this is a People   from ov" << endl;
    } 
    void visit(Bat *obj) {
        cout << "this is a Bat   from ov" << endl;
    } 
};
struct OutputVisitor2 : Animal::IVisitor {
    void visit(Cat *obj) {
        cout << "[Cat]   from ov2" << endl;
    } 
    void visit(Dog *obj) {
        cout << "[Dog]   from ov2" << endl;
    } 
    void visit(People *obj) {
        cout << "[People]   from ov2" << endl;
    } 
    void visit(Bat *obj) {
        cout << "[Bat]    from ov" << endl;
    } 
};

Animal *getCat() {
    return new Cat;
}

Animal *getDog() {
    return new Dog;
}

Animal *getPeople() {
    return new People;
}
Animal *getBat() {
    return new Bat;
}

Animal *(*getFuncs[4])() = {getCat, getDog, getPeople, getBat};

int main() {
    srand(time(0));
    Animal *arr[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = getFuncs[rand() % 4]();
    }
    
    for (int i = 0; i < 20; i++) {
        OutputVisitor vis;
        OutputVisitor2 vis2;
        arr[i]->Accept(&vis);
        arr[i]->Accept(&vis2);
    }
    
    return 0;
}
