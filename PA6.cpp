/*
	This program is the three strikes and you are out game, a bag will contain 8 chips,
	five of which will be digits of the cars price, three will be strike chips. Once the 
	user has drawn a chip, if it not a strike then the user will then have a chance to guess
	where it belongs in the price. 

	Date: 5/22/2020

	Programmer Kevin Morales-Nguyen
*
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

//functions used in main to manage game

//This function empties a vector after a game so it can be reused
void empty_vector(vector<int>& myvector) {
	for (int i = 0; i < myvector.size(); i++) {
		myvector.erase(myvector.begin());
	}
}

//This function fills up the chipbag and price digit vector to be used by the program
void generate_chipbag(vector<int> &digits, vector<int> &chipbag, vector<int> &price) {
	srand(time(nullptr));
	for (int i = 0; i < 5; i++) {
		int tempnum = static_cast<int>(rand() % (digits.size() - 1));
		chipbag[i] = digits[tempnum];
		price[i] = digits[tempnum];
		digits.erase(digits.begin() + tempnum);
	}
	// this check is to make sure there is no leading 0 in the price
	if (chipbag[0] == 0) {
		int temp = chipbag[0];
		chipbag[0] = chipbag[1];
		price[0] = price[1];
		chipbag[1] = temp;
		price[1] = temp;
	}
}

//This funciton displays the # of placed digits, the # of strikes and the panel of digits placed
void display_s_p(int placed, int strike,const vector<int> &digits) {
	cout << "\nStrikes hit: " << strike << endl;
	cout << "Digits placed: " << placed << endl << endl << "Panel: $";

	for (int e : digits) {
		cout << " ";
		if (e == -1) {
			cout << "_";
		}
		else {
			cout << e;
		}
	}
	cout << endl << setw(18) << "0 1 2 3 4" << endl;
}

//This funciton is used for debugging, it will print out the contents of a vector
void print_vector(vector<int> &vectora) {
	cout << endl;
	for (int i = 0; i < vectora.size(); i++){
		cout << vectora[i];
	}
	cout << endl;
}

//This function will print out all elements of the price_digi vector, displaying the price
void display_price(vector<int>& myvector) {
	cout << endl << "The price of the car is $";
	for (int i = 0; i < 5; i++) {
		cout << myvector[i];
	}
	cout << "..." << endl << endl;
}

//This function concatenates all elements of price_digi and returns price as a string
string get_price(vector<int> &chipv) {
	string price = "";
	for (int i = 0; i < 5; i++) {
		price += to_string(chipv[i]);
	}
	return price;
}

//This method is used to remove the drawn element from the chpibag
void erase_elem(int erasure, vector<int> &mvector) {
	for (int i = 0; i < mvector.size(); i++) {
		if (erasure == mvector[i]) {
			mvector.erase(mvector.begin() + i);
		}
	}
}


int main() {
	//declare and initialize valriables used in the program.
	stringstream ss;
	vector<int> digits; 
	vector<int> chipbag;
	vector<int> price_digi;
	vector<int> correct_guesses; 
	string usernum1;
	string price;
	string status = "o";
	string temp;
	bool valid;
	int drawn;
	int bag_index;
	int usernum;
	int digits_placed;
	int strikes_hit;
	
	cout << "Welcome to the Three Strikes and You Are Out game!\n\n";

	//main program loop
	while (status != "n") {
		//reset variables and vectors before setting up for another run
		digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		chipbag = { 0,0,0,0,0,-1,-1,-1 };
		price_digi = { 0,0,0,0,0 };
		correct_guesses = { -1,-1,-1,-1,-1 };
		digits_placed = 0;
		strikes_hit = 0;
		generate_chipbag(digits, chipbag, price_digi);
		display_price(chipbag);
		price = get_price(chipbag);
		// loop for gathering user choice
		while (true) {

			cout << "\nEnter k to draw a chip or any other key to quit game:  ";
			getline(cin, temp);
			valid = true;

			if (temp == "k") {
				display_s_p(digits_placed, strikes_hit, correct_guesses);
				bag_index = rand() % chipbag.size(); // grab a random chip out of the chipbags range, which will decrease as the game goes on so we do not use constant values or we will get out of bounds
				drawn = chipbag[bag_index];	// draw a "chip" from the bag
				
				//If a strike was drawn, strike counter increase and remove strike from chipbag
				if (drawn == -1) {
						cout << "\nYou drew a strike, no!!!" << endl << endl;
						strikes_hit++;
						chipbag.erase(chipbag.begin() + bag_index); // remove strike from chipbag
				}
				else {
						cout << endl <<  "You drew the number: " << drawn << endl 
							<< "Where does it belong? ";
						//validate use input
						getline(cin, usernum1); 
						for (char e : usernum1) {
							if (ispunct(e) || isalpha(e) || isblank(e)) {
								valid = false;
							}
						}

						if (valid == true) {
							usernum = stoi(usernum1);
						}

						if (valid == false || usernum > 4) {
							cout << "\nInput was incorrect." << endl << endl;
						}
						else { 
							usernum = stoi(usernum1);
							if (drawn == price_digi[usernum]) { // if user guesses correct index, remove chip from bag and add to panel
								cout << "\nCorrect guess!" << endl;
								erase_elem(drawn, chipbag);
								correct_guesses[usernum] = price_digi[usernum];
								digits_placed++;
							}
							else {
								cout << "\nIncorrect guess" << endl;
							}
						}
					}

					// endgame conditions, user get three strikes or user guesses all digits, game ends
					if (strikes_hit == 3) {
						display_s_p(digits_placed, strikes_hit, correct_guesses);
						cout << "\nYou could not guess the price of the car... " << endl << endl;
						cout << "The price of the car was $" << price << endl;
						empty_vector(chipbag);
						empty_vector(price_digi);
						break;
					}
					else if (digits_placed == 5) {
						display_s_p(digits_placed, strikes_hit, correct_guesses);
						cout << "\nYou won!! The car is yours!" << endl << endl <<
							"The price of the car was $" << price << endl;
						empty_vector(chipbag);
						empty_vector(price_digi);
						break;
					}
			}
			else {
				break;
			}
		}

		//prompt user to run game again
		while (true) {
			cout << "\n\nPlay another game? (y/n) ";
			getline(cin, temp);
			ss.str(temp);
			ss.clear();
			if (ss >> status) {
				if (status == "y" || status == "n") {
					break;
				}
			}
			else {
				continue;
			}
		}
	}

	cout << "\n\n\tProgrammer: Kevin Morales-Nguyen PA6\n\n";

	return 0;
}
