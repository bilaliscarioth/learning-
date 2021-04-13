class coreChessGame{
	private:
		char plateau[100];

	public:
		const char *tabX = "ABCDEFGHIJ";
		string players[2] = {"", ""};
		void startGame(){
			cout << players[0] << " Vs " << players[1] << endl;
			cout << "_________________________" << endl;
			/*
				Initialisation du plateau
			*/
			for(int i = 0; i*10 < 100; i++){	
				cout << tabX[i]<< " | ";
				//Les lignes;
				for(int ligne=0; ligne< 10; ligne++){
					if(i< 4){
						if((i+ligne)%2!=0) plateau[(10*i)+ligne] = *"X";
						else plateau[(10*i)+ligne] = *" ";
						cout << plateau[(10*i)+ligne];
					}else if(i > 5){
						if((i+ligne)%2==0) plateau[10*i+ligne] = *"O";	
						else plateau[10*i+ligne] = *" ";
						cout << plateau[10*i+ligne];
					}else{
						plateau[10*i+ligne] = *" ";	
						cout << plateau[10*i+ligne];
					}
				}
				cout << " |" << endl;
			}
			
			cout << "_________________________" << endl;
		};
		/*
			Changement de place
		*/
		void changePlacement(string output){
			int placement, newPlace;
			//Ancien Emplacement
			for(int chr = 0; chr < 2; chr++){		
				if(int(output[chr]) > 64) placement = (int(output[chr]) - 65);
				else placement += (int(output[chr]) -48)*10;
			}
			cout << "A - " << placement << endl;
			//Nouvel emplacement
			for(int chr=3; chr < 5; chr++){
				if(int(output[chr]) > 64) newPlace = (int(output[chr]) - 65);
				else newPlace += (int(output[chr]) -48)*10;
			}

			cout << "B - " << newPlace << endl;
			plateau[newPlace] = plateau[placement];
			plateau[placement] = *" ";
		};
		void saveGame(){


		};
		void loadGame(){


		};
		void afficherPlateau(){
			cout << "_________________________" << endl;
			//Le tableau
			for(int i = 0; i*10 < 100; i++){	
				cout << tabX[i] <<" | ";
				//Les lignes
				for(int ligne=0; ligne< 10; ligne++){
					cout << plateau[10*i+ligne];
				}
				cout << " |" << endl;
			}
			cout << endl << "_________________________" << endl;
		}
};
