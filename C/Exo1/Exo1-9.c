#include <stdio.h>

main(void){
  int c, blank;

  while((c = getchar()) != EOF){
    if(c == ' '){
      if(blank != 1){
        c = '_';
        blank = 1;
      }
    }
    putchar(c);
  }
}
