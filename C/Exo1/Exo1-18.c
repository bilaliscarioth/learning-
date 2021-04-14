#include <stdio.h>
#include <stdlib.h>

int getlines(char s[], int lim);
void copies(char *to, char *from);

main(){

  int len, max;
  char longest[1000];
  char copy[1000];
  max = 0;

  while((len = getlines(copy, 1000))  > 0){ // On set len = qui récupère le nombre de caractère de la ligne
    copies(longest, copy); //On transfère nos arrays
    printf("%s\n", longest); //On print
  }


  return 0;
}

int getlines(char s[], int lim){
  int c,i;
  //On fait une noucle pour avoir le caractère maximal de la ligne
  for(i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){
    if(c != ' ' || c != '\t') 
      s[i] = c;
  }
  //SI y'a un retour à la ligne en le compte aussi !
  if(c == '\n'){
    ++i;
  }
  //Indicateur de la fin :)
  s[i] = '\0';
  return i;
}

void detab(char *to, char *from){
  int i = 0;
  while((to[i] = from[i]) != '\0'){ //On set longest avec le copy et on vérifie qu'on est pas à la fin
    if(to[i] == ' '){
      for(int j = 1; j < 5; j++)
        to[i+j] = 1;
    }
    i++; 
  }
}
