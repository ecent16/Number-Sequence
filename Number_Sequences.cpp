// DataStructure_Assignment5_Part2_Centeno.cpp 
// Ervin Centeno
// March 5, 2019

#include "pch.h"
#include "Sort_Sequence_Centeno.h"
#include <iostream>
#include <cctype>
#include <cassert>
#include <cstdlib>

using namespace std;

// FUNCTION PROTOTYPE
void print_menu();
// Postcondition: This function will print out the main menu text.

char get_user_command();
// Preconditon: User is prompted to enter a one character command.
// Postcondition: The next character has been read and the character has been removed.

void show_sequence(sort_sequence display);
// Postcondition: This will print out the current sequence.

double get_number();
// Precondtion: User inputs a real number, either and integer or a decimal.
// Postcondition: Function will print out the input value on the screen and returned
// by the funtion. 

double get_index();
// Precontion: User types in the which index in the array they want to access.
// Postcondition: The function returns the value stored in selected index.

sort_sequence test; // A sequence that will perform tests on.

int main()
{

	char choice;   // A command character entered by the user.

	cout << "I have initialized an empty sequence of real numbers." << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case '!': test.start();
			break;
		case '+': test.advance();
			break;
		case '?': if (test.is_item())
			cout << "There is an item." << endl;
				  else
			cout << "There is no current item." << endl;
			break;
		case 'C': if (test.is_item())
			cout << "Current item is: " << test.current() << endl;
				  else
			cout << "There is no current item." << endl;
			break;
		case 'P': show_sequence(test);
			break;
		case 'S': cout << "Size is " << test.size() << '.' << endl;
			break;
		case 'I': test.insert_sort(get_number());
			break;
		
		case 'R': test.remove_current();
			cout << "The current item has been removed." << endl;
			break;
		
		case 'Q': cout << "Ridicule is the best test of truth." << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " !   Activate the start( ) function" << endl;
	cout << " +   Activate the advance( ) function" << endl;
	cout << " ?   Print the result from the is_item( ) function" << endl;
	cout << " C   Print the result from the current( ) function" << endl;
	cout << " P   Print a copy of the entire sequence" << endl;
	cout << " S   Print the result from the size( ) function" << endl;
	cout << " I   Insert a new number with the insert(...) function" << endl;
	cout << " A   Attach a new number with the attach(...) function" << endl;
	cout << " R   Activate the remove_current( ) function" << endl;
	cout << " Q   Quit this test program" << endl;

	// New Commands
	cout << " F   Insert a new number at the beginning of the sequence" << endl;
	cout << " L   Insert a number last in the sequence" << endl;
	cout << " CL  Assigns the last item in the sequence as current" << endl;
	cout << " D   Allows you to find a value in a specific location in the sequence" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

void show_sequence(sort_sequence display)
// Library facilities used: iostream
{
	for (display.start(); display.is_item(); display.advance())
		cout << display.current() << endl;
}

double get_number()
// Library facilities used: iostream
{
	double result;

	cout << "Please enter a real number for the sequence: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}
double get_index() {

	double index;

	cout << "Choose an index to access: " << endl;
	cin >> index;
	return index;

}