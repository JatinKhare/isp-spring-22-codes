//Homework 5: Sick Joe Structure
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

struct Person{
int status;
int days_sick;
};

int sick_people_count = 0;
int healthy = 0;
int recovered = 0;
int make_sick(Person &x){
	
	if(x.status == 0){
		x.status = 1;
		x.days_sick++;
		healthy--;
		sick_people_count++;
		//cout<<"Sick people count = "<<sick_people_count<<endl;
	}
	return 0;
}

int recover(Person &x){
	x.status = 2;
	x.days_sick = 0;
	recovered++;
	x.status = 2;
	;
	return 0;
}

void keep_making_sick(vector<Person> &Friends){
	//cout<<"keep making sick.."<<endl;
	for(int i = 0; i<Friends.size(); i++){
		bool prob10 = (rand() % 100) < 10;
		if(prob10)
			make_sick(Friends[i]);
	}
}
void update(vector<Person> &Friends){
	//cout<<"updating.."<<endl;
	for(int i = 0; i<Friends.size(); i++){
		//cout<<"Recovered +  Healthy = "<<recovered + healthy<<endl;
		if(Friends[i].status == 1 && Friends[i].days_sick==5){
			recover(Friends[i]);
		}
		if(Friends[i].status == 1 && Friends[i].days_sick!=5){
			Friends[i].days_sick++;
		}
	}
}

void print_visuals(vector<Person> &Friends){
	for(int i = 0; i<Friends.size(); i++){

	if(Friends[i].status == 0)
		cout<<" Healthy   | ";
	else if(Friends[i].status == 1)
		cout<<" Sick ("<<Friends[i].days_sick<<")  | ";
	else
		cout<<" Recovered | ";

	}
	cout<<endl;
}

int main () {
	srand(time(NULL));
	int days_took = 0;
	vector<Person> Friends;
	sick_people_count = 0;
	for(int i = 0; i<5; i++){    //initializing the 'persons'
		Person p;
		p.status = 0;
		p.days_sick = 0;
		healthy++;
		Friends.push_back(p);
}
	make_sick(Friends[0]);
	days_took++;
	while(recovered + healthy != 5){
		days_took++;
		keep_making_sick(Friends);
		//print_visuals(Friends);
		update(Friends);
	}
	//print_visuals(Friends);
	cout<<"Number of people got sick = "<<sick_people_count<<", and the disease propagated for "<<days_took<<" days."<<endl;
	return 0;
}

 
