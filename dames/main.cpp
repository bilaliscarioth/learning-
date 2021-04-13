#include "include.h"

class coreMainGame {
  private: 
    char board[10][10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}}; //notre plateau
    char mark[2] = {'O', 'X'}; //Nos joueurs
    int O_ = 20; // Nombre de pions
    int X_ = 20; 
    int player = 0;
  public:
    void fillBoard(){
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
    void deplaceMark(int from, int to, int player){
      if((from < 0 && from > 99) || (to < 0 && to > 99))  //On vérifie que le joueur ne propose pas un nombre au pif
        return;
      if(!(to-from != -11 || to-from != -9) ||  //On vérifie que le joueur parte en diagonale vers le bas
         !(to-from != 11  || to-from != 9)) //On vérifie encore pour la daigonale vers le haut)
          return;
      //On met nos indexs
      int i, j;
      i = j = 0;
      while(i*10+j != from){
        j++;
        if(j == 10){
          ++i;
          j=0;
        }
      }
      if(board[i][j] == mark[player] ){ // On vérifie bien que le joueur bouge son pion
        board[i][j] = ' ';
        i = j = 0;
        while(i*10+j != to){
          j++;
          if(j == 10){
            ++i;
            j=0;
          }
        }
        if((board[i][j] == 'X' && mark[player] == 'X') ||  // On vérifie qu'il ne se mange pas lui même...
            (board[i][j] == 'O' && mark[player] == 'O'))
          return;
        else { //Sinon on enlève bien les pions restants :)
          if(board[i][j] == 'X' && mark[player] == 'O') --X_; 
          if(board[i][j] == 'O' && mark[player] == 'X') --O_;
        }
        board[i][j] = mark[player];
        switchPlayer();
      }else cout << " /!\\ Ce n'est pas ton pion !" << endl;
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
    cout << endl << "Ou ça : ";
    cin >> from;
    core.deplaceMark(to, from, core.getPlayer());
    core.displayBoard();   
  }
}
