#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

// accountID has identifier for account type
//(accountID)_username =
//(accountID)_password =
//(accountID)_firstName =
//(accountID)_lastName =

struct CustomerAccount {
    string customerID;
    string username;
    string password;
    string firstName;
    string lastName;
};

struct ExpertAccount {
    string expertID;
    string username;
    string password;
    string firstName;
    string lastName;
    string specialization;

};

struct Appointment {
    string appointmentID;
    string customerID;
    string expertID;
    string serviceType;
	int appointmentTime; // 24-hour format (e.g., 1400 for 2 PM)
	int appointmentDate; // YYYYMMDD format (e.g., 20231212 for Dec 12, 2025)
    double totalPaid;
    bool paymentStatus;
};

struct Feedback {
    string feedbackID;
    string customerID;
    string serviceID;
    string expertID;
    string comment;
    int rating; // 1-5
};
