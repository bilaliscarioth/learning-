#include "stdio.h"

int main(){
  int arr = 20;
  int *test; //Pointeur.
  test = &arr; // On met vers la bonne ref

  printf(">> %x \n", &arr);
  printf(">> %x \n", test);

  printf(">> %d \n", arr);
  printf(">> %d \n", *test);

}
