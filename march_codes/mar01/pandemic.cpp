//Homework #1 : Pandemic
//Mar 01, 2022
//
//Name: Jatin Khare
//UTEID: jk47976


#include<iostream>
#include<time.h>
using std::cin;
using std::cout;
using std::endl;

void joe_is_sick();

int main () {
	srand(time(NULL));
	
	int random_number;
	while(1){		                         //Looping until Joe gets sick
		random_number = rand();                
		//A random number between 0 and 100 determines if Joe gets sick
		//considering between means (0-99) as x%100 will give a number from 0 to (100-1) 
		int rand_less_100 = random_number % 100; //Generating a random number from 0 to 100
		if(rand_less_100 >= 10){		//if number >=10, Joe is healthy
			cout<<"Joe is well"<<endl;
		}
		else{
			joe_is_sick();			//once the number < 10, joe gets sick for 5 days
			break;
		}
	}

return 0;
}

void joe_is_sick(){
	int sick = 5;
	while(sick){
		cout<<"Joe is sick "<<sick<< " to go"<<endl;
		sick--;
	}
	//joe is sick for 5 days and then recovers
	cout<<"Joe is recovered"<<endl;
}
