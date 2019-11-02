#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
int main() {
    double d,h,c;
    cin>>d>>h;
    c=sqrt(d*d+h*h);
    cout<<fixed<< std::setprecision(2)<<c+d+h<<endl;
    cout<<fixed<< std::setprecision(2)<<0.5*d*h<<endl;

    
    


    return 0;
}