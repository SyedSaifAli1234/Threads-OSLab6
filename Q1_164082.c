#include <iostream>
using namespace std;
#include <string.h>

struct Args
{
   int length;
   char ** array;

};

void* myFunc(void* param)
{
  char *arr = new char;
  char *student=(char*) param;
   
  Student updatedStudent
  strcpy(arr, student);
  updatedStudent->rollNumber=10;

  pthread_exit( (void*) updatedStudent);
  // or u can use: return (void*) updatedStudent; 
  //do not use exit routine, it will terminate the whole process

}


int main()
{


  pthread_t id;
  Args argue;

  strcpy(std.name, "abc");
  std.rollNumber=1;
 
  if (pthread_create(&id, NULL, &myFunc, &std)==-1)
  {
      cout<<"Thread Creation Failed!"<<endl;
      return 1;
  }
  

  Student *updatedStd;
  pthread_join(id, (void**) &updatedStd);
  cout<<updatedStd->rollNumber;
}
