#include <stdio.h>

#define IN 1
#define OUT 0

main(){
  /*
   *On set nos variables
   */
  int state, c;
  state = IN;
  
  while((c = getchar()) != EOF){
    if(c == '\n' && !state)
      state = IN;

    if(state){ // On vérifie de ne pas faire la condition inutilement
      if(c != ' '){ //On vérifie que c'est toujours un mot
        printf("%c", c);
      }else{
        state = OUT;
      }
    }
  }
  printf("\n");
}
