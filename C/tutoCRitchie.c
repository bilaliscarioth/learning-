#include <stdio.h>

#ifndef EOF
#define EOF (-1)
#endif

#define IN 1
#define OUT 0

main(void){
  int c,nl,nw,nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while((c = getchar())  != EOF){
    ++nc;
    if(c == '\n')
      ++nl;
    if (c == ' ' || c == '\n'  || c == '\t')
      state = OUT;
    else if(state == OUT){
       state = IN;
       ++nw;
    }
  }
  printf("Ligne : %d, Mot(s): %d,  %d\n", nl, nw, nc);
}
