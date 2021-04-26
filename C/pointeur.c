#include "stdio.h"

int main(){
	int arr[5]  =	{10, 20, 25, 33, 44};
	int *test;
	test = &arr;

	int i = 0;
	while((*test) != 25){	
		test = &arr[i];
		printf("%d \n", *test);
		i++;
	}
}
