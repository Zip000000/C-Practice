/*************************************************************************
	> File Name: 22.Observer.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年10月15日 星期二 20时03分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include <list>
using namespace std;
// 观察者类 同学们 要有update方法
class Observer {
public:
    virtual ~Observer() {}
    virtual const string name() const = 0;
    virtual void update(const string &words) = 0;
};

class Student : public Observer {
public:
    Student(const string &name) : _name(name) {}
    const string name() const { return _name; }
    void update(const string &);
private:
    string _name;
    string news;
};
void Student::update(const string &words) {
    news = words;
    cout << "我是 " << _name << "  老师说：" << news << endl;
}

//主题类 被观察者类 老师 ，要维护所有的同学，有事通知所有人
class Subject {
public:
    virtual ~Subject() {}
    virtual void attach(Observer *) = 0;
    virtual void dettach(Observer *) = 0;
    virtual void send_all(const string &) = 0;
};

class Teacher : public Subject {
public:
    void attach(Observer *obs) {
        lst.push_back(obs);
    }

    void dettach(Observer *obs) {
        for (auto iter = lst.begin(); iter != lst.end(); iter++) {
            if (*iter != obs) continue;
            lst.erase(iter);
            break;
        }
    }
    
    void send_all(const string &mes) {
        for (auto iter = lst.begin(); iter != lst.end(); iter++) {
            Observer *tmp = *iter;
            tmp->update(mes);
        }
    }
private:
    list<Observer *> lst;
};


int main() {
    
    Student *a = new Student("志鹏");
    Student *b = new Student("黄鑫");
    Student *c = new Student("俊明");

    Teacher t;
    t.attach(a);
    t.attach(b);
    t.attach(c);

    t.send_all("老师要打死你");


    
    
    
    return 0;
}
