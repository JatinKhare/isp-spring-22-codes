//In-Class Task #9: Objects: Line
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
	public:
	double xcoordinate, ycoordinate;
	Point(){
	//	cout<<"Inside default constructor of Point"<<endl;
		xcoordinate = 0; 
		ycoordinate = 0;
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


class Line {
	private:
	Point line_point1, line_point2;
	public:
	Line(){
	//	cout<<"Inside default constructor of Line"<<endl;
		line_point1.xcoordinate = 0;
		line_point1.ycoordinate = 0;
		line_point2.xcoordinate = 0;
		line_point2.ycoordinate = 0;
	}

	Line(Point point1, Point point2){
		line_point1.xcoordinate = point1.xcoordinate;
		line_point1.ycoordinate = point1.ycoordinate;
		line_point2.xcoordinate = point2.xcoordinate;
		line_point2.ycoordinate = point2.ycoordinate;
	};

	void display(){
		cout <<"Displaying the points from Line's display function.. "<<endl;
		cout<<"Point 1 = ";
		line_point1.display();
		cout<<"Point 2 = ";
		line_point2.display();
	};
	Point midpoint(){
		return Point((line_point1.xcoordinate + line_point2.xcoordinate)/2, (line_point1.ycoordinate + line_point2.ycoordinate)/2);
	};
};

int main() {
	Point point1(3,4);
	Point point2(9,12);
	Line line(point1, point2);
	cout<<endl;
	line.display();
	cout <<endl<<"Midpoint = ";
	line.midpoint().display();
	cout<<endl;

}
