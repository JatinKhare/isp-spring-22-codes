//Final Pandemic: SIR Model
//May 4 2022
//
//Name: Jatin Khare
//UTEID: jk47976


#include<iostream>
#include<time.h>
#include<vector>

#define TOTAL_PEOPLE 40000
#define INTERACTIONS 10
#define ASYM_SICK_PROB 20
#define DEATH_PROB 10
#define MAKING_SICK_PROB 10
#define VACCINATION_PROB 25
#define VACC_SICK_PROB 10
#define ISOLATION_PROB 30

using std::cin;
using std::cout;
using std::endl;
using std::vector;

enum status_flags {
        HEALTHY,
        SICK,
        ASYMPTOTICALLY_SICK,
        RECOVERED,
        VACCINATED,
        DIED
} status_flags;

class Person {
        public:
        int status, days_sick, is_isolated;
        vector<int> interaction_v;

        Person(){
                status = HEALTHY;
                days_sick = 0;
                is_isolated = 0;
        }

        void make_sick(){
                if(status == HEALTHY){

                        bool prob10 = (rand() % 100) < ASYM_SICK_PROB;
                        if(prob10)
                                status = ASYMPTOTICALLY_SICK;
                        else
                                status = SICK;

                        days_sick++;
                }

                if(status == VACCINATED){
                        bool prob10 = (rand() % 100) < VACC_SICK_PROB;
                        if(prob10)
                                status = SICK;
                }
        }
        void recover(){
                status = RECOVERED;
                days_sick = 0;
        }
        void die(){
                status = DIED;
                days_sick = 0;
        }

        int GetStatus(){
                return status;
        }

        void update(){
                if((status == SICK || status == ASYMPTOTICALLY_SICK) && days_sick == 5){
                        bool prob10 = (rand() % 100) < DEATH_PROB;
                        if(prob10)
                                die();
                        else
                                recover();
                }
                if(status == SICK &&  days_sick != 5){
                        days_sick++;
                }
        }

        void fill_interaction_v(){
                for(int i = 0; i< INTERACTIONS; i++){
                        interaction_v.push_back(rand()%TOTAL_PEOPLE + 1);
                }
        }

        void vaccinate(){
                status = VACCINATED;
                //no need to set the days_sick as we will vaccinate healthy people only
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
                int count = 0;
                for(int i = 0;i< TOTAL_PEOPLE;i++){
                        if(population_v[i].status == HEALTHY)
                                count++;
                }
                return count;
        }

        int no_of_sick(){
                int count = 0;
                for(int i = 0;i< TOTAL_PEOPLE;i++){
                        if(population_v[i].status == SICK)
                                count++;
                }
                return count;
        }

        int no_of_asym_sick(){
                int count = 0;
                for(int i = 0;i< TOTAL_PEOPLE;i++){
                        if(population_v[i].status == ASYMPTOTICALLY_SICK)
                                count++;
                }
                return count;
        }

        int no_of_recovered(){
                int count = 0;
                for(int i = 0;i< TOTAL_PEOPLE;i++){
                        if(population_v[i].status == RECOVERED)
                                count++;
                }
                return count;
        }
        int no_of_vaccinated(){
                int count = 0;
                for(int i = 0;i< TOTAL_PEOPLE;i++){
                        if(population_v[i].status == VACCINATED)
                                count++;
                }
                return count;
        }
        int no_of_deaths(){
                int count = 0;
                for(int i = 0;i< TOTAL_PEOPLE;i++){
                        if(population_v[i].status == DIED)
                                count++;
                }
                return count;
        }
        int no_of_isolations(){
                int count = 0;
                for(int i = 0;i< TOTAL_PEOPLE;i++){
                        if(population_v[i].is_isolated == 1)
                                count++;
                }
                return count;
        }
};

