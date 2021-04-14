#include <stdio.h>

main(){
  int c;
  while((c = getchar()) != EOF){
    /*
     *  On met en évidences les retours à la ligne avec un printf
     */

    if(c == '\\')
      c = '\\';
    else if(c == '\n')
      printf("\\n");
    else if(c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b"); 

    /*
     *Sans oublier de les remplacer
     */

    if (c == '\n' || c == '\t' || c == '\b') c = 0;

    putchar(c);
  }
}
