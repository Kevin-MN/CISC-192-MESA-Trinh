/**
Body Mass Index Calculator Program:
	this program will calulate the BMI given a weight in pounds and height in inches.
	The program will continue to run via while-loop unitl the user decides to quit.
	A series of if statements is utilized to determine which range the BMI falls under.

	Name: Kevin Morales-Nguyen
	Date: 4/14/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << fixed << setprecision(2);

	//declare variables to be used in the program
	double weight_pounds;
	double height_inches;
	double BMI;
	double adjusted_weight;
	double normal_lower;
	double normal_upper;
	string status;

	cout << "Body Mass Index Calculator" << endl;

	//while loop for repeatedly calculating BMI
	char run = 'c';
	while (tolower(run) == 'c') {
		cout << "\nEnter your weight in pounds: ";
		cin >> weight_pounds;

		cout << "Enter your height in inches: ";
		cin >> height_inches;

		BMI = round((weight_pounds * 703) / (height_inches * height_inches) * 100) / 100;

		// set status based on BMI
		if (BMI < 18.5) {
			status = "Underweight";
		}
		else if (BMI >= 18.5 && BMI <= 25) {
			status = "Normal";
		}
		else if (BMI > 25 && BMI <= 30) {
			status = "Overweight";
		}
		else {
			status = "Obese";
		}

		//calculate lower and upper bounds for normal BMI range
		normal_lower = 18.50 * height_inches * height_inches / 703;
		normal_upper = 25.00 * height_inches * height_inches / 703;

		//calculate adjusted weight based on whether BMI is under or over normal range limits
		if (BMI < 18.5) {
			adjusted_weight = (18.50 * height_inches * height_inches / 703) - weight_pounds;
		}
		else if (BMI > 25) {
			adjusted_weight = (25.00 * height_inches * height_inches / 703) - weight_pounds;
		}
		else {
			adjusted_weight = 0.00;
		}

		//prints BMI ranges
		cout << "\nBMI VALUES\n(from the Department of Health and Human Services/National Institutes of Health)\n"
			<< "Underweight: less than 18.5\n"
			<< "Normal     : in the interval [18.5, 25.0]\n"
			<< "Overweight : in the interval (25.0, 30.0]\n"
			<< "Obese:     : greater than 30\n\n";

		//print calculation info
		cout << "With a weight of " << weight_pounds << " pounds and height of " << height_inches << " inches.\n"
			<< "Your BMI: " << BMI << " - You are " << status << endl;
		// print adjusted weight with '+' in front if positive or regularly if already negative
		if (adjusted_weight > 0.00) {
			cout << "Your adjusted weight: +" << adjusted_weight << " pounds to be in Normal BMI range." << endl;
		}
		else if (adjusted_weight < 0.00) {
			cout << "Your adjusted weight: " << adjusted_weight << " pounds to be in Normal BMI range." << endl;
		}
		else {
			cout << "Your BMI falls within the normal range, no need for adjustment.\n";
		}
		cout << "\nFor a height of " << height_inches << " inches a weight within " << normal_lower
			<< "-" << normal_upper << " pounds is considered Normal.\n"
			<< "\nWould you like to calculate another BMI?\n\n";

		//while loop for gathering valid input from used to continue or quit
		int rin = 0;
		while (rin == 0) {
			cout << "\'c\' to run again or \'q\' to exit : ";
			cin >> run;
			if (tolower(run) == 'c' || tolower(run) == 'q') {
				rin = 1;
			}
		}
	}

	//print name of programmer
	cout << "\nProgrammer: Kevin Morales-Nguyen\n";

	return 0;
}