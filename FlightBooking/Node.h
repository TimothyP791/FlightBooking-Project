#pragma once
#include "Flight.h"
#include <string>
using namespace std;
class Flight; //Forward delcration of class flight

class Node
{
private: 
	Flight* data; // Pointer to an object of the flight class
	Node* next;
public:
	Node(Flight* newFlight);	
	void book(Node* node);
	void cancel(Node* node);
	void inseartAtEnd(Node*& head, Flight*& newFlight);
	void printList(Node* n);
	void showData(Node* n, string flightNum);
	//Accessors
	string getFNData();
	Node* getNext();
	//Below are extra functions for more Linked list functionality
	//They are currently unused but may return to add more functionality later
	void inseartAtFront(Node*& head, Flight* newFlight);
	void inseartAfter(Node* previous, Flight* newFlight);
	void removeNode(Node*& head, Node* n);
};

