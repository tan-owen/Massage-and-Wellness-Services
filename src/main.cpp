#include <iostream>
#include <string>
#include <fstream>
#include "function.hpp"
#include "struct.hpp"
#include "menu.hpp"
using namespace std;


int main() {
	const int customerAccountArraySize = 999;
	const int expertAccountArraySize = 99;
	const int adminAccountArraySize = 9;
	const int appointmentArraySize = 999;
	const int feedbackArraySize = 999;

	CustomerAccount customerAccountArry[customerAccountArraySize];
	ExpertAccount expertAccountArry[expertAccountArraySize];
	AdminAccount adminAccountArry[adminAccountArraySize];
	Appointment appointmentArry[appointmentArraySize];
	Feedback feedbackArry[feedbackArraySize];
	
	// Load Account Data
	loadToCustomerAccountStruct(customerAccountArry, customerAccountArraySize);
	loadToExpertAccountStruct(expertAccountArry, expertAccountArraySize);
	loadToAdminAccountStruct(adminAccountArry, adminAccountArraySize);
	loadToAppointmentStruct(appointmentArry, appointmentArraySize);
	loadToFeedbackStruct(feedbackArry, feedbackArraySize);
	
	// Print
	printAllCustomerStructs(customerAccountArry, customerAccountArraySize);
	printAllExpertStructs(expertAccountArry, expertAccountArraySize);
	printAllAdminStructs(adminAccountArry, adminAccountArraySize);
	printAllAppointmentStructs(appointmentArry, appointmentArraySize);
	printAllFeedbackStructs(feedbackArry, feedbackArraySize);


	// Your code starts here:


















    return 0;
}

