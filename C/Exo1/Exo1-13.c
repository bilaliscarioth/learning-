#include <stdio.h>

main(){
  int c, i, nwhite, nother, nb;
  int ndigit[10];


  nwhite = nother = nb = 0;
  for (i = 0; i < 10; i++)
    ndigit[i] = 0;

  while((c = getchar()) != EOF){
    if (c >=  '0' && c <= '9'){
      ++ndigit[c-'0'];
      ++nb;
    }
    else if(c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }
  printf("digits=");

  for (i  = 0;  i < 10; ++i){
    printf("\n[%d =  %d]", i,ndigit[i]);
    printf(" [%d =  %.0f]", i,  100*(float)ndigit[i]/nb);
  }

  printf("\n, white space = %d, others = %d \n", 
      nwhite, nother);
}
