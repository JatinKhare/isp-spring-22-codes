//In-Class Task #8: Objects: Points
//
//Mar 29, 2022
//
//Name: Jatin Khare
//UTEID: jk47976


#include<iostream>
#include<time.h>
#include<vector>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;

class Point {
	private:
	double xcoordinate, ycoordinate;
	public:
	Point(){
	//	cout<<"Inside default constructor of Point"<<endl;
		xcoordinate = 1; 
		ycoordinate = 1;
	}

	Point(double x1, double y1){
		xcoordinate = x1;
		ycoordinate = y1;
	};

	int display(){
		cout<<"(xcoordinate, ycoordinate) = ("<<xcoordinate<<", "<<ycoordinate<<")"<<endl;
		return 1;
	};

	float distance(Point point2){
		return sqrt(pow((xcoordinate - point2.xcoordinate),2) + pow((ycoordinate - point2.ycoordinate),2));
	};
	
	float distance_to_origin(){
		return sqrt(pow((xcoordinate),2) + pow((ycoordinate),2));
	};
};


int main() {
	Point point1(3,4);
	Point point2(9,12);
	cout <<endl<<"Displaying the points.. "<<endl;
	cout<<"Point 1 = ";
	point1.display();
	cout<<"Point 2 = ";
	point2.display();
	cout <<endl<<"Distance between points = "<<point1.distance(point2)<< endl;
	cout << "Distance of Point 1 from the origin = "<<point1.distance_to_origin()<< endl;

}
