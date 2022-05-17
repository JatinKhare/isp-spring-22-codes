//Homework #6: Pandemic: Objects
//Mar 31, 2022
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

class Person {
	public:
	int status, days_sick; 
	vector<int> interaction_v;

	Person(){
	//	cout<<"Inside default constructor of Point"<<endl;
		status = 0; 
		days_sick = 0;
	}

	void make_sick(){
		if(status == 0){
			status = 1;
			days_sick++;
		}
	}
	
	void recover(){
		status = 2;
		days_sick = 0;
	}

	int GetStatus(){
		return status;
        }

	void update(){
		if(days_sick == 5 && status == 1)
			recover();
		if(status == 1 &&  days_sick != 5){
			days_sick++; 
		}
	}

	void fill_interaction_v(){
		for(int i = 0; i< 10; i++){
			interaction_v.push_back(rand()%100 + 1);
		}
	}
};

class Population{
	public:
	vector<Person>population_v;

	Population(){
		;
	}

	void add_person(Person p){
		population_v.push_back(p);
	}

	int no_of_healthy(){
		int count;
		for(int i = 0;i< 100;i++){
			if(population_v[i].status == 0)
				count++;
		}
		return count;
	}	

	int no_of_sick(){
		int count;
		for(int i = 0;i< 100;i++){
			if(population_v[i].status == 1)
				count++;
		}
		return count;
	}	

	int no_of_recovered(){
		int count;
		for(int i = 0;i< 100;i++){
			if(population_v[i].status == 2)
				count++;
		}
		return count;
	}	
};

int main() {
	srand(time(NULL));
	Population Population_O;

	//each population will start out at 100 persons.
	for(int i=0;i<100;i++){
		Person Person_O;
		Population_O.add_person(Person_O);
	}

	//make the first person sick
	Population_O.population_v[0].make_sick();
	int day=1;
	int peak_sick = -1;
	while(1){
		/*cout<<"Day = "<<day<<": "<<"Healthy = "<<Population_O.no_of_healthy();
		cout<<" Recovered = "<<Population_O.no_of_recovered();
		cout<<" Sick = "<<Population_O.no_of_sick()<<endl; 
		*/
		day++;
		
		for(int i=0;i<100;i++){
			if(Population_O.population_v[i].status == 1){		//if the person is sick
				Population_O.population_v[i].fill_interaction_v(); //prepare its interaction vector
				for(int j=0;j<10;j++){
					bool prob10 = (rand() % 100) < 10;
					if(prob10)			//make the 10 people sick with a probability of 0.1 each
						Population_O.population_v[Population_O.population_v[i].interaction_v[j]].make_sick();
				}
			}
			
		}
		for(int i = 0; i<100; i++){
			Population_O.population_v[i].update();
		}			
		int sick_c = Population_O.no_of_sick();	
		if(sick_c == 0)
			break;

		if(sick_c>peak_sick)
			peak_sick = sick_c;
	}
	
	cout<<endl<<"Total number of days for disease propagation: "<<day<<" days"<<endl;
	cout<<"Total number of healthy people = "<<Population_O.no_of_healthy()<<endl;
	cout<<"Total number of inoculated (recovered) people = "<<Population_O.no_of_recovered()<<endl;
	cout<<"Total numbner of sick people = "<<Population_O.no_of_sick()<<endl; 
	cout<<"Peak number of sick people on a day in this pandemic = "<<peak_sick<<endl;
}
