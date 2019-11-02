#include <iostream>
#include <string>
using namespace std;

class People{
    
public:
    People(int new_number, string new_name, string new_gender, string new_ID, double new_salary)
    {
        cout<<"calling the constructor"<<endl;
        number=new_number;
        name=new_name;
        gender=new_gender;
        ID=new_ID;
        salary=new_salary;
    }
    People(People& pp)
    {
		cout<<"calling the copy constructor"<<endl;
        number=pp.number+1;
        name=pp.name;
        gender=pp.gender;
        ID=pp.ID;
        salary=pp.salary;
    }
    void set_name(string new_name)
    {
        name=new_name;
    }
    void set_salary(double new_salary)
    {
        salary=new_salary;
    }
    void show()
    {
        cout<<number<<" "<<name<<" "<<gender<<" "<<ID<<" "<<salary<<endl;
    }
    ~People(){
        cout<<"calling the destructor"<<endl;
    }
    
private:
    int number;
    string name;
    string gender;
    string ID;
    double salary;
};


int main() {
    People p1(01, "qratosone", "Male", "2010201326", 4800.0);
    People p2(p1);
    p2.set_name("He");
    p2.set_salary(301.301);
    p1.show();
    p2.show();
    string new_name;
    cin>>new_name;
    People p3(p2);
    p3.set_name(new_name);
    p3.show();
    return 0;
}