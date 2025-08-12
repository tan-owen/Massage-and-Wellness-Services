#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstring>
#include "function.hpp"
#include "struct.hpp"
#include "menu.hpp"
using namespace std;


// Customer Account Struct Functions
void loadFromCustomerAccountFile(struct CustomerAccount* account, int arrayPosition) {
    string fileText;
    ifstream accountFile(RESOURCES_FOLDER + "AccountCustomer.txt");

    int currentLine = 0;
    while (getline(accountFile, fileText)) {

        if (currentLine == arrayPosition && !fileText.empty()) {
            // C0001;username=john;password=1234;firstName=John;lastName=Black;

            // Get accountID
            account[arrayPosition].customerID = fileText.substr(0, 4);

            // Get username 
            account[arrayPosition].username = fileText.substr(
                fileText.find("username=") + string("username=").length(),
                fileText.find(';', fileText.find("username=")) - (fileText.find("username=") + string("username=").length())
            );
            // Get password 
            account[arrayPosition].password = fileText.substr(
                fileText.find("password=") + string("password=").length(),
                fileText.find(';', fileText.find("password=")) - (fileText.find("password=") + string("password=").length())
            );
            // Get firstName 
            account[arrayPosition].firstName = fileText.substr(
                fileText.find("firstName=") + string("firstName=").length(),
                fileText.find(';', fileText.find("firstName=")) - (fileText.find("firstName=") + string("firstName=").length())
            );
            // Get lastName 
            account[arrayPosition].lastName = fileText.substr(
                fileText.find("lastName=") + string("lastName=").length(),
                fileText.find(';', fileText.find("lastName=")) - (fileText.find("lastName=") + string("lastName=").length())
            );

        }
        currentLine++;
    }

    accountFile.close();
}
void loadToCustomerAccountStruct(struct CustomerAccount* account, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        loadFromCustomerAccountFile(account, i);
    }
}
// Expert Account Struct Functions
void loadFromExpertAccountFile(struct ExpertAccount* account, int lineIndex) {
    string fileText;
    ifstream expertFile(RESOURCES_FOLDER + "AccountExpert.txt");
    int currentLine = 0;
    while (getline(expertFile, fileText)) {
        if (currentLine == lineIndex && !fileText.empty()) {
            // E0001;username=bob Expert;password=bob'spassword;firstName=Bob;lastName=the Builder;
            // Get expertID
            account[lineIndex].expertID = fileText.substr(0, 3);
            // Get username 
            account[lineIndex].username = fileText.substr(
                fileText.find("username=") + string("username=").length(),
                fileText.find(';', fileText.find("username=")) - (fileText.find("username=") + string("username=").length())
            );
            // Get password 
            account[lineIndex].password = fileText.substr(
                fileText.find("password=") + string("password=").length(),
                fileText.find(';', fileText.find("password=")) - (fileText.find("password=") + string("password=").length())
            );
            // Get firstName 
            account[lineIndex].firstName = fileText.substr(
                fileText.find("firstName=") + string("firstName=").length(),
                fileText.find(';', fileText.find("firstName=")) - (fileText.find("firstName=") + string("firstName=").length())
            );
            // Get lastName 
            account[lineIndex].lastName = fileText.substr(
                fileText.find("lastName=") + string("lastName=").length(),
                fileText.find(';', fileText.find("lastName=")) - (fileText.find("lastName=") + string("lastName=").length())
            );
			// Get specialization
			account[lineIndex].specialization = fileText.substr(
                fileText.find("specialization=") + string("specialization=").length(),
                fileText.find(';', fileText.find("specialization=")) - (fileText.find("specialization=") + string("specialization=").length())
            );
			// Get working hours
            account[lineIndex].workingHours.startTime = fileText.substr(
                fileText.find("workStartTime=") + string("workStartTime=").length(),
                fileText.find(';', fileText.find("workStartTime=")) - (fileText.find("workStartTime=") + string("workStartTime=").length())
            );
            account[lineIndex].workingHours.endTime = fileText.substr(
                fileText.find("workEndTime=") + string("workEndTime=").length(),
                fileText.find(';', fileText.find("workEndTime=")) - (fileText.find("workEndTime=") + string("workEndTime=").length())
            );
        }
        currentLine++;
    }
    expertFile.close();
}
void loadToExpertAccountStruct(struct ExpertAccount* account, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        loadFromExpertAccountFile(account, i);
    }
}
// Admin Account Struct Functions
void loadFromAdminAccountFile(struct AdminAccount* account, int lineIndex) {
    string fileText;
    ifstream accountFile(RESOURCES_FOLDER + "AccountAdmin.txt");

    int currentLine = 0;
    while (getline(accountFile, fileText)) {
        if (fileText.empty()) {
            continue; // Skip empty lines
        }
        if (currentLine == lineIndex) {
            account[lineIndex].adminID = fileText.substr(0, 2);
            account[lineIndex].username = fileText.substr(
                fileText.find("username=") + string("username=").length(),
                fileText.find(';', fileText.find("username=")) - (fileText.find("username=") + string("username=").length())
            );
            account[lineIndex].password = fileText.substr(
                fileText.find("password=") + string("password=").length(),
                fileText.find(';', fileText.find("password=")) - (fileText.find("password=") + string("password=").length())
            );
            account[lineIndex].firstName = fileText.substr(
                fileText.find("firstName=") + string("firstName=").length(),
                fileText.find(';', fileText.find("firstName=")) - (fileText.find("firstName=") + string("firstName=").length())
            );
            account[lineIndex].lastName = fileText.substr(
                fileText.find("lastName=") + string("lastName=").length(),
                fileText.find(';', fileText.find("lastName=")) - (fileText.find("lastName=") + string("lastName=").length())
            );
        }
        currentLine++;
    }
    accountFile.close();
}
void loadToAdminAccountStruct(struct AdminAccount* account, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        loadFromAdminAccountFile(account, i);
    }
}
//  Appointment Struct Functions
void loadFromAppointmentFile(struct Appointment* appointment, int lineIndex) {
    string fileText;
    ifstream appointmentFile(RESOURCES_FOLDER + "Appointment.txt");
    int currentLine = 0;
    while (getline(appointmentFile, fileText)) {
        if (fileText.empty()) {
            continue; // Skip empty lines
        }
        if (currentLine == lineIndex) {
            // AP001;C001;E001;serviceType=Treatment;appointmentStartTime=1200;appointmentEndTime=1300;appointmentDate=20231212;totalPaid=100.00;serviceFee=10.00;paymentStatus=true;
            appointment[lineIndex].appointmentID = fileText.substr(0, 5);
            appointment[lineIndex].customerID = fileText.substr(
                fileText.find(';') + 1,
                fileText.find(';', fileText.find(';') + 1) - (fileText.find(';') + 1)
            );
            appointment[lineIndex].expertID = fileText.substr(
                fileText.find(';', fileText.find(';') + 1) + 1,
                fileText.find(';', fileText.find(';', fileText.find(';') + 1) + 1) - (fileText.find(';', fileText.find(';') + 1) + 1)
            );
            appointment[lineIndex].serviceType = fileText.substr(
                fileText.find("serviceType=") + string("serviceType=").length(),
                fileText.find(';', fileText.find("serviceType=")) - (fileText.find("serviceType=") + string("serviceType=").length())
            );
            appointment[lineIndex].appointmentTimeSlot.startTime = fileText.substr(
                fileText.find("appointmentStartTime=") + string("appointmentStartTime=").length(),
                fileText.find(';', fileText.find("appointmentStartTime=")) - (fileText.find("appointmentStartTime=") + string("appointmentStartTime=").length())
            );
            appointment[lineIndex].appointmentTimeSlot.endTime = fileText.substr(
                fileText.find("appointmentEndTime=") + string("appointmentEndTime=").length(),
                fileText.find(';', fileText.find("appointmentEndTime=")) - (fileText.find("appointmentEndTime=") + string("appointmentEndTime=").length())
            );
            appointment[lineIndex].appointmentDate = fileText.substr(
                fileText.find("appointmentDate=") + string("appointmentDate=").length(),
                fileText.find(';', fileText.find("appointmentDate=")) - (fileText.find("appointmentDate=") + string("appointmentDate=").length())
            );
            appointment[lineIndex].serviceFee = stod(fileText.substr(
                fileText.find("serviceFee=") + string("serviceFee=").length(),
                fileText.find(';', fileText.find("serviceFee=")) - (fileText.find("serviceFee=") + string("serviceFee=").length())
            ));
            appointment[lineIndex].totalPaid = stod(fileText.substr(
                fileText.find("totalPaid=") + string("totalPaid=").length(),
                fileText.find(';', fileText.find("totalPaid=")) - (fileText.find("totalPaid=") + string("totalPaid=").length())
            ));
            appointment[lineIndex].paymentStatus = stoi(fileText.substr(
                fileText.find("paymentStatus=") + string("paymentStatus=").length(),
                fileText.find(';', fileText.find("paymentStatus=")) - (fileText.find("paymentStatus=") + string("paymentStatus=").length())
            ));
            break; // Add this line to exit the loop after finding the correct line
        }
        currentLine++;
    }
}
void loadToAppointmentStruct(struct Appointment* appointment, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        loadFromAppointmentFile(appointment, i);
    }
}
// Feedback Struct Functions
void loadFromFeedbackFile(struct Feedback* feedback, int lineIndex) {
    string fileText;
    ifstream feedbackFile(RESOURCES_FOLDER + "Feedback.txt");
    int currentLine = 0;
    while (getline(feedbackFile, fileText)) {
        if (fileText.empty()) {
            continue; // Skip empty lines
        }
        if (currentLine == lineIndex) {
            // F001;C001;AP001;E01;comment=Great service!;service=5;
            feedback[lineIndex].feedbackID = fileText.substr(0, 4);
            feedback[lineIndex].customerID = fileText.substr(
                fileText.find(';') + 1,
                fileText.find(';', fileText.find(';') + 1) - (fileText.find(';') + 1)
            );
            feedback[lineIndex].appointmentID = fileText.substr(
                fileText.find(';', fileText.find(';') + 1) + 1,
                fileText.find(';', fileText.find(';', fileText.find(';') + 1) + 1) - (fileText.find(';', fileText.find(';') + 1) + 1)
            );
            feedback[lineIndex].expertID = fileText.substr(
                fileText.find(';', fileText.find(';', fileText.find(';') + 1) + 1) + 1,
                fileText.find(';', fileText.find(';', fileText.find(';', fileText.find(';') + 1) + 1) + 1) - (fileText.find(';', fileText.find(';', fileText.find(';') + 1) + 1) + 1)
            );
            feedback[lineIndex].comment = fileText.substr(
                fileText.find("comment=") + string("comment=").length(),
                fileText.find(';', fileText.find("comment=")) - (fileText.find("comment=") + string("comment=").length())
            );
            feedback[lineIndex].rating = stoi(fileText.substr(
                fileText.find("service=") + string("service=").length(),
                string::npos
            ));
            break; // Add this line to exit the loop after finding the correct line
        }
        currentLine++;
    }
    feedbackFile.close();
}
void loadToFeedbackStruct(struct Feedback* feedback, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        loadFromFeedbackFile(feedback, i);
    }
}

