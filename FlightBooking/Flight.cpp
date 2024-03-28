#include "Flight.h"
#include <iostream>
using namespace std;

void Flight::setLocation(string l)
{
	location = l;
}

void Flight::setDT(string dt)
{
	departureTime = dt;
}

void Flight::setAT(string at)
{
	arrivalTime = at;
}

void Flight::setStatus(string s)
{
	status = s;
}

void Flight::setBS(string bs)
{
	bookingStatus = bs;
}

void Flight::setFN(string fn) 
{
	flightNum = fn;
}

string Flight::getFN() 
{
	return flightNum;
}

string Flight::getLocal()
{
	return location;
}

string Flight::getDT()
{
	return departureTime;
}

string Flight::getAT()
{
	return arrivalTime;
}

string Flight::getStatus()
{
	return status;
}

string Flight::getBS()
{
	return bookingStatus;
}

