//In-Class Task #2: Head-Tail 
//Feb 15, 2022
//
//Name: Jatin Khare
//UTEID: jk47976


#include<iostream>
#include<time.h>
using std::cin;
using std::cout;
using std::endl;
//using namespace std;
int main () {
	srand(time(NULL));
	
	int loop_count = 1000000;	//Intializing the Loop count
	int random_number, count_heads, count_tails; //Declaring the variables

	for(int i = 0; i<loop_count; i++){
		random_number = rand();		//Generating a random number
		if(random_number%2){
			cout<<"Heads"<<endl;	//Printing head for every odd number
			count_heads++;		//Incrementing the head counter for every head printed
		}
		else{
			cout<<"Tails"<<endl;	//Printing tails for every even number
			count_tails++;          //Incrementing the tails counter for every tail printed
		}
}

	cout<<"Total number of Heads = "<<count_heads<<endl;	//Printing the final answers
	cout<<"Total number of Tails = "<<count_tails<<endl;

}

 
