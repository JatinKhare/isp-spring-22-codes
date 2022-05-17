//In-Class Task #6: Vector Push Back
//Mar 10, 2022
//
//Name: Jatin Khare
//UTEID: jk47976


#include<iostream>
#include<time.h>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main () {
	srand(time(NULL));
	vector<int> v;
	
	while(1){
		int random_number = rand()%101;
		v.push_back(random_number);
		if(random_number == 42)
			break;
	}
	cout<<v.size()<<endl;

}

 
