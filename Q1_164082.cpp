#include <iostream>
using namespace std;
#include <string.h>

struct Args{

   int length;
   char ** array;

};

void* myFunc(void* param){

  Args *test =(Args*) param;

  for(int i=1; i<test->length; i++) 
       cout<<test->array[i]<<endl;

  pthread_exit( (void*) test);
  // or u can use: return (void*) updatedStudent; 
  //do not use exit routine, it will terminate the whole process

}


int main(int argc, char** argv){


  pthread_t id;
  Args argue;

  argue.array = argv;
  argue.length = argc;
 
  if (pthread_create(&id, NULL, &myFunc, &argue)==-1){

      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }
  

  Args *argue2;
  pthread_join(id, (void**) &argue2);

  cout<<"\nThread exiting\n";
}
