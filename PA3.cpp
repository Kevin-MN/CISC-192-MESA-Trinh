/**
	This program can be used to write to files and open files with student names in them
	When writing or reading from a file the, for alphabetical order, the top name and last name are printed.

	Date: 4/22/2019
	Programmer: Kevin Morales-Nguyen
*/


#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
	// declare variables
	int collect_names;
	int name_in_counter;
	int name_count;
	string file_name;
	string name;
	string name_top;
	string name_bot;
	fstream cool;
	stringstream ss;

	string command = "zeta";

	//program info 
	cout << "\tThis program allows you to write names to files and open up files to view names.\n"
		<< "\tFor alphabetical order, the first and last names are appropriately printed out.\n\n";

	//loop main program 
	while (command != "quit") {
		cout << "\tWhat would you like to do?\n\t\"write\" to write names to a file \"open\" to open file and \"quit\" to quit.\n\n";
		name_top = "";
		name_bot = "";

		cout << "Command: ";
		getline(cin, command,'\n');

		for (int i = 0; i < command.size(); i++) {
			command[i] = (char)tolower(command[i]);
		}

		//type 'open' to open and view names in a file
		if (command == "open") {
			name_in_counter = 1;
			cout << "Enter file name: ";
			getline(cin, file_name,'\n');
			cool.open(file_name, ios::in); // open file
			if (cool) {
				while (getline(cool, name)) {	//read in until eof
					cout <<name_in_counter << ".\t" <<  name << endl;
					if (name_in_counter == 1) {	// first name read in will be compared against
						name_top = name;
						name_bot = name;
					}
					else {
						if (name > name_top) {
							name_top = name;
						}
						else if (name < name_bot) {
							name_bot = name;
						}
					}
					++name_in_counter;
				}
				cool.close();
				cout << "\nName at top: " << name_bot << endl;
				cout << "Name at bot: " << name_top << endl<< endl;
			}
			else {
				cout << "Unable to open file\n\n";
			}
		}
		else if (command == "write") {		//write block
			collect_names = 0;
			name_count = 1;
			cout << "Enter a number between 5 and 45 inclusive: ";
			while (true) {
				cin >> collect_names;	//data validation for range value
					if (cin.fail()) { 
						cout << "Please enter valid input: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					else if (collect_names < 5 || collect_names > 45) {
						cout << "please enter value within range: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					else {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << endl;
						break;
					}
			}

			cool.open("Student.txt", ios::out); 

			for (int i = 0; i < collect_names; i++) { // collect names based on range value
				cout << "Full name of student " << name_count << ": ";
				getline(cin, name,'\n');
				if (name.empty()) {		//data validation
					cout << "No blank names!\n";
					i--;
				}
				else {
				name_count++;
				cool << name << '\n';
			}
				if (i == 0) {		//top and last names comparison block
					name_top = name;
					name_bot = name;
				}
				else {
					if (name > name_top) {
						name_top = name;
					}
					else if (name < name_bot) {
						name_bot = name;
					}
				}
			}
			cool.close();
			cout << "\nName are top: " << name_bot << endl;
			cout << "Name at bot: " << name_top << endl << endl;
			cout << "File was saved as Student.txt" << endl << endl;

		}
		else  if (command == "quit") {
			cout << "\nProgram has exited. Programmer: Kevin Morales-Nguyen\t PA3\n";
		}
		else {
			cout << "Enter valid Command\n\n";
		}
	}
	return 0;
}