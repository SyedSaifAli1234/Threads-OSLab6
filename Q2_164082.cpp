#include <iostream>
#include <string.h>
#include <cstring>
#include <unistd.h>
using namespace std;

struct Args{

   int number;

};

int k = 2;
int c = 0;
int arr[20];

int fib (int x);

void* Fibonacci(void* param){

	int num = 0;
	Args *test =(Args*) param;

    c = fib(test->number);

	for(int i = 0; i < c; i++){
		cout<<"array["<<i<<"] = "<<arr[i]<<endl;
	}
	c=0;
  	pthread_exit( (void*) test);
}


int fib (int x){
	k=2;
	arr[0] = 0;
	arr[1] = 1;

	while(arr[k-1] <= x){
		arr[k] = arr[k-2] + arr[k-1];
		k++;
		c++;
	}

	arr[k] = arr[k-2] + arr[k-1];
	return k;
}





int main(int argc, char** argv){
	cout<<endl;
	pthread_t id;
	Args argue[argc];
	int j = 1;

	for(int i=0; i< argc-1; i++){											//Assigning values
		argue[i].number = atoi((argv[j]));
		//cout<<"argv["<<i<<"] = "<<*argv[j]<<endl;
		cout<<"argue["<<i<<"].number = "<<argue[i].number<<endl<<endl;
		j++;
	}


	for(int i=0; i< argc-1; i++){
		usleep(1000000);
		if (pthread_create(&id, NULL, &Fibonacci, &argue[i])==-1){      //For loop to create
			cout<<"Thread Creation Failed!"<<endl;						//threads.
	     	return 1;
	  	}
	  	Args *fib;
		pthread_join(id, (void**) &fib);
		cout<<"Thread "<<i<<" finished"<<endl;
		// cout<<"Fibonacci series by Thread "<<i<<" = "; 
		// cout<<fib->number;
	}

	
	

	cout<<"exiting function"<<endl;
}









