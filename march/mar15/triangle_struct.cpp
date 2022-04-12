//Homeowrk 4: Triangle Struct
//March 15, 2022
//
//Name: Jatin Khare
//UTEID: jk47976


#include<iostream>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;
const double pi = 22.0/7.0;	

struct my_triangle{

float a, b, c;
float angle_A, angle_B, angle_C;

};


void calculate_values(struct my_triangle* triangle){


	triangle->c = sqrt(pow(triangle->a,2) + pow(triangle->b,2));
	cout<<"With a side a of "<<triangle->a<<" and a side b of "<<triangle->b<<endl;
	
	float angle_A_rd = atan(triangle->a / triangle->b);
	float angle_B_rd = atan(triangle->b / triangle->a);	

        //converting from radian to degrees	

	triangle->angle_A = angle_A_rd * 180/pi;
	triangle->angle_B = angle_B_rd * 180/pi;

}
int main () {
	struct my_triangle triangle_1, triangle_2;

	//taking user inputs and saving them in the c variables of the form double
	//cout<<"Enter side a: value"<<endl;
	//cin>>a;
	//cout<<"Enter side b value"<<endl;
	//cin>>b;
	
	//Hardcoding the values of a and b
	cout<<"Setting Triangle 1 sides to a = 3, b = 4 for the homework evaluation.."<<endl;	
	triangle_1.a  = 3;
	triangle_1.b = 4;
        //pass by reference
        calculate_values(&triangle_1);	

	cout<<"The hypotenuse is = "<<triangle_1.c<<endl; 
	cout<<"The angle 1 is = "<<triangle_1.angle_A<<" degrees "<<endl;
	cout<<"The angle 2 is = "<<triangle_1.angle_B<<" degrees "<<endl<<endl;

	cout<<"Setting Triangle 2 sides to a = 5, b = 12 for the homework evaluation.."<<endl;	
	triangle_2.a  = 5;
	triangle_2.b = 12;
        calculate_values(&triangle_2);	

	cout<<"The hypotenuse is = "<<triangle_2.c<<endl; 
	cout<<"The angle 1 is = "<<triangle_2.angle_A<<" degrees "<<endl;
	cout<<"The angle 2 is = "<<triangle_2.angle_B<<" degrees "<<endl;
	return 0;
}
 
