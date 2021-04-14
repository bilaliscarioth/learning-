#include <stdio.h>
#include <stdlib.h>

int getlines(char s[], int lim);
void copies(char *to, char *from);
void entab(char *to);

main(){

  int len;
  char longest[1000];
  char copy[1000];

  while((len = getlines(copy, 1000))  > 0){ // On set len = qui récupère le nombre de caractère de la ligne
    if(len > 1){
      copies(longest, copy); //On transfère nos arrays
      printf("%s\n", longest); //On print
      entab(longest);
    }
  }

  return 0;
}

int getlines(char s[], int lim){
  int c,i;
  //On fait une noucle pour avoir le caractère maximal de la ligne
  for(i=0; i < lim-1 && (c=getchar()) != EOF && c !='\n'; ++i)
    s[i] = c;
  //SI y'a un retour à la ligne en le compte aussi !
  if(c == '\n'){
    s[i] = c;
    ++i;
  }
  //Indicateur de la fin :)
  s[i] = '\0';
  return i;
}

void copies(char *to, char *from){
  int i = 0;
  while((to[i] = from[i]) != '\0') //On set longest avec le copy et on vérifie qu'on est pas à la fin
    i++;
}

void entab(char *to){
  char tab[1000];
  int i;
  i = 0;

  printf(" A >> %s \n", to);
  while(to[i] != '\0'){
    if(to[i] == ' '){
      tab[i] = '\t'; 
    }else tab[i] = to[i];
    i++;
  }
  printf(" Z >> %s \n", tab);
}