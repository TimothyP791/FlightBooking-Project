#include "Node.h"
#include "Flight.h"
#include <iostream>
using namespace std;

Node::Node(Flight* newFlight)
{
	data = newFlight;
	next = nullptr;
}

string Node::getFNData() 
{
	return data->getFN();
}

Node* Node::getNext()
{
	return next;
}

void Node::book(Node* node)// Helper fucntion that allows User class to change booking status
{
		node->data->setBS("Booked");	
}
void Node::cancel(Node* node)// Helper fucntion that allows User class to change booking status
{
	node->data->setBS("Not Booked");
}

void Node::inseartAtFront(Node*& head, Flight* newFlight) 
{
	Node* newNode = new Node(newFlight); //Allocate memory for new node

	//newNode->data = newFlight;			 //Set new node data to the input flight
	if (head == nullptr) {				 //Check if list is empty
		head = newNode;
	}
	else 
	newNode->next = head;				 //Set next pointer to current head of list
	head = newNode;						 //Set head to newNode
}

void Node::inseartAtEnd(Node*& head, Flight*& newFlight)
{
	Node* temp;
	Node* newNode = new Node(newFlight);
	//newNode->data = newFlight;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void Node::inseartAfter(Node* previous, Flight* newFlight)
{
	if (previous == nullptr) {
		cout << "Previous cannot equal null" << endl;
		return;
	}
	
	Node* newNode = new Node(newFlight);

	//newNode->data = newFlight;
	newNode->next = previous->next;
	previous->next = newNode;
	
}

void Node::printList(Node* n)
{
	while (n != nullptr) {
		cout << n->data->getFN() << endl;
		cout << n->data->getLocal() << endl;
		cout << n->data->getDT() << endl;
		cout << n->data->getAT() << endl;
		cout << n->data->getStatus() << endl;
		cout << n->data->getBS() << endl << endl;
		n = n->next;
	}

	
}

void Node::showData(Node* n, string flightNum)
{
	while (n->data->getFN() != flightNum) {
		n = n->next;
	}
	cout << n->data->getFN() << endl;
	cout << n->data->getLocal() << endl;
	cout << n->data->getDT() << endl;
	cout << n->data->getAT() << endl;
	cout << n->data->getStatus() << endl;
	cout << n->data->getBS() << endl;
}


void Node::removeNode(Node*& head, Node* n)
{
	Node* temp;
	temp = head;
	while (temp->next != n) {
		temp = temp->next;
	}
	temp->next = n->next;
	delete n;
	n = nullptr;
}
