#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

// Customer Account File Format:
// C010;username=olivia;password=olivia1;firstName=Olivia;lastName=Martinez;
struct CustomerAccount {
    string customerID;
    string username;
    string password;
    string firstName;
    string lastName;
};

// Expert Account File Format:
// E01;username=bob Expert;password=bob'spassword;firstName=Bob;lastName=the Builder;
struct ExpertAccount {
    string expertID;
    string username;
    string password;
    string firstName;
    string lastName;
    string specialization;

};

// Admin Account File Format:
// A1;username=admin;password=admin123;firstName=Admin;lastName=User;
struct AdminAccount {
    string adminID;
    string username;
    string password;
    string firstName;
    string lastName;
};

struct AppointmentTimeSlot {
    string startTime; // 24-hour format (e.g., 1400 for 2 PM)
    string endTime;   // 24-hour format (e.g., 1600 for 4 PM)
};;


// Appointment File Format:
// AP001;C001;E01;serviceType=Treatment;appointmentStartTime=1200;appointmentEndTime=1300;appointmentDate=20231212;totalPaid=100.00;serviceFee=10.00;paymentStatus=true;
struct Appointment {
    string appointmentID;
    string customerID;
    string expertID;
    string serviceType;
	AppointmentTimeSlot appointmentTimeSlot; // appointmentTimeSlot.startTime or appointmentTimeSlot.endTime to access
	string appointmentDate; // YYYYMMDD format (e.g., 20231212 for Dec 12, 2025)
    double totalPaid;
	double serviceFee; // Fee charged for the service
    bool paymentStatus = 0;
};

// Feedback File Format:
// F001;C001;AP001;E01;comment=Great service!;service=5;
struct Feedback {
    string feedbackID;
    string customerID;
    string appointmentID;
    string expertID;
    string comment;
    int rating; // 1-5
};
