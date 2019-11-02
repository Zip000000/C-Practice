#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class student
{
public:
    student(string _name,int _score)
    {
        name=_name;
        score=_score;
    }
    
    void insert(string _name,int _score)
    {
        
    }
    
    void showAll()
    {
        cout<<name<<" "<<score<<endl;
    }
    
    string name;
    int score;
};

bool cmp(student s1,student s2)
{
    if(s1.score!=s2.score)
    {
        return s1.score<s2.score;
    }
    else
    {
        return s1.name<s2.name;
    }
}

int main()
{
    vector <student> stdt;
    
    int temp_score;
    string temp_name;
    while(cin>>temp_name>>temp_score)
    {
        student temp(temp_name,temp_score);
        stdt.push_back(temp);
    }
    
    sort(stdt.begin(),stdt.end(),cmp);
        
    for(int i=0;i<stdt.size();i++)
    {
        stdt[i].showAll();
    }
    cout<<stdt.size();
    
    
    return 0;
}