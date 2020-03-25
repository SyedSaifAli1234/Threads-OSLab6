#include <iostream>
#include <string.h>
#include <cstring>
#include <unistd.h>
using namespace std;

struct Args{

   int number;

};

int fibonacci (int x){
    if (x <= 1) {
        return 1;
    }
    return fibonacci(x-1) + fibonacci(x-2);
}


void* Fibonacci(void* param){
  int num = 0;
  int sum = 0;
  
  Args *test =(Args*) param;

  sum = fibonacci(test->number);

  test->number = sum;
  cout<<endl;
  
  pthread_exit( (void*) test);
  // or u can use: return (void*) updatedStudent; 
  //do not use exit routine, it will terminate the whole process

}









int main(int argc, char** argv){

	pthread_t id;
	Args argue[argc];
	int j = 1;

	for(int i=0; i< argc-1; i++){											//Assigning values
		argue[i].number = atoi((argv[j]));
		//cout<<"argv["<<i<<"] = "<<*argv[j]<<endl;
		cout<<"argue["<<i<<"].number = "<<argue[i].number<<endl;
		j++;
	}


	for(int i=0; i< argc-1; i++){
		usleep(100000);
		if (pthread_create(&id, NULL, &Fibonacci, &argue[i])==-1){      //For loop to create
			cout<<"Thread Creation Failed!"<<endl;						//threads.
	     	return 1;
	  	}
	  	Args *fib;
		pthread_join(id, (void**) &fib);
	
		cout<<"Fibonacci series by Thread "<<i<<" = "; 
		cout<<fib->number;
	}

	
	

	cout<<"exiting function"<<endl;
}









