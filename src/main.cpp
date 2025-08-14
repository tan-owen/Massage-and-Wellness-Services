#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const std::string RESOURCES_FOLDER = "res/";

// Customer Account File Format:
// C010;username=olivia;password=olivia1;firstName=Olivia;lastName=Martinez;
struct CustomerAccount {
    string customerID;
    string username;
    string password;
    string firstName;
    string lastName;
};

struct ExpertWorkingHours {
    string day = "Monday - Friday"; // Moneday to Friday
    string startTime; // 24-hour format (e.g., "0900" for 9 AM)
    string endTime;   // 24-hour format (e.g., "1700" for 5 PM)
};

// Expert Account File Format:
// E01;username=bob Expert;password=bob'spassword;firstName=Bob;lastName=the Builder;specializatoin=Massage;workStartTime=0900;workEndTime=1700;
struct ExpertAccount {
    string expertID;
    string username;
    string password;
    string firstName;
    string lastName;
    string specialization;
    ExpertWorkingHours workingHours; // Array of working hours for each day (Monday to Friday)
    // REMINDER TO ADD WOWRKING HOURS
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
};


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

// View expert individual schedule
int expertScheduleMenuSelection();
int expertDailyScheduleInput();
int expertWeeklyScheduleInput();
int calculateWeek(int dateInput);
void expertDailySchedule(ExpertAccount expertAccountArray[], Appointment appointmentArray[], int expertDailyScheduleInput, int arraySize, int week);
void expertWeeklySchedule(ExpertAccount expertAccountArray[], Appointment appointmentArray[], int arraySize, int week);


int main() 
{
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
	
	//Load Account Data
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

    int dateInput, week;
    int menuInput = expertScheduleMenuSelection();
    

    switch (menuInput)
    {
    case 1:
        dateInput = expertDailyScheduleInput();
        week = calculateWeek(dateInput);
        expertDailySchedule(expertAccountArry, appointmentArry, dateInput, appointmentArraySize, week);
        break;
    case 2:
        week = expertWeeklyScheduleInput();
        expertWeeklySchedule(expertAccountArry, appointmentArry, appointmentArraySize, week);
        break;
    case 3: 
        // return to menu function
        cout << "Going Back to Main Menu"; 
        break;
    default:
        ;
    }

















    return 0;
}

int expertScheduleMenuSelection()
{
    int expertInput;
    cout << "Select from the menu below. (1 - 3)\n";
    cout << "1. View Daily Schedule\n";
    cout << "2. View Weekly Schedule\n";
    cout << "3. Return to menu\n\n";
    cout << "Option: ";
    cin >> expertInput;

    while (expertInput > 3 || expertInput < 1)
    {
        cout << "\nError! Please enter a valid option (1 - 3).\n";
        cout << "Select from the menu below. (1 - 3)\n";
        cout << "1. View Daily Schedule\n";
        cout << "2. View Weekly Schedule\n";
        cout << "3. Return to menu\n\n";
        cout << "Option: ";
        cin >> expertInput;
    }


    switch (expertInput)
    {
    case 1:
        return 1; // Enter daily schedule menu
    case 2:
        return 2; // Enter weekly schedule menu
    case 3:
        return 3; // Return to expert menu function()
    default:
        return 0; 
    }
}

int expertDailyScheduleInput()
{
    int daysInMonth = 31;
    int currentDay = 1;
    int dateInput;

    cout << "Calendar for December 2025\n";
    cout << "____________________________________\n\n";

    cout << setw(7) << " " << "SU MO TU WE TH FR SA\n"; // Display the days of the week 
    cout << setw(3) << " "; // Blank space for 30 Dec Sunday

    cout << setw(7) << " ";
    for (int i = 0; i < 6; i++) { // Display 6 days only in the first week
        cout << setw(2) << currentDay++ << " ";
    }


    int dayOfWeek = 7; // Display the rest of the 7 days in the week
    for (int i = currentDay; i <= daysInMonth; i++) {
        if (dayOfWeek % 7 == 0) {
            cout << "\n";
            cout << setw(7) << " ";
        }
        cout << setw(2) << i << " ";
        dayOfWeek++;
    }

    cout << "\n____________________________________\n\n";
    cout << "Select the day of the month to view your schedule (1 - 31): ";
    cin >> dateInput;

    while (dateInput > 31 || dateInput < 1)
    {
        cout << "\nError! Please enter a valid day. (1 - 31).\n";
        cout << "Select the day of the month to view your schedule (1 - 31): ";
        cin >> dateInput;
    }

    return dateInput;
}

int expertWeeklyScheduleInput()
{
    int daysInMonth = 31;
    int currentDay = 1;
    int weekInput;

    cout << "Calendar for December 2025\n";
    cout << "____________________________________\n\n";

    cout << setw(7) << " " << "SU MO TU WE TH FR SA\n"; // Display the days of the week 
    cout << setw(3) << " "; // Blank space for 30 Dec Sunday

    cout << setw(7) << " ";
    for (int i = 0; i < 6; i++) { // Display 6 days only in the first week
        cout << setw(2) << currentDay++ << " ";
    }

    int dayOfWeek = 7; // Display the rest of the 7 days in the week
    for (int i = currentDay; i <= daysInMonth; i++) {
        if (dayOfWeek % 7 == 0) {
            cout << "\n";
            cout << setw(7) << " ";
        }
        cout << setw(2) << i << " ";
        dayOfWeek++;
    }

    cout << "\n____________________________________\n\n";
    cout << "Note: Each new week starts on MONDAY!\n";
    cout << "Select the week of the month to view your schedule (1 - 5): ";
    cin >> weekInput;

    while (weekInput > 5 || weekInput < 1)
    {
        cout << "\nError! Please enter a valid week. (1 - 5)\n";
        cout << "Select the week of the month to view your schedule (1 - 5): ";
        cin >> weekInput;
    }

    return weekInput;
}

