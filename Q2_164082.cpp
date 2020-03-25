#include <iostream>
using namespace std;
#include <string.h>

struct Args{

   int number;

};

void* Fibonacci(void* param){
  int num = 0;
  Args *test =(Args*) param;

  for(int i=1; i<test->length; i++){

       avg = avg + atoi(test->array[i]);

  }

  test->length = test->length-1;
  avg = avg/test->length;

  test->length = avg;

  pthread_exit( (void*) test);
  // or u can use: return (void*) updatedStudent; 
  //do not use exit routine, it will terminate the whole process

}









int main(int argc, char** argv){

	pthread_t id;
	Args argue[argc];
	int j = 1;

	for(int i=0; i< argc-1; i++){											//Assigning values
		argue[i].array = *argv[j];
		j++;
	}


	for(int i=0; i< argc-1; i++){
		if (pthread_create(&id, NULL, &Fibonacci, &argue[i])==-1){      //For loop to create
			cout<<"Thread Creation Failed!"<<endl;						//threads.
	     	return 1;
	  	}

	  	Args *fib;
		pthread_join(id, (void**) &fib);
		
		cout<<"Fibonacci series by Thread "<<i<<" = "; 
		for(int i = 0; i < argc; i++){
			cout<<fib->array[i];
		}
	}
}









