#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "include.h"

chess *findPosition(int place, coreGame *core){
	int x, y;
	x = y = 0;
	while(place != (x*10)+y){
		if(x == 10){
			y = 0;
			++x;
		}
		y++;
	}
	return &(core->grid[x][y]);
};

void startGame(coreGame *core){
	int x, y;
	x = y = 0;
        for(x = 0; x < 10; ++x){
                for (y = 0; y < 10; ++y){
                        (core->grid[x][y]) = createChess(x, y, ' ');
                        if((x+y+1)%2 == 0 && (x*10+y) <= 39)
                                core->grid[x][y] = createChess(x, y, 'x');
                        else if((x+y+1)%2 == 0 && (x*10+y) > 59)
                                core->grid[x][y] = createChess(x, y, 'o');
                }
        }
};

void deplaceChess(chess *old, chess *new, coreGame *core){	
	char marks[2] = {'x', 'o'};
	if(abs((new->x*10 + new->y) - (old->x*10 + old->y)) == 11 || abs((new->x*10 + new->y) - (old->x*10 + old->y)) == 9 ){
		if(old->player == marks[core->player]){
			if(new->player != ' ') deleteChess(&(core->grid[new->x][new->y]), core);
			core->grid[new->x][new->y].player = old->player;
			core->grid[old->x][old->y].player = ' ';
			core->player = changePlayerTurn(core);
		}
	}
}

void printGrid(coreGame *core){
	int x = 0;
	do{
		if(x%10 == 0) printf("\n+---+---+---+---+---+---+---+---+---+---+\n");
		printf("| %c ", findPosition(x, core)->player);
		++x;
	}while(x  < 100);
	printf("\n+---+---+---+---+---+---+---+---+---+---+\n");
}

bool checkDeplacement(int to, int from){ 
	if((to > 100 || to < 0) && (from > 100 || from < 0)) return true; /*Si on dépasse le tableau; */
	return false;
}

int changePlayerTurn(coreGame *core){
	if(core->player == 1) return (core->player) -1;
	else return (core->player) +1;
}

int main(){
	int to, from;
	to = from = 0;
	struct coreGame core = createParty(20, 20);
	startGame(&core);
	while(core.X_ || core.O_){	
		printGrid(&core);
		printf("[%d] - Pion à déplacer :  ", core.player);
		if(scanf("%d", &to) > 0){
			printf("[%d] Quel endroit :  ", core.player);
			chess oldPosition = *findPosition(to, &core);
			if(scanf("%d", &from) > 0){
				chess newPosition = *findPosition(from, &core);
				if(!checkDeplacement(to, from))
					deplaceChess(&oldPosition, &newPosition, &core);
			}	
		}
	} 
}
