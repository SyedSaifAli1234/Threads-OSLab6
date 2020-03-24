#include <stdio.h>
#include <pthread.h>
#include <string.h>


int arr[50];
int n = 0;
int i = 0;

void *average(void* param){


	char a[10] = *(char*) param;
 	char *new_ptr = new int; 
 	*new_ptr = a;
 	printf("%s\n", *new_ptr);
	// int *new_ptr=new int; 
	// *new_ptr=a;
	// (*new_ptr)++;

 // 	pthread_exit( (void*) new_ptr);

	// int sum = 0;
	// float avg = 0;

	// printf("Input number ");
	// scanf("%d", &n);

	// for(i = 0; i < n; i++){
	// 	scanf("%d", &arr[i]);
	// }

	// for(i = 0; i<n; i++){
	// 	sum=sum+arr[i];
	// }

	// avg = sum/n;

	// printf("The average  is : %f",avg);
}

void *maximum(){
	
	int temp=arr[0];
	int i;

	for( i=1;i<n;i++){
		if(temp<arr[i]){
			temp=arr[i];
		}
	}
	printf("\nThe Maximum  is : %d",temp);	
}

void *Minimum(){
	
	int i;
	int temp=arr[0];

	for( i=1;i<n;i++){
		if(temp>arr[i]){
			temp=arr[i];
		}
	}

	printf("\nThe Minimum  is :%d",temp);

}



int main(int argc, char *argv[]){

int n, i;

pthread_t t1;
pthread_t t2;
pthread_t t3;


	n = pthread_create(&t1, NULL, &average, &argv);
	pthread_join(t1, NULL);

	//n = pthread_create(&t2, NULL, &Minimum, NULL);
	//pthread_join(t2, NULL);

    //n = pthread_create(&t3, NULL, &maximum, NULL);
	//pthread_join(t3, NULL);

}