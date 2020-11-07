/*
	This profram calculates the average of the lowest and highest values entered.
	In able to perform the calculation of the average, two unique numbers are required.

	Date:4/22/2020

	Programmer Kevin Morales-Nguyen
*
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

int main() {
	//declare variables
	cout << fixed << setprecision(2);
	double high = 0;
	double low = 0;
	double num;
	double collecting = 0;
	string status = "o";
	int counter = 0;
	bool valid;
	int nindex = -1000;
	int decindex = 1000;
	bool negi;
	bool  dec;
	char again;
	string temp;
	stringstream ss;

	cout << "This program calculates the average of the highest and lowest numbers entered.\n\n";

	//main program loop
	while (status != "n") {
		high = 0;
		low = 0;
		counter = 0;

		cout << "type 'q' to stop inputting numbers." << endl << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

		//gather numbers from user
		while (true) {

			cout << "Enter: ";
			getline(cin, temp);
			valid = true;
			negi = false;
			dec = false;
			ss.str(temp);
			ss.clear();

			//check for first - sign store index
			if (temp.find('-') != -1) {
				nindex = temp.find('-');
				negi = true;
				temp.erase(nindex, 1);
			}
			//check for first . and store index
			if (temp.find('.') != -1) {
				decindex = temp.find('.');
				dec = true;
				temp.erase(decindex, 1);
			}

			//if negative is before decimal number is invalid
			if (dec == true && negi == true && (nindex > decindex)) {
				valid = false;
			}
			// if negative is not at the front number is invalid
			if (negi == true) {
				if (nindex != 0) {
					valid = false;
				}
			}

			//check for junk after removing possible decimal and negative sign
			for (char e : temp) {
				if (ispunct(e) || isalpha(e) || isspace(e) || e == '\n') {
					valid = false;
				}
			}

			//add bak . or - sign if they were art of the number
			if (dec == true && decindex < temp.size()) {
				temp = temp.insert(decindex, ".");
			}
			if (negi == true && nindex < temp.size()) {
				temp = temp.insert(nindex, "-");
			}
			
			//test to store number
			if (ss >> num && valid) {
				//set low and high values
				if (counter == 0) {
					low = num;
					high = num;
					counter++;
				}
				else if (num >= high) {
					high = num;
					counter++;
				}
				else if (num <= low) {
					low = num;
					counter++;
				}
			}
			else  if (temp == "q") {
				break;
			}
			else if (!valid) {
				cout << "input a valid number\n";
			}
		}

		double average = static_cast<double>(high + low) / 2.0;
				
		if (counter == 0) {
			cout << "No average.\n\n";
		}
		else {
			cout << "Low is: " << low << " High is: " << high << endl;
			cout << "Average of high and low: " << average << endl;
		}

		while (true) {
			cout << "calculate again? (y/n) ";
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

	cout << "\n\n\tProgrammer: Kevin Morales-Nguyen EC1\n\n";

		return 0;
}