int main() {

        /*things to implement
        1. Vaccination: Make a function to vaccinate people on a daily basis. Vaccinate a fixed number of healthy poeple.
        2. Isolation state: If a person is going to isolate himself/herself- they will not interact with anyone of their vectors.
        Make the interaction variable so that we can investigate herd immunity too. 
        Isolate the  sick people. Not the asymptomatically sick people. 
        3. Asymptomatic State: A new state. There you can propagate the virus even if isolation is on.
        */

        srand(time(NULL));
        Population Population_O;

        //each population will start out at TOTAL_PEOPLE persons.
        for(int i=0;i<TOTAL_PEOPLE;i++){
                Person Person_O;
                Population_O.add_person(Person_O);
        }

        //make the first person sick
        Population_O.population_v[0].make_sick();
        int day=1;
        int peak_sick = -1;
        while(1){ 
                //while loop for every day
                cout<<"Day = "<<day<<": "<<"Healthy = "<<Population_O.no_of_healthy();
                cout<<" Vaccinated = "<<Population_O.no_of_vaccinated();
                cout<<" Recovered = "<<Population_O.no_of_recovered();
                cout<<" Deaths = "<<Population_O.no_of_deaths();
                cout<<" Isolations = "<<Population_O.no_of_isolations();
                cout<<" Sick = "<<Population_O.no_of_sick()<<endl;

                day++;
                

                //infection drive
                for(int i=0;i<TOTAL_PEOPLE;i++){
                        if(Population_O.population_v[i].status == SICK || Population_O.population_v[i].status == ASYMPTOTICALLY_SICK){           //if the person is sick

                                //will he isolate?
                                bool prob10 = (rand() % 100) < ISOLATION_PROB;
                                if(Population_O.population_v[i].status == SICK && prob10){
                                        Population_O.population_v[i].is_isolated = 1;
                                        continue; //will not meet others. 
                                }

                                Population_O.population_v[i].fill_interaction_v(); //prepare its interaction vector
                                for(int j=0;j<INTERACTIONS;j++){
                                        bool prob10 = (rand() % 100) < MAKING_SICK_PROB;
                                        vector<int> susceptible_person = Population_O.population_v[i].interaction_v;

                                        if(prob10 && Population_O.population_v[susceptible_person[j]].status != VACCINATED)                      //make the 10 people sick with a probability of 0.1 each
                                                Population_O.population_v[susceptible_person[j]].make_sick();
                                }
                        }

                }

                //vaccination drive
                if(day>5){
                        for(int i=0;i<TOTAL_PEOPLE;i++){
                                if(Population_O.population_v[i].status == HEALTHY){         //if the person is healthy
                                        bool prob1 = (rand() % 100) < VACCINATION_PROB;
                                        if(prob1)
                                        Population_O.population_v[i].vaccinate();
                                }
                        }
                }
                for(int i = 0; i<TOTAL_PEOPLE; i++){
                        Population_O.population_v[i].update();
                }
                int sick_c = Population_O.no_of_sick();
                if(sick_c == 0){
                        break;
                }
                if(sick_c>peak_sick)
                        peak_sick = sick_c;
        }

        cout<<"Day = "<<day<<": "<<"Healthy = "<<Population_O.no_of_healthy();
        cout<<" Recovered = "<<Population_O.no_of_recovered();
        cout<<" Sick = "<<Population_O.no_of_sick()<<endl;
        cout<<endl<<"Total number of days for disease propagation: "<<day<<" days"<<endl;
        cout<<"Total number of healthy people = "<<Population_O.no_of_healthy()<<endl;
        cout<<"Total number of vaccinated people = "<<Population_O.no_of_vaccinated()<<endl;
        cout<<"Total number of recovered people = "<<Population_O.no_of_recovered()<<endl;
        cout<<"Total number of people died = "<<Population_O.no_of_deaths()<<endl;
        cout<<"Total number of isolated people = "<<Population_O.no_of_isolations()<<endl<<endl;
        cout<<"Peak number of sick people on a day in this pandemic = "<<peak_sick<<endl;
        cout<<"Total numbner of sick people = "<<Population_O.no_of_sick()<<endl;
        cout<<"Total numbner of asymptotically sick people = "<<Population_O.no_of_asym_sick()<<endl;
}
