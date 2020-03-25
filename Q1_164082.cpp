#include <iostream>
using namespace std;
#include <string.h>

struct Args{

   int length;
   char ** array;

};

void* Average(void* param){
  float avg = 0;
  Args *test =(Args*) param;

  for(int i=1; i<test->length; i++){
       cout<<test->array[i]<<endl;
       avg = avg + atoi(test->array[i]);
  }
  test->length = test->length-1;
  avg = avg/test->length;

  test->length = avg;

  pthread_exit( (void*) test);
  // or u can use: return (void*) updatedStudent; 
  //do not use exit routine, it will terminate the whole process

}


void *maximum(void* param){

  int max = 0;
  Args *test =(Args*) param;

  for(int i=1; i<test->length; i++){
      if(atoi(test->array[i]) > max){
        max = atoi(test->array[i]);
      }
  }
  
  test->length = max;

  pthread_exit( (void*) test);

}

void *Minimum(void* param){

  int min = 10000;
  Args *test =(Args*) param;

  for(int i=1; i<test->length; i++){
      if(atoi(test->array[i]) < min){
        min = atoi(test->array[i]);
      }
  }
  
  test->length = min;

  pthread_exit( (void*) test);

}










int main(int argc, char** argv){


  pthread_t id;
  Args argue;
  Args argue2;
  Args argue3;

  argue.array = argv;
  argue.length = argc;

  argue2.array = argv;
  argue2.length = argc;

  argue3.array = argv;
  argue3.length = argc;

  if (pthread_create(&id, NULL, &Average, &argue)==-1){           //Average

      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }
  

  Args *average;
  pthread_join(id, (void**) &average);
  cout<<"\nAverage is = "<<average->length;




  if (pthread_create(&id, NULL, &maximum, &argue2)==-1){           //Maximum

      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }

  Args *max;
  pthread_join(id, (void**) &max);
  cout<<"\nMaximum is = "<<max->length;




  if (pthread_create(&id, NULL, &Minimum, &argue3)==-1){           //Minimum

      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }

  Args *min;
  pthread_join(id, (void**) &min);
  cout<<"\nMinimum is = "<<min->length;
  cout<<endl;
}









