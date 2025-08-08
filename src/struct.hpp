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

struct Account {
    string accountID;
    string accountType; // "customer", "expert", "admin"
    string username;
    string password;
    string firstName;
    string lastName;
};

struct Expert : public Account {
    string expertID;
    string specialization;
    bool workingTimeslot[31][24]; 
    int totalTreatmentHours;    // calculated based on booked timeslots
    int totalConsultationHours; 
    double totalServiceCharges;  
};

struct Service {
    string serviceID;
    string name;
    string description;
    double price;
    double serviceCharge;
    int durationMinutes; // e.g., 60 for 1 hour
};

struct Appointment {
    string appointmentID;
    string customerID;
    string expertID;
    string serviceID;
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
