/* Création d'un morpion */
#include <stdio.h>

void printTable(char table[3][3]);
int main() {
	char table[3][3] = {{'1', '2', '3'}, 
	  		{'4', '5', '6'}, 
			{'7', '8', '9'}};
	char mark[2] = {'X', 'O'};
	int winner, out, player, choice;
	winner = out = player = 0;
  	while(out == 0){
		printTable(table);
		if(scanf("%d", &choice) > 0){
      		if(choice <= 9  && choice >= 1){
				int i, j;
        		i = j = 0; 
        		while(choice != 0){
					if(choice > 3){
						j = 0;
						++i;
            			choice -= 3;
					}else{
						j++;
						--choice;
					}
				}
				if(table[i][j-1] != 'O' && table[i][j-1] != 'X'){
					table[i][j-1] = mark[player];
					if(player == 0 ) ++player;
					else --player;
				}
			}
		}  
    //Vérification si le joueur a gagné  :)    
		int row;
		for(row=0; row < 3; ++row){
			if( (table[row][0] == 'O' && table[row][1] == 'O' && table[row][2] == 'O') || 
					(table[row][0] == 'X' && table[row][1] == 'X' && table[row][2] == 'X')) {
 						out = 1;
						if(player == 0) ++player;
						else --player;
						winner = player;
			}
			if( (table[0][row] == 'O' && table[1][row] == 'O' && table[2][row] == 'O') || 
					(table[0][row] == 'X' && table[1][row] == 'X' && table[2][row] == 'X')) {
						out = 1;
						if(player == 0) ++player;
 						else --player;
						winner = player;
			}
			//La diagonale de [0][0] Ã  [2][2]
			if( (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O') || 
					(table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X')) {
						out = 1;
						if(player == 0) ++player;
						else --player;
						winner = player;
			}
			//La diagonale de [0][2] Ã  [2][0]
			if( (table[0][2] == 'O' && table[1][1] == 'O' && table[2][0] == 'O') || 
					(table[0][2] == 'X' && table[1][1] == 'X' && table[2][0] == 'X')) {
						out = 1;
						if(player == 0) ++player;
 						else --player;
						winner = player;
		}
	}
	//Vérification si personne ne peut jouer
	for(row=0;  row < 3; row++){
		if((table[row][0] != 'X' && table[row][0] != 'O') || 
			(table[row][1] != 'X' && table[row][1] != 'O')  || 
			(table[row][2] != 'X' && table[row][2] != 'O')) break; 
		if(row == 2){ // Vérifie jusqu'au derniÃ¨re ligne :)
			if(out != 1) winner = 2;
			out = 1;
			}
		}
	}
	printTable(table);
	if(winner == 2){ //Si c'est égalité :)
		printf("Boriiiiing... \n");
		return 0;  
	}
 	printf("PLAYER %c ARE WINNER !!!\n", mark[winner]); // On renvoit le vainqueur
	return 0;
}

void printTable(char table[3][3]){
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", table[0][0], table[0][1], table[0][2]); 
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", table[1][0], table[1][1], table[1][2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n", table[2][0], table[2][1], table[2][2]);
	printf("+---+---+---+\n"); 
}
