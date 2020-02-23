// Tuyen Vu
// tvkqd@mail.umkc.edu
// Program 6
// Due 11/17/2019

#include<iostream>
using namespace std;

//This function recursively searching for number of candy equal 17 within 20 moves
void candyGame(int num, int &check, int move = 20);

int main() {
	int numCandy;
	char play = 'y';

	do {
		//Get number of candy
		cout << "How many Candies are you starting with? ==> ";
		cin >> numCandy;
		//Validating number of candy
		while (numCandy < 0 || numCandy > 10000) {
			cout << "Number of Candies must be greater than 0 and no more than 10000." << endl;
			cout << "How many Candies are you starting with? ==> ";
			cin >> numCandy;
		}

		int check = 0;
		//Start the game
		cout << "Searching for a solution within 20 moves...." << endl;
		candyGame(numCandy, check);
		//Output this line if there if no solution
		if (!check)
			cout << "No solution found within 20 moves. Sorry." << endl;
		cout << endl;

		//Play again?
		cout << "Would you like to try again [Y/N]? ==> ";
		cin >> play;
	} while (tolower(play) == 'y');

	system("pause");

	return 0;
}

void candyGame(int num, int &check, int move) {
	//Base cases
	if (move > 0) {
		if (num == 17) {
			cout << "Found solution. I have exactly 17 Candies, with " << move << " moves left." << endl;
			check = 1;
		}
		//Recursively
		else if (num > 17 && num % 2 == 0) {
			//Reduce number of candy by half
			candyGame(num / 2, check, move - 1);
			if (check)
				cout << "Reduce " << num << " by half to get " << num / 2 << "." << endl;
		}
		else {
			//Add one-third number of candy to itself
			if (num % 3 == 0) {
				candyGame(num + num / 3, check, move - 1);
				if (check)
					cout << "With " << num << ", add 1/3 to get " << num + num / 3 << "." << endl;
			}
			//Add 23 more candies
			else{
				candyGame(num + 23, check, move - 1);
				if (check)
					cout << "With " << num << ", add 23 to get " << num + 23 << "." << endl;
			}
		}
	}
}
