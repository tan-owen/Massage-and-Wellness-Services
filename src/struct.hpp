#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

struct Account {
	string accountID; 
	string accountType; // "patient", "expert", "admin"
	string username; 
	string password;
	string firstName;
	string lastName;
};
struct Expert : Account {
	string expertID;
	string expertType; // "doctor", "nurse", "therapist"
	string availableTime;
};
struct Admin : Account{
// Admin specific fields can be added here
};

struct appointment {
	string appointmentID;
	time_t appointmentDateTime;
};