int calculateWeek(int day)
{
    if (day >= 1 && day <= 7)
    {
        return 1;
    }
    else if (day >= 8 && day <= 14)
    {
        return 2;
    }
    else if (day >= 15 && day <= 21)
    {
        return 3;
    }
    else if (day >= 22 && day <= 28)
    {
        return 4;
    }
    else if (day >= 29 && day <= 31)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

void expertDailySchedule(ExpertAccount expertAccountArray[], Appointment appointmentArray[], int expertDailyScheduleInput, int arraySize, int week)
{
    int i = 1; // Logged in expert user ID
    int workingHoursCount = 0;
    int indexNumber = 1;

    cout << "\n\nViewing Daily Schedule\n";
    cout << "Name: " << expertAccountArray[i].firstName << " " << expertAccountArray[i].lastName;
    cout << "\nWeek: " << week << "\n"; 
    cout << "-------------------------------------------------------------------------\n";
    cout << left << setw(6) << "No."
        << setw(15) << "Date"
        << setw(12) << "Start Time"
        << setw(12) << "End Time"
        << setw(20) << "Service Type"
        << setw(20) << "Customer ID" << "\n";
    cout << "-------------------------------------------------------------------------\n";
    

    for (int j = 0; j < arraySize; j++) // j is appointment under expert
    {

        if (appointmentArray[j].appointmentID.empty()) {
            continue; // Skip empty appointments
        }
        
        else if (appointmentArray[j].expertID == expertAccountArray[i].expertID && stoi(appointmentArray[j].appointmentDate.substr(6,2)) == expertDailyScheduleInput) 
        // Loop through appointments that match with current expert
        {
            cout << left << setw(6) << indexNumber
                << "Dec " << setw(11) << expertDailyScheduleInput
                << setw(12) << appointmentArray[j].appointmentTimeSlot.startTime
                << setw(12) << appointmentArray[j].appointmentTimeSlot.endTime
                << setw(20) << appointmentArray[j].serviceType
                << setw(20) << appointmentArray[j].customerID << "\n";

            int startHour = stoi(appointmentArray[j].appointmentTimeSlot.startTime.substr(0, 2));
            int endHour = stoi(appointmentArray[j].appointmentTimeSlot.endTime.substr(0, 2));

            workingHoursCount += endHour - startHour;
            indexNumber++;
        }
        
    }
    
    cout << "\nTotal Working Hours: " << workingHoursCount << "\n\n";

    //cout << "Enter any key to return to menu.";  change the contents later
    //cin.get();

    // return 0; change function to int, to return to menu.
}

void expertWeeklySchedule(ExpertAccount expertAccountArray[], Appointment appointmentArray[], int arraySize, int week)
{
    int i = 1; // Logged in expert user ID
    int indexNumber = 1;
    int startDay = 0;
    int endDay = 0;
    if (week == 1) 
    { 
        startDay = 1; endDay = 7; 
    }
    
    else if (week == 2) 
    { 
        startDay = 8; endDay = 14; 
    }
    
    else if (week == 3) 
    { 
        startDay = 15; endDay = 21; 
    }
    
    else if (week == 4) 
    { 
        startDay = 22; endDay = 28; 
    }
    
    else if (week == 5) 
    { 
        startDay = 29; endDay = 31; 
    }

    cout << "\n\nViewing Weekly Schedule\n";
    cout << "Name: " << expertAccountArray[i].firstName << " " << expertAccountArray[i].lastName;
    cout << "\nWeek: " << week << "\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << left << setw(6) << "No."
        << setw(15) << "Date"
        << setw(12) << "Start Time"
        << setw(12) << "End Time"
        << setw(20) << "Service Type"
        << setw(20) << "Customer ID" << "\n";
    cout << "-------------------------------------------------------------------------\n";

    for (int j = 0; j < arraySize; j++) // j is appointment under expert
    {

        if (appointmentArray[j].appointmentID.empty()) {
            continue; // Skip empty appointments
        }

        else if (appointmentArray[j].expertID == expertAccountArray[i].expertID 
            && stoi(appointmentArray[j].appointmentDate.substr(6, 2)) >= startDay 
            && stoi(appointmentArray[j].appointmentDate.substr(6, 2)) <= endDay)
            // Loop through appointments that match with current expert
        {
            cout << left << setw(6) << indexNumber
                << "Dec " << setw(11) << appointmentArray[j].appointmentDate.substr(6, 2)
                << setw(12) << appointmentArray[j].appointmentTimeSlot.startTime
                << setw(12) << appointmentArray[j].appointmentTimeSlot.endTime
                << setw(20) << appointmentArray[j].serviceType
                << setw(20) << appointmentArray[j].customerID << "\n";

            indexNumber++;
        }

    }

    //cout << "Enter any key to return to menu.";  change the contents later
    //cin.get();

    // return 0; change function to int, to return to menu.

}

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