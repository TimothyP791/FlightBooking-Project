#pragma once
#include "Node.h"
#include <string>
using namespace std;
class Flight
{
private:
	string flightNum, location, departureTime, arrivalTime, status, bookingStatus;
public:
	Flight(string fn, string local, string dt, string at, string s, string bs):
	flightNum(fn), location(local), departureTime(dt), arrivalTime(at), status(s), bookingStatus(bs) {}
	
	//Manipulators
	void setLocation(string l);
	void setDT(string dt);
	void setAT(string at);
	void setStatus(string s);
	void setBS(string bs);
	void setFN(string fn);
	//accessors
	string getFN();			
	string getLocal();
	string getDT();
	string getAT();
	string getStatus();
	string getBS();
	

};

