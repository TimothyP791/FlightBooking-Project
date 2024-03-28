#include "User.h"
#include "Node.h"
#include <iostream>
using namespace std;

string User::getName()
{
	return name;
}

string User::getAddress()
{
	return address;
}

void User::bookFlight(Node* head, string flightNum)
{
	while (head->getFNData() != flightNum) {
		head = head->getNext();
	}
	head->book(head);
}

void User::cancelFlight(Node* head, string flightNum)
{
	while (head->getFNData() != flightNum) {
		head = head->getNext();
	}
	head->cancel(head);
}

void User::printTicket(Node* head, string flightNum)
{
	cout << name << endl;
	cout << address << endl;
	head->showData(head, flightNum);
}

void User::setName(string n)
{
	name = n;
}

void User::setAdd(string add)
{
	address = add;
}
