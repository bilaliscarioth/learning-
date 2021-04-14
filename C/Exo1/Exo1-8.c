#include <stdio.h>

#ifndef EOF
#define EOF (-1)
#endif

main(void){
  int tab, blank, line, c;
  tab = line = blank = 0;

  while((c = getchar()) != EOF){
    if (c == ' ')
      blank+= 1;
    else if(c == '\t')
      tab+= 1;
    else if(c == '\n')
      line+= 1;
  }

  printf("Line %d, Blank %d, Tab %d \n", line, blank, tab);

}
