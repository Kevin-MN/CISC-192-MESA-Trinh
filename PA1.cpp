/*
 This is the Pool Calculator program which calculates 
 the price of filling up a pool given the volume and 
 price per cubic foot. The program prompt the user for length,
 width, and height , makes calculations and then prints 
 out the calculations.

 Name: Kevin T Morales-Nguyen
 Date: 4/6/2020
 */


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//set decimal precision to two decimal places for reasonable output
	std::cout << std::setprecision(2) << std::fixed;

	//program info
	cout << "\t\tPool Calculator\n"
		<< "This program calculates and prints the pool's total volume,\n"
		<< "the volume of water needed and total cost to fill.\n\n";

	//declare and initialize constants and variables
	double price_per_cubic_foot = 0.77;
	double one_time_fee = 100.00;
	double length;
	double width;
	double depth;
	
	//prompt user
	cout << "Enter pool's length (feet): ";
	cin >> length;
	cout << "Enter pool's width (feet): ";
	cin >> width;
	cout << "Enter pool's depth (feet): ";
	cin >> depth;

	//make calculations
	double total_volume = length * width * depth;
	//3 inches is 0.25ft so subtract from depth and recalculate volume
	double chargable_volume = length * width * (depth - .25);
	double total_cost = (chargable_volume * price_per_cubic_foot) + one_time_fee;

	//print all information 
	cout << "\n\t***Invoice***\n"
		<< "      MN Brothers Pool Co.\n"
		<< "Pool:"
		<< "\n   Length: " << length << "ft" << endl
		<< "   Width: " << width << "ft" << endl
		<< "   Depth: " << depth << "ft" << endl
		<< "Pool's total volume: " << total_volume << "ft^3" << endl
		<< "Volume of water needed: " << chargable_volume << "ft^3" << endl
		<< "Total cost: $" << total_cost << endl
		<< "\nProgrammer: Kevin T Morales-Nguyen" << endl;

		return 0;
}
