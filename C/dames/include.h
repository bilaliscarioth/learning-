typedef struct chess {
	int x,y; 
	char player;
} chess;

typedef struct coreGame{
	int O_, X_;
	int player;
	chess grid[10][10];	
} coreGame;

void printGrid(coreGame *core); 
void startGame(coreGame *core);
void deplaceChess(chess *old, chess *new, coreGame *core);
chess *findPosition(int place, coreGame *core); 
bool checkDeplacement(int to, int from);
int changePlayerTurn(coreGame *core);

struct chess createChess(int x, int y, char player){
	struct chess temp;
	temp.x = x;
	temp.y = y;
	temp.player = player;
	return temp;
};
struct chess deleteChess(chess *toRemove){
	free(toRemove);
};
struct coreGame createParty(int bChess, int wChess){
	struct coreGame tmp;
	tmp.O_ = wChess;
	tmp.X_ = bChess;
	tmp.player = 0;
	return tmp;
};
