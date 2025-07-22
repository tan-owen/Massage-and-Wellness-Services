#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct account {
	string username;
	string password;
	string firstName;
	string lastName;
	string accoutType;
};

struct appointment {
	string appointmentID;
	time_t appointmentDateTime;
};