//In Class Challenge  #4 : Fibonacci
//Mar 01, 2022
//
//Name: Jatin Khare
//UTEID: jk47976


#include<iostream>
#include<time.h>
using std::cin;
using std::cout;
using std::endl;

int fibonacci_number(int n);

int main () {
	int input = 12;
	//cin>>input;
	
	//calculating the nth fibonacci number in non-recurcive fashion
	
	int f_0 = 0, f_1 = 1, f_nth;
	int f_n_1th = f_1;
	int f_n_2th = f_0;
	if(input == 0)
		f_nth = 0;
	else if (input == 1)
		f_nth = 1;
        else
		for(int i = 0; i < input - 1 ; i++){
			
			f_nth = f_n_1th + f_n_2th;
			f_n_2th = f_n_1th;
			f_n_1th = f_nth;
	}
	//cout<<"Fibonacci number non-recursively:"<< f_nth<<endl;
	//recursively
	int f_nth_rec  = fibonacci_number(input); 
	cout<<"Fibonacci number for n = "<<input<<" is "<< f_nth_rec<<endl;
return 0;
}

int fibonacci_number(int n){

if(n == 0)
return 0;
else if(n==1)
return 1;

else 
return fibonacci_number(n-1) + fibonacci_number(n-2);
}
