#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct accountCustomer {
	string username;
	string password;
	string firstName;
	string lastName;
};
struct accountExpert {
	string username;
	string password;
	string firstName;
	string lastName;
	int day;
	string timeslot[5]; // {"1200-1400",1400-1500,,,}
};
struct accountAdmin{
	string username;
	string password;
	string firstName;
	string lastName;
};

struct appointment {
	string appointmentID;
	time_t appointmentDateTime;
};


accountExpert expert[100];