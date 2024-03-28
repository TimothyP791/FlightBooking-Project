// FlightBooking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Flight.h"
#include "User.h"
#include "Node.h"
using namespace std;

int main()
{
	ifstream flightFile;
	char choice;
	string location, departureTime, arrivalTime, status, bookingStatus, flightNum;// strings for flight output
	string name, address;	// strings for users information
	Node* head = nullptr; // initialize head pointer to null for empty list
	User user;

	flightFile.open("Flights.txt");

	// While loop to read data from a file and populate the linked list
	while (getline(flightFile, flightNum) &&
		getline(flightFile, location) &&				
		getline(flightFile, departureTime) &&
		getline(flightFile, arrivalTime) &&
		getline(flightFile, status) &&
		getline(flightFile, bookingStatus)) {
		
		// Initialized flight values to read in values
		Flight* currentFlight = new Flight(flightNum, location, departureTime,arrivalTime,status, bookingStatus); 
		
		//start inputing flights into linked list using insert at end function
		if (head == nullptr) {
			head = new Node(currentFlight);
		}
		else {
			//Insert subsequent flights ant the end of the list
			head->inseartAtEnd(head, currentFlight);
		}
	}// TO DO:
	//Fix print ticket function in User.cpp
	// 
	
	cout << "Please enter your name and address for booking information" << endl;
	cout << "Name:";
	getline(cin, name);
	cout << endl;
	cout << "Address:";
	getline(cin, address);
	user.setName(name);
	user.setAdd(address);
	cout << endl;

	//Ask User if they would like to see a list of availiable flights
	cout << "Hello would you like to see a list of available flights. Enter Y/y or N/n or E/e to exit program" << endl;
	do {
		cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			//Print list of flights
			head->printList(head); 
			
		}
		else if (choice == 'N' || choice == 'n') {
			cout << "Okay" << endl;
		}
		else if (choice == 'E' || choice == 'e') {
			return 0;
		}
		else {
			cout << "Please enter a valid choice Y/y, N/n or E/e" << endl;
		}
	
	//Check if user wants to book any flights
	cout << "Would you like to book any flights Y/N" << endl;
	cin >> choice; 
	if (choice == 'Y' || choice == 'y') {
		// Ask user for flight Number to choose booking
		cout << "Please enter the flight Number of the flight you would like to book" << endl;
		cin >> flightNum;
		cout << endl;
		user.bookFlight(head, flightNum);
		head->showData(head, flightNum);
	 }
	else if (choice == 'N' || choice == 'n') {
		cout << "Okay" << endl;
	}
	else {
		cout << "Please enter a valid choice Y/y, N/n or E/e" << endl;
	}
	//Check if user wants to cancel any flights 
	cout << "Would you like to cancel any Flights" << endl;
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		cout << "Please enter the flight Number of the flight you would like to cancel" << endl;
		cin >> flightNum;
		cout << endl;
		user.cancelFlight(head, flightNum);
		head->showData(head, flightNum); 
	}
	else if (choice == 'N' || choice == 'n') {
		cout << "Okay" << endl;
	}
	else if (choice == 'E' || choice == 'e') {
		return 0;
	}
	else {
		cout << "Please enter a valid choice Y/y, N/n or E/e" << endl;
	} 
	//Check if user would like to print a flight ticket
	cout << "Would you like to Print a flight ticket" << endl;
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		cout << "Please enter the flight Number of the flight you would like to Print" << endl;
		cin >> flightNum;
		cout << endl;
		user.printTicket(head, flightNum);
	}
	else if (choice == 'N' || choice == 'n') {
		cout << "Okay you have reched the end of possible options please come again" << endl;
	}
	else if (choice == 'E' || choice == 'e') {
		return 0;
	}
	else {
		cout << "Please enter a valid choice Y/y, N/n or E/e" << endl;
	}

	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

	flightFile.close();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
