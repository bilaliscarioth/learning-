#include "./include.h"
#include "./core.cpp"

int main(){
	/*
		Initialisation
	*/
	coreChessGame cCore;
	int chooseGame = 2;

	cout << "___________________________________" << endl;
	cout << "| \tJEU D'ÉCHEC\t\t|" << endl;
	cout << "| 0) Jouer / 1) Aider / Autre) Quitter|" << endl;
	cout << "___________________________________" << endl;
	
	cin >> chooseGame;

	switch(chooseGame){
		case 0:
			cout << "[Pion Blanc] - Nom du joueur ?"	<< endl;
			cin >> cCore.players[0];
			cout << "[Pion Noir] - Nom du joueur ?"	<< endl;
			cin >> cCore.players[1];
				
				/*
					On prépare la partie et on la lance 
				*/
			cCore.startGame();
			while(1){
				string changement;
				cout << "Quel Pièce vous voulez faire bouger ?" << endl;
				cin >> changement;
				cCore.changePlacement(changement);
				cCore.afficherPlateau();
			}
			break;
		case 1:
			break;
		default:
			cout << "Vous avez quitter le jeu" << endl;
			return EXIT_FAILURE;
	}
}

