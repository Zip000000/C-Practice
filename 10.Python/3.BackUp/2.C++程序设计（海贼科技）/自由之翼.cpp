#include<iostream>

using namespace std;

class Base{
    
public:
    int Minerals; //水晶
    
    Base(string new_Basename, int new_Minerals)
    {
        Basename=new_Basename;
        Minerals=new_Minerals;
    }
    
    void Built_SCV()
    {
        if(Minerals>=10)
        {
            time+=1;
            Minerals-=10;
            id+=1;
            scv_num+=1;
            cout<<"Time: "<<time<<"  "<<Basename<<" SCV "<<id
                <<" "<<"born with HP 10 "<<scv_num<<" "<<"SCV in base "<<Basename<<endl;
        }
        else
        {
            return;
        }
    }
    void Built_Marine()
    {
        if(Minerals>=5)
        {
            time+=1;
            Minerals-=5;
            id+=1;
            marine_num+=1;
            cout<<"Time: "<<time<<"  "<<Basename<<" Marine "<<id
                <<" "<<"born with HP 5 "<<marine_num<<" "<<"Marine in base "<<Basename<<endl;
        }
        else
        {
            return;
        }
    }   
    
	void Built_Medic()
    {
        if(Minerals>=4)
        {
            time+=1;
            Minerals-=4;
            id+=1;
            medic_num+=1;
            cout<<"Time: "<<time<<"  "<<Basename<<" Medic "<<id
                <<" "<<"born with HP 4 "<<medic_num<<" "<<"Medic in base "<<Basename<<endl;
        }
        else
        {
            return;
        }
    }
    
    void gameover()
    {
        cout<<"Time: "<<time<<"  "<<Basename<<" base stop training troopers."<<endl;
        return;
    }
    
private:
    string Basename;
    //string scv_name="SCV";
    //string marine_name="Marine";
    //string medic_name="Medic";
    int time=-1;
    int id=-1;
    int scv=0;
    int marine=0;
    int medic=0;
    int scv_num=0;
    int marine_num=0;
    int medic_num=0;

};

int main()
{
    int M;
    cin>>M;
    Base Raynor("Raynor",M);
    Base Mengsk("Mengsk",M);
    
    while(Raynor.Minerals>=4)
    {
        Raynor.Built_SCV();
        Raynor.Built_Marine();     
        Raynor.Built_Medic();
    }
    Raynor.gameover();   
        
	while(Mengsk.Minerals>=4)
    {

        Mengsk.Built_Marine();
        Mengsk.Built_Medic();
        Mengsk.Built_SCV();
    }
    Mengsk.gameover();   
    
    
	return 0;    
}