// Function to print all Customer structs
void printAllCustomerStructs(CustomerAccount customerAccountArry[], int arraySize) {
    cout << "________________________________" << endl;
    cout << "Customer Account Data Loaded Successfully!";
    for (int i = 0; i < arraySize; i++) {
        if (customerAccountArry[i].customerID.empty()) {
            continue; // Skip empty customer accounts
        }
        cout << "\n________________________________" << endl;
        cout << "Account ID\t: " << customerAccountArry[i].customerID << endl;
        cout << "Username\t: " << customerAccountArry[i].username << endl;
        cout << "Password\t: " << customerAccountArry[i].password << endl;
        cout << "First Name\t: " << customerAccountArry[i].firstName << endl;
        cout << "Last Name\t: " << customerAccountArry[i].lastName << endl;
    }
}
// Function to print all Expert structs
void printAllExpertStructs(ExpertAccount expertAccountArry[], int arraySize) {
    cout << "\n________________________________" << endl;
    cout << "Expert Account Data Loaded Successfully!" << endl;
    for (int i = 0; i < arraySize; i++) {
        if (expertAccountArry[i].expertID.empty()) {
            continue; // Skip empty expert accounts
        }
        cout << "________________________________" << endl;
        cout << "Account ID\t: " << expertAccountArry[i].expertID << endl;
        cout << "Username\t: " << expertAccountArry[i].username << endl;
        cout << "Password\t: " << expertAccountArry[i].password << endl;
        cout << "First Name\t: " << expertAccountArry[i].firstName << endl;
        cout << "Last Name\t: " << expertAccountArry[i].lastName << endl;
		cout << "Specialization\t: " << expertAccountArry[i].specialization << endl;
		cout << "Working Days\t: " << expertAccountArry[i].workingHours.day << endl;
		cout << "Working Hours\t: " << expertAccountArry[i].workingHours.startTime << " - " << expertAccountArry[i].workingHours.endTime << endl;

    }
}
// Function to print all Admin structs
void printAllAdminStructs(AdminAccount adminAccountArry[], int arraySize) {
    cout << "\n________________________________" << endl;
    cout << "Admin Account Data Loaded Successfully!" << endl;
    for (int i = 0; i < arraySize; i++) {
        if (adminAccountArry[i].adminID.empty()) {
            continue; // Skip empty admin accounts
        }
        cout << "________________________________" << endl;
        cout << "Account ID\t: " << adminAccountArry[i].adminID << endl;
        cout << "Username\t: " << adminAccountArry[i].username << endl;
        cout << "Password\t: " << adminAccountArry[i].password << endl;
        cout << "First Name\t: " << adminAccountArry[i].firstName << endl;
        cout << "Last Name\t: " << adminAccountArry[i].lastName << endl;
    }
}
// Function to print all Appointment structs
void printAllAppointmentStructs(Appointment appointmentArry[], int arraySize) {
    cout << "\n________________________________" << endl;
    cout << "Appointment Data Loaded Successfully!" << endl;
    for (int i = 0; i < arraySize; i++) {
        if (appointmentArry[i].appointmentID.empty()) {
            continue; // Skip empty appointments
        }
        cout << "________________________________" << endl;
        cout << "Appointment ID\t: " << appointmentArry[i].appointmentID << endl;
        cout << "Customer ID\t: " << appointmentArry[i].customerID << endl;
        cout << "Expert ID\t: " << appointmentArry[i].expertID << endl;
        cout << "Service Type\t: " << appointmentArry[i].serviceType << endl;
        cout << "Start Time\t: " << appointmentArry[i].appointmentTimeSlot.startTime << endl;
        cout << "End Time\t: " << appointmentArry[i].appointmentTimeSlot.endTime << endl;
        cout << "Appointment Date: " << appointmentArry[i].appointmentDate << endl;
        cout << "Total Paid\t: RM" << appointmentArry[i].totalPaid << endl;
        cout << "Service Fee\t: RM" << appointmentArry[i].serviceFee << endl;
        cout << "Payment Status\t: " << (appointmentArry[i].paymentStatus ? "Paid" : "Unpaid") << endl;
    }
}
// Function to print all Feedback structs
void printAllFeedbackStructs(Feedback feedbackArry[], int arraySize) {
    cout << "\n________________________________" << endl;
    cout << "Appointment Data Loaded Successfully!" << endl;
    for (int i = 0; i < arraySize; i++) {
        if (feedbackArry[i].feedbackID.empty()) {
            continue; // Skip empty appointments
        }
        cout << "________________________________" << endl;
        cout << "Feedback ID\t: " << feedbackArry[i].feedbackID << endl;
        cout << "Customer ID\t: " << feedbackArry[i].customerID << endl;
        cout << "Appointment ID\t: " << feedbackArry[i].appointmentID << endl;
        cout << "Expert ID\t: " << feedbackArry[i].expertID << endl;
        cout << "Comment ID\t: " << feedbackArry[i].comment << endl;
        cout << "Rating\t\t: " << feedbackArry[i].rating << endl;
    }
}