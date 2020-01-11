#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
	//variables
	char pChoice;
	int pScore = 0;
	int RNGScore = 0;
	int rounds;
	int roundsCounter;
	
	//game
	cout << "Rock-Paper-Scissors against the RNG\n by RippandT | Version 1.1 (RNG NOW WORKS!)\n\n";
	cout << "How many rounds do you wanna play for? ";
	cin >> rounds;
	system("cls");
	
	do{
		cout << "Round " << roundsCounter + 1 << " of " << rounds << endl;
		cout << "You: " << pScore << " | RNG: " << RNGScore << "\n\n";
		cout << "[R]ock, [P]aper, or [S]cissors? \n";
		cout << "Choice: ";
		cin >> pChoice;
		cout << endl;
		
		//RNG
		mt19937 RNG;
		RNG.seed(time(0));
		
		uniform_int_distribution<uint32_t> RNGPRS(1,3);
		
		int RNGChoice = RNGPRS(RNG);
	
		if(pChoice == 'R' || pChoice == 'r'){
			cout << "You chose: Rock\n";
			switch(RNGChoice){
				case 1:
					cout << "The RNG chooses: Rock \n It's a tie!";
					break;
				case 2:
					cout << "The RNG chooses: Paper \n The RNG wins!";
					RNGScore += 1;
					break;
				case 3:
					cout << "The RNG chooses: Scissors \n You win!";
					pScore += 1;
					break;
			}
			cout << "\n\n" << "You: " << pScore << " | RNG: " << RNGScore << "\n\n";
			roundsCounter += 1;
			system("pause");
			system("cls");
		}
		else if(pChoice == 'P' || pChoice == 'p'){
			cout << "You chose: Paper\n";
			switch(RNGChoice){
				case 1:
					cout << "The RNG chooses: Rock \n\n You win!";
					pScore += 1;
					break;
				case 2:
					cout << "The RNG chooses: Paper \n\n It's a tie!";
					break;
				case 3:
					cout << "The RNG chooses: Scissors \n\n The RNG wins!";
					RNGScore += 1;
					break;
			}
			cout << "\n\n" << "You: " << pScore << " | RNG: " << RNGScore << "\n\n";
			roundsCounter += 1;
			system("pause");
			system("cls");
		}
		else if(pChoice == 'S' || pChoice == 's'){
			cout << "You chose: Scissors\n";
			switch(RNGChoice){
				case 1:
					cout << "The RNG chooses: Rock \n\n The RNG wins!";
					RNGScore += 1;
					break;
				case 2:
					cout << "The RNG chooses: Paper \n\n You win!";
					pScore += 1;
					break;
				case 3:
					cout << "The RNG chooses: Scissors \n\n It's a tie!";
					break;
			}
			cout << "\n\n" <<"You: " << pScore << " | RNG: " << RNGScore << "\n\n";
			roundsCounter += 1;
			system("pause");
			system("cls");
		}
		else{
			system("cls");
			cout << "Wrong input, try again \n\n";
		}
	}while(rounds != roundsCounter);
	
	//Final Verdict
	if(pScore > RNGScore){
		cout << "You win the game! Congratulations!";
	}
	else if(pScore < RNGScore){
		cout << "The RNG wins the game! Better luck next time!";
	}
	else{
		cout << "It's all a tie!";
	}
	
	cout << "\n\n";
	system("pause");	
	return 0;
}
