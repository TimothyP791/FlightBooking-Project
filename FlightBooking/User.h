#pragma once
#include "Node.h"
#include <string>
using namespace std;

class User
{
private: 
	string name, address;

public: 
	void printTicket(Node* head, string flightNum);
	void bookFlight(Node* head, string flightNum);
	void cancelFlight(Node* head, string flightNum);
	//Manipulators
	void setName(string name);		
	void setAdd(string add);
	//Accessors
	string getName();				
	string getAddress();			
	
};

