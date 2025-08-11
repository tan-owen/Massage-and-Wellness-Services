#pragma once
#include <iostream>
#include <string>
#include "struct.hpp"
#include <fstream>
#include <sstream>


// Customer Account Struct Functions
void loadFromCustomerAccountFile(struct CustomerAccount* account, int lineIndex);
void loadToCustomerAccountStruct(struct CustomerAccount* account, int arraySize);
// Expert Account Struct Functions
void loadFromExpertAccountFile(struct ExpertAccount* account, int lineIndex);
void loadToExpertAccountStruct(struct ExpertAccount* account, int arraySize);
// Admin Account Struct Functions
void loadFromAdminAccountFile(struct AdminAccount* account, int lineIndex);
void loadToAdminAccountStruct(struct AdminAccount* account, int arraySize);
// Appointment Struct Functions
void loadFromAppointmentFile(struct Appointment* appointment, int lineIndex);
void loadToAppointmentStruct(struct Appointment* appointment, int arraySize);
// Feedback Struct Functions
void loadFromFeedbackFile(struct Feedback* feedback, int lineIndex);
void loadToFeedbackStruct(struct Feedback* feedback, int arraySize);

// Print Customer Account Struct
void printAllCustomerStructs(CustomerAccount customerAccountArry[], int arraySize);
// Print Expert Account Struct
void printAllExpertStructs(ExpertAccount expertAccountArry[], int arraySize);
// Print Admin Account Struct
void printAllAdminStructs(AdminAccount adminAccountArry[], int arraySize);
// Print Appointment Struct
void printAllAppointmentStructs(Appointment appointmentArry[], int arraySize);
// Print Feedback Struct
void printAllFeedbackStructs(Feedback feedbackArry[], int arraySize);