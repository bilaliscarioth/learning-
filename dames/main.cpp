#include "include.h"

class coreMainGame {
  private: 
    char board[10][10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}}; //notre plateau
    char mark[2] = {'O', 'X'}; //Nos joueurs
    int O_ = 20; // Nombre de pions
    int X_ = 20; 
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
      if((from < 0 && from > 99) || (to < 0 && to > 99) ||
          (to-from != 11 )) 
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
      if(board[i][j] != 'O' || board[i][j] != 'O'){ // On vérifie bien que le joueur bouge son pion
        board[i][j] = ' ';
        i = j = 0;
        while(i*10+j != to){
          j++;
          if(j == 10){
            ++i;
            j=0;
          }
        }
        board[i][j] = mark[player];
      }
    }
    bool endGame() {
      return (O_ == 0 || X_ == 0);  
    }
};


int main(){
  coreMainGame core;
  core.fillBoard();
  core.displayBoard(); 

    core.deplaceMark(31, 41, 1);
    core.displayBoard();

}
