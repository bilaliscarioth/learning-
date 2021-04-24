#include "include.h"

class coreMainGame {
	private: 
		char board[10][10];
		char mark[2]; //Nos joueurs
		int O_;
		int X_; 
		int player;
		int storageEmplacement[2];
	public:

		void fillBoard(){
			player = 0;
			mark[0] = 'O';
			mark[1] = 'X';
			O_ = 20;
			X_ = 20;
			for(int i=0; i < 10; ++i){
				for(int j=0; j < 10; ++j){
					if((i+j+1)%2 == 0 && (i*10+j) <= 39)
		    		board[i][j] = mark[1];
					else if((i+j+1)%2 == 0 && (i*10+j) > 59)
						board[i][j] = mark[0];
					else board[i][j] = ' ';
				}
			}	
		}
		void displayBoard(){
			for(int i= 0; i < 10; ++i){
	    	cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
        for(int j=0; j < 10; j++)
          cout << "| " << board[i][j] << " ";
				cout << "|" << endl;
			}
			cout << "+---+---+---+---+---+---+---+---+---+---+" << endl;
		}
		void deplaceMark(int to, int from, int player){
			if((from < 0 && from > 99) || (to < 0 && to > 99))  //On v�rifie que le joueur ne propose pas un nombre au pif
				return;
			if(!(to-from != -11 || to-from != -9) ||  //On v�rifie que le joueur parte en diagonale vers le bas
					!(to-from != 11 || to-from != 9)) //On v�rifie encore pour la daigonale vers le haut)
					return;		
			int i, j;
			i = j = 0;
			if(board[i][j] == mark[player]){ // On v�rifie bien que le joueur bouge son pion
				i = j = 0;
				if(board[i][j] == mark[player] && board[storageEmplacement[0]][storageEmplacement[1]] == mark[player])  // On v�rifie qu'il ne se mange pas lui même...
						return;
				else { //Sinon on enl�ve bien les pions restants :)
					if(board[i][j] == 'X' && mark[player] == 'O') --X_; 
					if(board[i][j] == 'O' && mark[player] == 'X') --O_;
					board[storageEmplacement[0]][storageEmplacement[1]] = ' ';
					board[i][j] = mark[player];
				}
				switchPlayer();
			}else cout << i << " " << j<< " /!\\ Ce n'est pas ton pion !" << endl; 	
		}

		void switchPlayer(){
			if(player ==0) ++player;
			else --player;
		}
		int getPlayer(){
			return player;
		}
		bool endGame() {
			return (O_ == 0 || X_ == 0);  
		}
};


int main(){
	coreMainGame core;
	core.fillBoard();
	core.displayBoard(); 
	while(!core.endGame()){
		int to, from;
		cout << core.getPlayer() << "Vous bougez quel pion : ";
		cin >> to;
		cout << endl << "Ou �a : ";
		cin >> from;
		core.deplaceMark(to, from, core.getPlayer());
		core.displayBoard();   
  }
}
