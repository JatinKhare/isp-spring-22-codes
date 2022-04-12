//In-Class Task #7: Vector Push Back Pass By Reference
//Mar 24, 2022
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

vector<int> combineV(vector<int> A, vector<int> B){

	vector<int> C;

	while(A.size()>0){
		C.push_back(A[0]);   //put the element
		A.erase(A.begin());  //delete that element from V1
	}
	while(B.size()>0){
		C.push_back(B[0]);
		B.erase(B.begin());
	}

	return C;

}

int main () {
	vector<int> V1;
	vector<int> V2;
	vector<int> V3;
	
	for(int i = 0; i< 10; i++){
		V1.push_back(i*2);
		V2.push_back(i*3);
	}
	
	V3 = combineV(V1, V2);
        
        for(auto &t : V3){
		cout<<t<<' ';
	}
	cout<<endl;
	return 0;
}

 
