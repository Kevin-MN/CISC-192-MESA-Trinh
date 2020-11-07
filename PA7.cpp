/*
	This program will compute all possible words given a seven digit number and will 
	display the words on screen as well as write to a text file.

	Date:5/23/2020

	Programmer Kevin Morales-Nguyen
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Number_Permutation_Writer class used as an object in main to implement program
class Number_Permutation_Writer {
private:
	//private members
	fstream filestream;
	string number;
	string filename;
	vector<string> codings = {"","", "abc", "def","ghi","jkl", "mno","pqrs","tuv","wxyz" };
	vector<string> permutes;
	vector<int> indexes;
	vector<int> digits;
public:
	//public members

	//default constructor
	Number_Permutation_Writer() {
		this->filename = "Words.txt";
		this->number = "";
		this->filestream.open(this->filename, ios::out);
	}

	//default destructor
	~Number_Permutation_Writer() {
		filestream.close();
	}

	//prints a int vector
	void print_vector(vector<int>& vectorp) {
		for (int i = 0; i < vectorp.size(); i++) {
			cout << vectorp[i] << " ";
		}
		cout << endl;
	}
	
	// empties a int vector
	void emptyVector(vector<int>& myvec) {
		for (int e : myvec) {
			myvec.erase(myvec.begin());
		}
	}

	//empties a string vector
	void emptyVectorS(vector<string>& myvec) {
		for (string e : myvec) {
			myvec.erase(myvec.begin());
		}
	}
	
	//checks if user input is valid for number variable
	void check_number(bool &mybool) {
		if (this->number.size() != 7) {
			cout << endl <<  "Please enter a seven digit number." << endl << endl;
			mybool = false;
		}
	}
	
	//the bulk method that will generate permutations and write
	void generate_and_write_permutations() {
		// temp local variables used by method
		int count = 0;
		int permutecount = 0;
		int permutes2 = 1;
		bool permutef = false;

		//empty instance members for reuse
		emptyVector(digits);
		emptyVector(indexes);
		emptyVectorS(permutes);

		filestream << "\n";
		cout << "\n";
		//convert string digits to int digits and add to respective vectors for processing
		for (char e : this->number) {
			if (isdigit(e)) {
				int temp = (int)(e - '0');
				if (temp > 1 && temp < 10) {
					digits.push_back(temp);
					indexes.push_back(count);
				}
			}
			count++;
		}

		
		//calculate total possible words
		for (int i = 0; i < digits.size(); i++) {
			permutes2 *= codings[digits[i]].size();
		}

		cout << "For number " << this->number << " there are " << permutes2 << " possible words." << endl << endl;
		filestream << "For number " << this->number << " these are " << permutes2 << " possible words." << endl << endl;

		// permutations via random generator is terrible and impractical for numbers with more coded digits. There is a more optimal approach.
		// I spent a whole day trying to generalize the formula for permutations, but could not figure it out so I went with the randomizer.
		// Performance is barely acceptable for a reasonable  digit number, would take forever if 999999, after 2000+ permutations it takes forever
		// I always think about order and computation efficiency and I would have loved to solve the problem efficiently and more importantly
		//correctly, it is just that I have two final projects that I have to start working on so own the loss on this one.
		while (permutecount < permutes2) { 
			permutef = false;
			//set all coded digits to random char
			for (int i = 0; i < digits.size(); i++) {
				number[indexes[i]] = codings[digits[i]].at(rand() % codings[digits[i]].size());
			}
			//check to see if the permutation has already been found
			for (string e : permutes) {
				if (number == e) {
					permutef = true;
				}
			}
			//if it has not been added add to found permutations vector
			if (permutef != true) {
				permutes.push_back(number);
				permutecount++;
			}
		}

		//sort the permutations 
		sort(permutes.begin(), permutes.begin() + permutes.size());

		int count2 = 1;
		//display permutations and write to file
		for (string e : permutes) {
			cout << setw(12) << right << count2 << "." << e;
			filestream << setw(12) << right << count2 << "." << e;
			if (count2 > 0 && (count2 % 4 == 0)) {
				cout << endl;
				filestream << "\n";
			}
			count2++;
		}
		cout << endl << endl;
		filestream << endl << endl;
	}
	
	//used to get number form user
	void get_number() {
		cout << "\nEnter a phone number: ";
		getline(cin, this->number);
	}
	
	//used for debugging
	void print_number() {
		cout << this->number;
	}
};

int main() {
	//declare and initialize valriables used in the program.
	Number_Permutation_Writer number_writer; // object used to implement program
	stringstream ss;
	string temp;
	bool valid;
	string status = "o";
	
	cout << "This program will compute all possible words based on a phone number \n\n";
	//main program loop
	while (status != "n") {

		// loop for gathering user input
		while (true) {
			valid = true;
			number_writer.get_number();
			number_writer.check_number(valid);

			if (valid) {
				number_writer.generate_and_write_permutations();
				break;
			}
		}

		//prompt user to run again
		while (true) {
			cout << "\n\nTry another number? (y/n) ";
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

	cout << "\n\n\tProgrammer: Kevin Morales-Nguyen PA7\n\n";

	return 0;
}
