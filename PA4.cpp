/*
	This program can tell whether an entered time is considered lucky. 

	Date:4/30/2020

	Programmer Kevin Morales-Nguyen
*
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

int main() {
	//declare and initialize valriables used in the program.
	string status = "o";
	string half1 = "";
	string half2 = "";
	string hour1s = "";
	string hour2s = "";
	string min1s = "";
	string min2s = "";
	int half1Raw = 0;
	int half2Raw = 0;
	int half1Sum = 0;
	int half2Sum = 0;
	int midIndex = 0;
	int hour1 = 0;
	int hour2 = 0;
	int min1 = 0;
	int min2 = 0;
	bool valid;
	string temp;
	stringstream ss;

	cout << "This program determines whether a standard time is normal, lucky, or unlucky.\n\n";
	//main program loop
	while (status != "n") {
		 // loop for gathering time
		while (true) {

			cout << "\nEnter time (HH:MM): ";
			getline(cin, temp);
			valid = true;
			//if there is not ':' in the line then ask for valid input
			if (temp.find(":") != -1) {
				midIndex = temp.find(":");
				temp.erase(temp.find(":"), 1);
				//remove the ':' and check if there is any other junk
				for (char e : temp) {
					if (isalpha(e) || isspace(e) || ispunct(e)) {
						valid = false;
					}
				}
				//split time in strings before and after ':'
				half1 = temp.substr(0, midIndex);
				half2 = temp.substr(midIndex);

				//check that time is correctly enter (size), hsould only have two numbers on each half
				if ((half1.size() == 2 || half1.size() == 1) && half2.size() == 2 && valid) {
					//convert strings to ints with stringstream for one number for hour
					if (half1.size() == 1) {

						hour1s = temp.substr(0, 1);			// I should of utilized a vector for this part, would of made code cleaner
						min1s = temp.substr(1, 1);
						min2s = temp.substr(2, 1);
						ss.str(hour1s);
						ss.clear();
						ss >> hour1;
						ss.str(min1s);
						ss.clear();
						ss >> min1;
						ss.str(min2s);
						ss.clear();
						ss >> min2;
						
						if (min1 > 5) {
							valid = false;
						}

					}	//convert strings to ints with stringstream for two number for hour
					else if (half1.size() == 2 && valid) {

						hour2s = temp.substr(0, 1);			// I should of utilized a vector for this part, would of made code cleaner
						hour1s = temp.substr(1, 1);
						min1s = temp.substr(2, 1);
						min2s = temp.substr(3, 1);
						ss.str(hour2s);						
						ss.clear();
						ss >> hour2;
						ss.str(hour1s);
						ss.clear();
						ss >> hour1;
						ss.str(min1s);
						ss.clear();
						ss >> min1;
						ss.str(min2s);
						ss.clear();
						ss >> min2;

						if ((hour2 > 0 && hour1 > 2 )|| hour2 > 1 || min1 > 5){
							valid = false;
						}
					}
				}
				else {
					valid = false;
				}
			}
			else {
				valid = false;
			}

			//this segment is to determine the state of the time and then print our appropriatly
			if (valid) {
				half1Sum = hour1 + hour2;
				half2Sum = min1 + min2;
				temp.insert(midIndex, ":");
				//determine if number is lucky, individual numbers added up on first half = numbers added on second half
				if (half1Sum == half2Sum) {
					cout << temp << " is a lucky time.";
				}
				else {
					cout << temp << " is a normal time.";
				}
				//print out special characteristics, this is for 4 number time evaluations 
				if (temp.size() == 5) {

					if (hour2 == hour1 && hour2 == min1 && hour2 == min2){
						cout << "  ->  Bingo! Go buy a lottery ticket" << endl;
					}
					else if (hour1 == (hour2 + 1) && min1 == (hour1 + 1) && min2 == (min1 + 1)) {
						cout << "  -> Up! All dreams will come true." << endl;
					}
					else if (hour1 == (hour2 - 1) && min1 == (hour1 - 1) && min2 == (min1 - 1)) {
						cout << "  -> Down! The callenging road is ahead." << endl;
					}
				}	// for three number time evaluations
				else if (temp.size() == 4) {

					if (hour1 == min1 && hour1 == min2) {
						cout << "  ->  Bingo! Go buy a lottery ticket" << endl;
					}
					else if (min1 == (hour1 + 1) && min2 == (min1 + 1)) {
						cout << "  -> Up! All dreams will come true." << endl;
					}
					else if (min1 == (hour1 - 1) && min2 == (min1 - 1)) {
						cout << "  -> Down! The callenging road is ahead." << endl;
					}
				}
			
				//reset variables for another run
				half1Raw = 0;
				half2Raw = 0;
				half1Sum = 0;
				half2Sum = 0;
				midIndex = 0;
				hour1 = 0;
				hour2 = 0;
				min1 = 0;
				min2 = 0;
				break;
		
			}
			else if (!valid) {
				cout << "input a valid time.\n";
			}
		}
		//prompt user to run again
		while (true) {
			cout << "\n\nTest time again? (y/n) ";
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

	cout << "\n\n\tProgrammer: Kevin Morales-Nguyen PA4\n\n";

	return 0;
}
