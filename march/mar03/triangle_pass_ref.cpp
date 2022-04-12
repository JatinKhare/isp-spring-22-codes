//Homeowrk 3: Triangle pass by refernce  
//March 3, 2022
//
//Name: Jatin Khare
//UTEID: jk47976

//iostream is for input-output stream
///////Use only those headers which are neccessary///////
//:: Binary scope resolution operator.

#include<iostream>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;
//using namespace std;
const double pi = 22.0/7.0;	

void calculate_values(double *a, double *b, double *c, double *angle_A_deg, double *angle_B_deg){


	*c = sqrt(pow(*a,2) + pow(*b,2));
	cout<<"With a side a of "<<*a<<" and a side b of "<<*b<<endl;
	
	double angle_A_rd = atan(*a / *b);
	double angle_B_rd = atan(*b / *a);	

        //converting from radian to degrees	

	*angle_A_deg = angle_A_rd * 180/pi;
	*angle_B_deg = angle_B_rd * 180/pi;

}
int main () {
	double a, b, c;
	double angle_A_deg;
	double angle_B_deg;
	//taking user inputs and saving them in the c variables of the form double
	//cout<<"Enter side a value"<<endl;
	//cin>>a;
	//cout<<"Enter side b value"<<endl;
	//cin>>b;
	
	//Hardcoding the values of a and b
	cout<<"Setting a = 3, b = 4 for the homework evaluation.."<<endl;	
	a = 3;
	b = 4;
        //pass by reference
        calculate_values(&a, &b, &c, &angle_A_deg, &angle_B_deg);	

	cout<<"The hypotenuse is = "<<c<<endl; 
	cout<<"The angle 1 is = "<<angle_A_deg<<" degrees "<<endl;
	cout<<"The angle 2 is = "<<angle_B_deg<<" degrees "<<endl;
	return 0;
}
 
