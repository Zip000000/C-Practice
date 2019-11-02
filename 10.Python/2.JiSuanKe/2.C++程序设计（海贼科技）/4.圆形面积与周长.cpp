#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
#define PI 3.14159
int main() {
	double r;
    cin>>r;
    cout<<fixed<<setprecision(3)<<2*PI*r<<endl;
    cout<<fixed<<setprecision(3)<<PI*r*r<<endl;
    

    return 0;
}