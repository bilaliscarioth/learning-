#include "stdio.h"

int main(){
  int arr = 20;
  int *test;
  test = &arr;

  printf(">> %x \n", &arr);
  printf(">> %x \n", test);
  if(!test)
    test = &arr;
  printf(">> %d \n", arr);
  printf(">> %d \n", *test);

}
