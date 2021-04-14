#include <stdio.h>

int celsius(int fahr);

main(){
  printf("%d , %d \n", celsius(100), 100);
}

int celsius(int fahr){
  return 5 * (fahr-32) / 9;
}
