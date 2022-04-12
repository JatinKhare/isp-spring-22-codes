//In Class 5: Structures
//March 8, 2022
//
//Name: Jatin Khare
//UTEID: jk47976

#include<iostream>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;
//using namespace std;


struct point {
   float x;
   float y;
};
//Defining a new structe of line segment
struct line_segment {
    struct point P1;
    struct point P2;
};
float calc_distance(line_segment LS);

int main() {
   line_segment LS; //Defining the new instance of the structre and initializing the point values. 
   LS.P1.x = 3.;
   LS.P1.y = 4.;
   LS.P2.x = 2.;
   LS.P2.y = 2.;
   float dist = calc_distance(LS);
   cout << dist << endl;

}

 
float calc_distance(line_segment LS) {
   float dist = sqrt(pow(LS.P1.x - LS.P2.x,2)+pow(LS.P1.y - LS.P2.y,2));  //modified version of the formula
   return dist;
}
