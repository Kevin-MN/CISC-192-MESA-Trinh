/*
	This program will output the date in different formats given a valid US date. The program 
	will also utilize a struct called Date.

	Date:5/7/2020

	Programmer Kevin Morales-Nguyen
*
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

struct Date {
	int month;
	int day;
	int year;
};

int main() {
	//declare and initialize valriables used in the program.
	int fsindex = 0;
	int bsindex = 0;
	bool valid_month = true;
	bool valid_day = true;
	bool leap_year = false;
	string month = "";
	bool valid = true;
	string temp;
	stringstream ss;
	string status = "o";
	Date my_date = { -1,-1,-1 };		// initialize a date struct

	cout << "This program will print the date entered in various formats.\n\n";
	//main program loop
	while (status != "n") {
		// loop for gathering time
		while (true) {
			//reset variables from previous run
			fsindex = 0;
			bsindex = 0;
			valid_month = true;
			valid_day = true;
			leap_year = false;
			month = "";
			valid = true;
			temp = "";
			my_date.day = -1;
			my_date.month = -1;
			my_date.year = -1;

			cout << "\nEnter a date (mm/dd/yyyy):  ";
			getline(cin, temp);
			valid = true;
			// find index of potential two forward slashes
			fsindex = temp.find("/");
			bsindex = temp.rfind("/");
			// input validation with only two forward slashes
			if (fsindex != -1 && bsindex != -1 && fsindex == bsindex - 3) {
				temp.erase(fsindex, 1);
				temp.erase(bsindex - 1, 1);
				for (char e : temp) {
					if (isalpha(e) || isspace(e) || ispunct(e)) {	// check for any other junk
						valid = false;
					}
				}
				//if forward slashes are removed there should only be 8 characters
				if (temp.size() == 8) {
					temp.insert(fsindex, " ");
					temp.insert(bsindex, " ");
					ss.str(temp);
					ss.clear();
					ss >> my_date.month;
					ss >> my_date.day;
					ss >> my_date.year;
				}
				else {
					valid = false;
				}
			}
			else {
				valid = false;
			}
			//check for leap year
			if ((my_date.year % 400) == 0) {
				leap_year = true;
			}
			else if ((my_date.year % 100) == 0) {
				leap_year = false;
			}
			else if ((my_date.year % 4) == 0) {
				leap_year = true;
			}
			//check to see what month and day are valid
			if ((my_date.month < 1 || my_date.month > 12) && my_date.month != -1) {
				valid_month = false;
			}
			else {
				if (my_date.day < 1) {
					valid_day = false;
				}
				switch (my_date.month) {
				case(1):
					month = "January";
					if (my_date.day > 31) {
						valid_day = false;
					}
					break;
				case(2):
					month = "Feburary";
					if ((my_date.day > 28 && !leap_year) || (leap_year && my_date.day > 29)) {
						valid_day = false;
					}
					break;
				case(3):
					month = "March";
					if (my_date.day > 31) {
						valid_day = false;
					}
					break;
				case(4):
					month = "April";
					if (my_date.day > 30) {
						valid_day = false;
					}
					break;
				case(5):
					month = "May";
					if (my_date.day > 31) {
						valid_day = false;
					}
					break;
				case(6):
					month = "June";
					if (my_date.day > 30) {
						valid_day = false;
					}
					break;
				case(7):
					month = "July";
					if (my_date.day > 31) {
						valid_day = false;
					}
					break;
				case(8):
					month = "August";
					if (my_date.day > 31) {
						valid_day = false;
					}
					break;
				case(9):
					month = "September";
					if (my_date.day > 30) {
						valid_day = false;
					}
					break;
				case(10):
					month = "October";
					if (my_date.day > 31) {
						valid_day = false;
					}
					break;
				case(11):
					month = "November";
					if (my_date.day > 30) {
						valid_day = false;
					}
					break;
				case(12):
					month = "December";
					if (my_date.day > 31) {
						valid_day = false;
					}
					break;
				default:
					break;
				}
			}
			//print output or prompt again
			if (valid) {
				if (leap_year) {
					cout << "\n" << my_date.year << " is a leap year." << endl;
				}
				else {
					cout << "\n" << my_date.year << " is not a leap year." << endl;
				}

				if (!valid_month) {
					cout << my_date.month << " is an invalid month." << endl;
				}
				else if (!valid_day) {
					cout << my_date.day << " is not a valid day of " << month << endl;
				}
				else {
					cout  <<"Date: " <<  my_date.month << "/" << my_date.day << "/"  << my_date.year << " is valid." << endl << endl
						 << my_date.month << "/"  << my_date.day << "/"  << my_date.year << " (US)." << endl
						<< month << " "  << my_date.day << ", "  << my_date.year << " (US Expanded)." << endl
						<< my_date.day << " " << month << " "  << my_date.year << " (US Military)." << endl
						<< setw(4) << setfill('0') << my_date.year << "-" << setw(2) << setfill('0') << my_date.month << setw(0) << "-" << setw(2) << setfill('0')  << my_date.day << " (International)." << endl << endl;
					break;
				}
				
			}
			else if (!valid) {
				cout << "input a valid date. For month and day use two digits.\n";
			}
		}

		//prompt user to run again
		while (true) {
			cout << "\n\nTest another date? (y/n) ";
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

	cout << "\n\n\tProgrammer: Kevin Morales-Nguyen PA5\n\n";

	return 0;
}
