#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

const string RESOURCES_FOLDER = "res/";
#pragma region Struct Definitions
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

struct TimeSlot
{
  string appointmentID = "";
  bool booked = false;
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
  TimeSlot timeSlots[31][24];
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
#pragma endregion
#pragma region Struct Data Loading and Printing
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
// TimeSlot Struct Functions
void loadExpertTimeSlots(Appointment* appointmentArray, int appointmentArraySize, ExpertAccount* expertAccountArray, int expertAccountArraySize);

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
#pragma endregion


// Miscellaneous Functions
string serviceSelectionValidation();
int bookingAvailablitySelect();
int findExpertIndexByID(ExpertAccount expertAccountArray[], int expertArraySize);
string convertToAmPm(string& time24);
string convertToAmPm(int hour24);
void eraseEmptyLinesFromFile(const string& fileName);
void showExpertTimeTable(ExpertAccount expertAccountArray[], int expertIndex);

// Customer Functions
string customerLogin(CustomerAccount customerAccountArray[], int customerArraySize);
void customerRegistration(CustomerAccount customerAccountArray[], int customerAccountArraySize);
void viewBeautyCentreInformation();
void viewServicesAndExperts(ExpertAccount expertAccountArray[], int expertAccountArraySize);
void checkAppointmentAvailability(ExpertAccount expertAccountArray[], int expertArraySize);
void viewBooking(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountSize, int customerIndex, CustomerAccount customerAccountArray[]);
void bookAppointment(CustomerAccount customerAccountArray[], ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize, int customerArrayIndex);
void makePayment(Appointment appointmentArray[], int appointmentArraySize, CustomerAccount customerAccountArray[], int customerArrayIndex);


// Admin Functions 
string adminLogin(AdminAccount adminAccountArray[], int adminArraySize);
void viewOverallSchedule(ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize);
void viewIndividualExpertSchedule(ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize);
void viewCustomerList(CustomerAccount customerAccountArray[], int customerAccountArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize);
void generateSalesReport(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize);
void viewExpertBonusEntitlement(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize);

// Expert Functions
string expertLogin(ExpertAccount expertAccountArray[], int expertArraySize);
void viewIndividualSchedule(ExpertAccount expertAccountArray[], Appointment appointmentArray[], int appointmentArraySize, int expertIndex);
void viewAssignedCustomerList(CustomerAccount customerAccountArray[], int customerAccountArraySize, Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertIndex);
void viewEarningsBonusEntitlement(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize, int expertIDIndex);

// Menu functions
void displayMainMenu();
void customerMenu(CustomerAccount customerAccountArray[], int customerAccountArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize);
void adminMenu(AdminAccount adminAccountArray[], int adminAccountArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize, CustomerAccount customerAccountArray[], int customerAccountArraySize);
void expertMenu(ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize, CustomerAccount customerAccountArray[], int customerAccountArraySize);

int main()
{
  // Clear Empty Lines in Files
  eraseEmptyLinesFromFile(RESOURCES_FOLDER + "AccountCustomer.txt");
  eraseEmptyLinesFromFile(RESOURCES_FOLDER + "AccountExpert.txt");
  eraseEmptyLinesFromFile(RESOURCES_FOLDER + "AccountAdmin.txt");
  eraseEmptyLinesFromFile(RESOURCES_FOLDER + "Appointment.txt");
  eraseEmptyLinesFromFile(RESOURCES_FOLDER + "feedback.txt");

  // Array Size Declaration
  const int customerAccountArraySize = 50;
  const int expertAccountArraySize = 10;
  const int adminAccountArraySize = 1;
  const int appointmentArraySize = 200;
  const int feedbackArraySize = 200;

  // Array Declaration
  CustomerAccount customerAccountArray[customerAccountArraySize];
  ExpertAccount expertAccountArray[expertAccountArraySize];
  AdminAccount adminAccountArray[adminAccountArraySize];
  Appointment appointmentArray[appointmentArraySize];
  Feedback feedbackArray[feedbackArraySize];

  // Load File Data to Array
  loadToCustomerAccountStruct(customerAccountArray, customerAccountArraySize);
  loadToExpertAccountStruct(expertAccountArray, expertAccountArraySize);
  loadToAdminAccountStruct(adminAccountArray, adminAccountArraySize);
  loadToAppointmentStruct(appointmentArray, appointmentArraySize);
  loadToFeedbackStruct(feedbackArray, feedbackArraySize);
  loadExpertTimeSlots(appointmentArray, appointmentArraySize, expertAccountArray, expertAccountArraySize);

  // Display welcome message
  cout << "==================================\n";
  cout << "  SERENITY WELLNESS CENTER\n";
  cout << "  Massage & Therapy Booking System\n";
  cout << "==================================\n\n";

  // Main program loop
  int choice;
  do {
    displayMainMenu();
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      customerMenu(customerAccountArray, customerAccountArraySize,
        expertAccountArray, expertAccountArraySize,
        appointmentArray, appointmentArraySize);
      break;
    case 2:
      expertMenu(expertAccountArray, expertAccountArraySize,
        appointmentArray, appointmentArraySize,
        customerAccountArray, customerAccountArraySize);
      break;
    case 3:
      adminMenu(adminAccountArray, adminAccountArraySize,
        expertAccountArray, expertAccountArraySize,
        appointmentArray, appointmentArraySize,
        customerAccountArray, customerAccountArraySize);
      break;
    case 4:
      cout << "Thank you for using Serenity Wellness Center System!\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 4);

  return 0;
}
// Menu Functions
void displayMainMenu() {
  cout << "\n===== MAIN MENU =====\n";
  cout << "1. Customer Menu\n";
  cout << "2. Expert Menu\n";
  cout << "3. Admin Menu\n";
  cout << "4. Exit\n";
  cout << "=====================\n";
}

void customerMenu(CustomerAccount customerAccountArray[], int customerAccountArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize) {

  int customerIndex = -1;
  string customerID;
  int choice;

  cout << "\n===== CUSTOMER MENU =====\n";
  cout << "1. Login\n";
  cout << "2. Register\n";
  cout << "3. Back to Main Menu\n";
  cout << "Enter your choice: ";
  cin >> choice;

  if (choice == 1) {
    customerID = customerLogin(customerAccountArray, customerAccountArraySize);
    if (customerID == "") return;

    // Find customer index
    for (int i = 0; i < customerAccountArraySize; i++) {
      if (customerAccountArray[i].customerID == customerID) {
        customerIndex = i;
        break;
      }
    }
  }
  else if (choice == 2) {
    customerRegistration(customerAccountArray, customerAccountArraySize);
    return;
  }
  else if (choice == 3) {
    return;
  }
  else {
    cout << "Invalid choice.\n";
    return;
  }

  // Customer submenu
  int customerChoice;
  do {
    cout << "\n===== CUSTOMER DASHBOARD =====\n";
    cout << "Welcome, " << customerAccountArray[customerIndex].firstName << "!\n";
    cout << "1. View Beauty Centre Information\n";
    cout << "2. View Services and Experts\n";
    cout << "3. Check Appointment Availability\n";
    cout << "4. Book Appointment\n";
    cout << "5. Make Payment\n";
    cout << "6. View My Bookings\n";
    cout << "7. Logout\n";
    cout << "Enter your choice: ";
    cin >> customerChoice;

    switch (customerChoice) {
    case 1:
      viewBeautyCentreInformation();
      break;
    case 2:
      viewServicesAndExperts(expertAccountArray, expertAccountArraySize);
      break;
    case 3:
      checkAppointmentAvailability(expertAccountArray, expertAccountArraySize);
      break;
    case 4:
      bookAppointment(customerAccountArray, expertAccountArray, expertAccountArraySize,
        appointmentArray, appointmentArraySize, customerIndex);
      break;
    case 5:
      makePayment(appointmentArray, appointmentArraySize, customerAccountArray, customerIndex);
      break;
    case 6:
      viewBooking(appointmentArray, appointmentArraySize, expertAccountArray,
        expertAccountArraySize, customerIndex, customerAccountArray);
      break;
    case 7:
      cout << "Logging out...\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (customerChoice != 7);
}

void expertMenu(ExpertAccount expertAccountArray[], int expertAccountArraySize,
  Appointment appointmentArray[], int appointmentArraySize,
  CustomerAccount customerAccountArray[], int customerAccountArraySize) {

  string expertID = expertLogin(expertAccountArray, expertAccountArraySize);
  if (expertID == "") return;

  // Find expert index
  int expertIndex = -1;
  for (int i = 0; i < expertAccountArraySize; i++) {
    if (expertAccountArray[i].expertID == expertID) {
      expertIndex = i;
      break;
    }
  }

  if (expertIndex == -1) {
    cout << "Expert not found.\n";
    return;
  }

  int expertChoice;
  do {
    cout << "\n===== EXPERT MENU =====\n";
    cout << "Welcome, " << expertAccountArray[expertIndex].firstName << "!\n";
    cout << "1. View Individual Schedule\n";
    cout << "2. View Assigned Customer List\n";
    cout << "3. View Earnings Bonus Entitlement\n";
    cout << "4. Logout\n";
    cout << "Enter your choice: ";
    cin >> expertChoice;

    switch (expertChoice) {
    case 1:
      viewIndividualSchedule(expertAccountArray, appointmentArray, appointmentArraySize, expertIndex);
      break;
    case 2:
      viewAssignedCustomerList(customerAccountArray, customerAccountArraySize,
        appointmentArray, appointmentArraySize,
        expertAccountArray, expertIndex);
      break;
    case 3:
      viewEarningsBonusEntitlement(appointmentArray, appointmentArraySize,
        expertAccountArray, expertAccountArraySize,
        expertIndex);
      break;
    case 4:
      cout << "Logging out...\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (expertChoice != 4);
}

void adminMenu(AdminAccount adminAccountArray[], int adminAccountArraySize,
  ExpertAccount expertAccountArray[], int expertAccountArraySize,
  Appointment appointmentArray[], int appointmentArraySize,
  CustomerAccount customerAccountArray[], int customerAccountArraySize) {

  string adminID = adminLogin(adminAccountArray, adminAccountArraySize);
  if (adminID == "") return;

  int adminChoice;
  do {
    cout << "\n===== ADMIN MENU =====\n";
    cout << "1. View Overall Schedule\n";
    cout << "2. View Individual Expert Schedule\n";
    cout << "3. View Customer List\n";
    cout << "4. Generate Sales Report\n";
    cout << "5. View Expert Bonus Entitlement\n";
    cout << "6. Logout\n";
    cout << "Enter your choice: ";
    cin >> adminChoice;

    switch (adminChoice) {
    case 1:
      viewOverallSchedule(expertAccountArray, expertAccountArraySize,
        appointmentArray, appointmentArraySize);
      break;
    case 2:
      viewIndividualExpertSchedule(expertAccountArray, expertAccountArraySize,
        appointmentArray, appointmentArraySize);
      break;
    case 3:
      viewCustomerList(customerAccountArray, customerAccountArraySize,
        expertAccountArray, expertAccountArraySize,
        appointmentArray, appointmentArraySize);
      break;
    case 4:
      generateSalesReport(appointmentArray, appointmentArraySize,
        expertAccountArray, expertAccountArraySize);
      break;
    case 5:
      viewExpertBonusEntitlement(appointmentArray, appointmentArraySize,
        expertAccountArray, expertAccountArraySize);
      break;
    case 6:
      cout << "Logging out...\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (adminChoice != 6);
}

// Customer Functions
string customerLogin(CustomerAccount customerAccountArray[], int customerArraySize) {
  string username, password, customerID;
  cout << "Enter Username: ";
  cin >> username;
  cout << "Enter Password: ";
  cin >> password;
  // Validate credentials
  for (int i = 0; i < customerArraySize; i++) {
    if (customerAccountArray[i].username == username && customerAccountArray[i].password == password) {
      cout << "Login successful. Welcome, " << customerAccountArray[i].firstName << "!\n";
      return customerAccountArray[i].customerID;
    }

  }
  cout << "Login failed. Please try again.\n";
  return "";
}
void customerRegistration(CustomerAccount customerAccountArray[], int customerAccountArraySize) {
  // Find free slot
  int freeIndex = -1;
  for (int i = 0; i < customerAccountArraySize; i++) {
    if (customerAccountArray[i].customerID.empty()) {
      freeIndex = i;
      break;
    }
  }
  if (freeIndex == -1) {
    cout << "No space available for new customer registration.\n";
    return;
  }

  // Input details
  string username, password, firstName, lastName;
  cout << "Enter Username: ";
  cin >> username;

  // Check for duplicate username
  for (int i = 0; i < customerAccountArraySize; i++) {
    if (!customerAccountArray[i].customerID.empty() &&
      customerAccountArray[i].username == username) {
      cout << "Error: Username already exists. Please choose another.\n";
      return;
    }
  }

  cout << "Enter Password: ";
  cin >> password;
  cout << "Enter First Name: ";
  cin >> firstName;
  cout << "Enter Last Name: ";
  cin >> lastName;

  // Generate CustomerID (C001, C002, etc.)
  int newCustNum = 1;
  for (int i = 0; i < customerAccountArraySize; i++) {
    if (!customerAccountArray[i].customerID.empty()) {
      newCustNum++;
    }
  }
  string customerID = "C" + string(3 - to_string(newCustNum).length(), '0') + to_string(newCustNum);

  // Save to memory
  customerAccountArray[freeIndex].customerID = customerID;
  customerAccountArray[freeIndex].username = username;
  customerAccountArray[freeIndex].password = password;
  customerAccountArray[freeIndex].firstName = firstName;
  customerAccountArray[freeIndex].lastName = lastName;

  // Append to file AccountCustomer.txt
  ofstream outFile(RESOURCES_FOLDER + "AccountCustomer.txt", ios::app);
  if (outFile.is_open()) {
    outFile << customerID << ";"
      << "username=" << username << ";"
      << "password=" << password << ";"
      << "firstName=" << firstName << ";"
      << "lastName=" << lastName << ";\n";
    outFile.close();
  }
  else {
    cout << "Error: Could not open AccountCustomer.txt\n";
  }

  cout << "Registration successful! Your Customer ID is: " << customerID << endl;
}

void viewBeautyCentreInformation() {
  cout << "==================================\n\n";
  cout << "Serenity Massage & Wellness Centre\n\n";
  cout << "==================================\n\n\n";


  cout << "VISION:\n";
  cout << " To be the region's most trusted sanctuary for holistic relaxation and recovery.\n\n";


  cout << "MISSION:\n";
  cout << " 1. Provide safe, professional massage and wellness therapies.\n";
  cout << " 2. Promote physical and mental wellbeing through personalised care.\n";
  cout << " 3. Educate clients on self-care and sustainable healthy habits.\n";
  cout << "------------------------------------------------------------\n\n";


  cout << "OPERATING HOURS:\n";
  cout << " Mon - Fri: 9AM - 5PM\n";


  cout << "CONTACT:\n";
  cout << " Phone: +60 12-345 6789\n";
  cout << " Email: hello@serenitywellness.my\n";
  cout << " Address: 12 Jalan Genting, Kuala Lumpur, Malaysia\n\n";

  cout << "Available Services:\n";
  cout << " Massage Therapy\n";
  cout << " Aromatherapy\n";
  cout << " Reflexology\n";
  cout << "------------------------------------------------------------\n\n";
};
void viewServicesAndExperts(ExpertAccount expertAccountArray[], int expertAccountArraySize) {

  string selectedService = serviceSelectionValidation();

  cout << "\nExperts for " << selectedService << ":\n";
  cout << "-------------------------------------------------\n";

  bool found = false;
  for (int i = 0; i < expertAccountArraySize; i++)
  {
    if (expertAccountArray[i].specialization == selectedService)
    {
      cout << "ExpertID: "
        << expertAccountArray[i].expertID << '\n';
      cout << "Name: "
        << expertAccountArray[i].firstName << " "
        << expertAccountArray[i].lastName << "\n";
      cout << "Specialization: "
        << expertAccountArray[i].specialization << "\n";
      cout << "Availability: "
        << expertAccountArray[i].workingHours.day << " ("
        << convertToAmPm(expertAccountArray[i].workingHours.startTime) << " - "
        << convertToAmPm(expertAccountArray[i].workingHours.endTime) << ")\n";
      cout << "-------------------------------------------------\n";
      found = true;
    }
  }

  if (!found) {
    cout << "No experts available for this service.\n";
  }
}
void checkAppointmentAvailability(ExpertAccount expertAccountArray[], int expertArraySize) {

  int expertIDIndex = findExpertIndexByID(expertAccountArray, expertArraySize);
  if (expertIDIndex == -1)
  {
    return;
  }


  cout << "Select the week of the month to view appointment slot availability (1 - 5): ";
  int weekInput = 0, weekStartDay = 0, weekEndDay = 0;
  cin >> weekInput;

  while (weekInput > 5 || weekInput < 1) {
    cout << "\nError! Please enter a valid week. (1 - 5)\n";
    cout << "Select the week of the month to view appointment slot availability (1 - 5): ";
    cin >> weekInput;
  }

  // Set the week range
  switch (weekInput) {
  case 1: weekStartDay = 1; weekEndDay = 6; break;
  case 2: weekStartDay = 7; weekEndDay = 13; break;
  case 3: weekStartDay = 14; weekEndDay = 20; break;
  case 4: weekStartDay = 21; weekEndDay = 27; break;
  case 5: weekStartDay = 28; weekEndDay = 31; break;
  }

  // Display week days
  cout << "\nWeek " << weekInput << ":\n";
  string daysOfWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

  for (int i = 0; i < 7; i++) {
    int currentDay = weekStartDay + i;
    if (currentDay <= weekEndDay) {
      cout << i + 1 << ". " << daysOfWeek[i] << " (Dec " << currentDay << ")\n";
    }
  }

  // Get day selection
  cout << "\nSelect a day of week (1-7): ";
  int daySelection = 0;
  cin >> daySelection;

  while (daySelection < 1 || daySelection > 7) {
    cout << "\nError! Please enter a valid day (1-7): ";
    cin >> daySelection;
  }

  int selectedDay = weekStartDay + daySelection - 1;
  if (selectedDay > weekEndDay) {
    cout << "\nError! Selected day is not in week " << weekInput << ".\n";
    return;
  }

  // Display time slots for selected day

  int intStartTime = stoi(expertAccountArray[expertIDIndex].workingHours.startTime.substr(0, 2));
  int intEndTime = stoi(expertAccountArray[expertIDIndex].workingHours.endTime.substr(0, 2));

  cout << "\nWeek " << weekInput << " " << daysOfWeek[daySelection - 1] << " (Dec " << selectedDay << "):\n";
  cout << "Working Hours: " << convertToAmPm(intStartTime) << " to " << convertToAmPm(intEndTime) << endl;
  cout << "\nTime Slots\n";
  cout << "--------------------------------\n";

  int counter = 1;
  for (int i = 0; i < 24; i++)
  {
    if (i < intStartTime || i >= intEndTime)
    {
      continue;
    }
    else
    {
      cout << left << setw(2) << counter << "| "
        << right << setw(8) << convertToAmPm(i)
        << " - "
        << right << setw(8) << convertToAmPm(i + 1);

      if (expertAccountArray[expertIDIndex].timeSlots[selectedDay - 1][i].booked == true)
      {
        cout << setw(5) << "  [X]" << endl;
      }
      else
      {
        cout << setw(5) << "  [ ]" << endl;
      }
      counter++;
    }
  }

}
void bookAppointment(CustomerAccount customerAccountArray[], ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize, int customerArrayIndex) {
  viewServicesAndExperts(expertAccountArray, expertAccountArraySize); // Placeholder

  // Get expert selection
  int expertIDIndex = findExpertIndexByID(expertAccountArray, expertAccountArraySize);
  if (expertIDIndex == -1) {
    cout << "Invalid expert selection.\n";
    return;
  }

  // Get service type
  cout << "Service Type:\n";
  cout << "1. Treatment (3 Hours)\n";
  cout << "2. Consultation (1 Hour)\n";
  cout << "Enter service type: ";
  int serviceChoice = 0;
  if (!(cin >> serviceChoice) || (serviceChoice < 1 || serviceChoice > 2)) {
    cout << "Invalid input, exiting...\n";
    return;
  }

  string serviceType;
  int serviceTypeHours = 0;
  double subtotal = 0.0;
  if (serviceChoice == 1) {
    serviceType = "Treatment";
    serviceTypeHours = 3;
    subtotal = 500.0;   // example base price
  }
  else {
    serviceType = "Consultation";
    serviceTypeHours = 1;
    subtotal = 85.50;   // example base price
  }

  // Show expert schedule
  showExpertTimeTable(expertAccountArray, expertIDIndex);

  // Get day and time
  int dayInt = 0, timeInt = 0;
  cout << "Enter day (1-31): ";
  if (!(cin >> dayInt) || dayInt < 1 || dayInt > 31) {
    cout << "Invalid day. Returning...\n";
    return;
  }
  cout << "Enter start hour within 9AM to 5PM (9-17): ";
  if (!(cin >> timeInt) || timeInt < 9 || timeInt > 17) {
    cout << "Invalid time. Returning...\n";
    return;
  }
  if (timeInt + serviceTypeHours > 17) {
    cout << "Service does not fit within working hours. Returning...\n";
    return;
  }

  // Check availability
  int totalHoursWorkedDay = 0;
  for (int i = 0; i < 24; i++) {
    if (expertAccountArray[expertIDIndex].timeSlots[dayInt - 1][i].booked) {
      totalHoursWorkedDay++;
    }
  }

  int startDay, endDay;
  if (dayInt <= 7) { startDay = 1; endDay = 7; }
  else if (dayInt <= 14) { startDay = 8; endDay = 14; }
  else if (dayInt <= 21) { startDay = 15; endDay = 21; }
  else if (dayInt <= 28) { startDay = 22; endDay = 28; }
  else { startDay = 29; endDay = 31; }

  int totalHoursWorkedWeek = 0;
  for (int i = startDay - 1; i < endDay; i++) {
    for (int j = 0; j < 24; j++) {
      if (expertAccountArray[expertIDIndex].timeSlots[i][j].booked) {
        totalHoursWorkedWeek++;
      }
    }
  }

  for (int k = 0; k < serviceTypeHours; k++) {
    int hourIndex = timeInt + k;
    if (expertAccountArray[expertIDIndex].timeSlots[dayInt - 1][hourIndex].booked) {
      cout << "Time slots are already booked.\n";
      return;
    }
  }

  if ((totalHoursWorkedDay + serviceTypeHours) > 6) {
    cout << "Expert schedule is already full for the selected day.\n";
    return;
  }

  // Mark booked slots
  for (int k = 0; k < serviceTypeHours; k++) {
    expertAccountArray[expertIDIndex].timeSlots[dayInt - 1][timeInt + k].booked = true;
  }

  // Calculate payment
  double serviceFee = subtotal * 0.10;
  double totalPaid = subtotal + serviceFee;

  // Generate Appointment ID (find next available)
  int newApptNum = 1;
  for (int i = 0; i < appointmentArraySize; i++) {
    if (!appointmentArray[i].appointmentID.empty()) newApptNum++;
  }
  string appointmentID = "AP" + string(3 - to_string(newApptNum).length(), '0') + to_string(newApptNum);

  // Pick a free slot in memory
  int freeIndex = -1;
  for (int i = 0; i < appointmentArraySize; i++) {
    if (appointmentArray[i].appointmentID.empty()) {
      freeIndex = i;
      break;
    }
  }
  if (freeIndex == -1) {
    cout << "No space left in appointment array.\n";
    return;
  }

  // Fill appointment struct
  Appointment& appt = appointmentArray[freeIndex];
  appt.appointmentID = appointmentID;
  appt.customerID = customerAccountArray[customerArrayIndex].customerID;
  appt.expertID = expertAccountArray[expertIDIndex].expertID;
  appt.serviceType = serviceType;
  appt.appointmentTimeSlot.startTime = (timeInt < 10 ? "0" : "") + to_string(timeInt) + "00";
  appt.appointmentTimeSlot.endTime = ((timeInt + serviceTypeHours) < 10 ? "0" : "") + to_string(timeInt + serviceTypeHours) + "00";
  appt.appointmentDate = "202512" + ((dayInt < 10 ? "0" : "") + to_string(dayInt));
  appt.totalPaid = totalPaid;
  appt.serviceFee = serviceFee;
  appt.paymentStatus = false;

  // Reset Expert Time Slots 
  loadExpertTimeSlots(appointmentArray, appointmentArraySize, expertAccountArray, expertAccountArraySize);

  // Append to file
  ofstream outFile(RESOURCES_FOLDER + "Appointment.txt", ios::app);
  if (outFile.is_open()) {
    outFile << appt.appointmentID << ";"
      << appt.customerID << ";"
      << appt.expertID
      << ";serviceType=" << appt.serviceType
      << ";appointmentStartTime=" << appt.appointmentTimeSlot.startTime
      << ";appointmentEndTime=" << appt.appointmentTimeSlot.endTime
      << ";appointmentDate=" << appt.appointmentDate
      << ";totalPaid=" << fixed << setprecision(2) << appt.totalPaid
      << ";serviceFee=" << appt.serviceFee
      << ";paymentStatus=0;\n";
    outFile.close();
  }

  cout << "Booking successful for " << serviceType << " on Dec "
    << (dayInt < 10 ? "0" : "") << dayInt
    << " starting at " << timeInt << ":00\n";
}
void makePayment(Appointment appointmentArray[], int appointmentArraySize, CustomerAccount customerAccountArray[], int customerArrayIndex)
{
  int unpaidCount = 0;

  cout << "\n--- Unpaid Appointments for "
    << customerAccountArray[customerArrayIndex].firstName << " "
    << customerAccountArray[customerArrayIndex].lastName << " ---\n";

  for (int i = 0; i < appointmentArraySize; i++) {
    if (appointmentArray[i].appointmentID != ""
      && !appointmentArray[i].paymentStatus
      && appointmentArray[i].customerID == customerAccountArray[customerArrayIndex].customerID) {
      unpaidCount++;
      cout << unpaidCount << ". "
        << appointmentArray[i].appointmentID
        << " | Expert: " << appointmentArray[i].expertID
        << " | Service: " << appointmentArray[i].serviceType
        << " | Date: " << appointmentArray[i].appointmentDate
        << " | Total: RM " << fixed << setprecision(2) << appointmentArray[i].totalPaid
        << endl;
    }
  }

  if (unpaidCount == 0) {
    cout << "No unpaid appointments found.\n";
    return;
  }

  int choice;
  cout << "\nSelect an appointment to pay (1-" << unpaidCount << "): ";
  cin >> choice;

  if (choice < 1 || choice > unpaidCount) {
    cout << "Invalid selection.\n";
    return;
  }

  // Find the chosen unpaid appointment
  int selectedIndex = -1;
  int currentCount = 0;
  for (int i = 0; i < appointmentArraySize; i++) {
    if (appointmentArray[i].appointmentID != ""
      && !appointmentArray[i].paymentStatus
      && appointmentArray[i].customerID == customerAccountArray[customerArrayIndex].customerID) {
      currentCount++;
      if (currentCount == choice) {
        selectedIndex = i;
        break;
      }
    }
  }

  if (selectedIndex == -1) {
    cout << "Error selecting appointment.\n";
    return;
  }

  // Prompt user for payment detail
  cout << "Payment Methods:\n";
  cout << "1. Credit/Debit Card\n";
  cout << "2. T&G E-Wallet\n";
  cout << "3. Online Banking\n";
  string paymentMethod;
  cout << "Enter payment method: ";
  cin >> paymentMethod;

  cout << "\nProcessing payment...\n";

  // Mark as paid in memory
  appointmentArray[selectedIndex].paymentStatus = true;

  // Rewrite Appointment.txt with updated statuses
  ofstream outFile(RESOURCES_FOLDER + "Appointment.txt", ios::trunc);
  if (outFile.is_open()) {
    for (int i = 0; i < appointmentArraySize; i++) {
      if (appointmentArray[i].appointmentID.empty()) continue;

      outFile << appointmentArray[i].appointmentID << ";"
        << appointmentArray[i].customerID << ";"
        << appointmentArray[i].expertID
        << ";serviceType=" << appointmentArray[i].serviceType
        << ";appointmentStartTime=" << appointmentArray[i].appointmentTimeSlot.startTime
        << ";appointmentEndTime=" << appointmentArray[i].appointmentTimeSlot.endTime
        << ";appointmentDate=" << appointmentArray[i].appointmentDate
        << ";totalPaid=" << fixed << setprecision(2) << appointmentArray[i].totalPaid
        << ";serviceFee=" << appointmentArray[i].serviceFee
        << ";paymentStatus=" << (appointmentArray[i].paymentStatus ? 1 : 0) << ";\n";
    }
    outFile.close();
  }
  else {
    cout << "Error: Could not open Appointment.txt for writing.\n";
  }

  cout << "Payment successful for appointment "
    << appointmentArray[selectedIndex].appointmentID << "!\n";
}
void viewBooking(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountSize, int customerIndex, CustomerAccount customerAccountArray[])
{
  string customerID = customerAccountArray[customerIndex].customerID;
  int indexNumber = 1;
  bool hasBookings = false;


  for (int i = 0; i < appointmentArraySize; i++)
  {
    if (appointmentArray[i].appointmentID.empty()) {
      continue;
    }

    // Check if appointment = logged in customer
    if (appointmentArray[i].customerID == customerID)
    {
      hasBookings = true;

      // For expert name
      string expertName = "Unknown";
      for (int j = 0; j < expertAccountSize; j++)
      {
        if (expertAccountArray[j].expertID == appointmentArray[i].expertID)
        {
          expertName = expertAccountArray[j].firstName;
          break;
        }
      }

      // Format date (Dec 12)
      string dateStr = appointmentArray[i].appointmentDate;
      string formattedDate = "Dec " + dateStr.substr(6, 2);

      // Format time (1000-1200)
      string startTime = convertToAmPm(appointmentArray[i].appointmentTimeSlot.startTime);
      string endTime = convertToAmPm(appointmentArray[i].appointmentTimeSlot.endTime);
      string formattedTime = startTime + "-" + endTime;

      // Format payment status
      string status = appointmentArray[i].paymentStatus ? "Paid" : "Pending";


      cout << "\n\nYour Booked Appointments:\n";
      cout << "====================================================================================\n";
      cout << left << setw(4) << "No."
        << '|' << setw(15) << "Service"
        << '|' << setw(10) << "Expert"
        << '|' << setw(12) << "Date"
        << '|' << setw(18) << "Time"
        << '|' << setw(12) << "Amount"
        << '|' << setw(6) << "Status" << '|' << "\n";
      cout << "------------------------------------------------------------------------------------\n";

      cout << left << setw(4) << indexNumber++
        << '|' << setw(15) << (appointmentArray[i].serviceType.length() > 14 ? appointmentArray[i].serviceType.substr(0, 12) + ".." : appointmentArray[i].serviceType)
        << '|' << setw(10) << (expertName.length() > 9 ? expertName.substr(0, 8) + ".." : expertName)
        << '|' << setw(12) << formattedDate
        << '|' << setw(18) << formattedTime
        << '|' << "RM" << setw(10) << fixed << setprecision(2) << appointmentArray[i].totalPaid
        << '|' << setw(6) << status << '|' << "\n";
    }
  }

  if (!hasBookings)
  {
    cout << "No bookings found for your account.\n";
  }

  cout << "------------------------------------------------------------------------------------\n";


}

// Admin Functions
string adminLogin(AdminAccount adminAccountArray[], int adminArraySize) {
  string username, password, adminID;
  cout << "Enter Username: ";
  cin >> username;
  cout << "Enter Password: ";
  cin >> password;
  // Validate credentials
  for (int i = 0; i < adminArraySize; i++) {
    if (adminAccountArray[i].username == username && adminAccountArray[i].password == password) {
      cout << "Login successful. Welcome, " << adminAccountArray[i].firstName << "!\n";
      return adminAccountArray[i].adminID;
    }

  }
  cout << "Login failed. Please try again.\n";
  return "";
}
void viewOverallSchedule(ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize)
{
  cout << "Overall Schedule for December\n";

  for (int expertIndex = 0; expertIndex < expertAccountArraySize; expertIndex++)
  {
    showExpertTimeTable(expertAccountArray, expertIndex);
  }

  cout << "[X] = Booked, [ ] = Available\n\n";

  // Loop through all appointments to find booked slots
  cout << "Booked Appointments:\n";
  cout << "==================================================================\n";
  cout << left << setw(4) << "No."
    << '|' << setw(15) << "Service"
    << '|' << setw(10) << "Expert"
    << '|' << setw(12) << "Date"
    << '|' << setw(20) << "Time" << '|' << "\n";
  cout << "------------------------------------------------------------------\n";
  int indexNumber = 1;
  for (int i = 0; i < appointmentArraySize; i++)
  {
    if (appointmentArray[i].appointmentID.empty()) {
      continue; // Skip empty appointments
    }
    // Find expert details
    string expertName = "Unknown";
    for (int j = 0; j < expertAccountArraySize; j++)
    {
      if (expertAccountArray[j].expertID == appointmentArray[i].expertID)
      {
        expertName = expertAccountArray[j].firstName;
        break;
      }
    }
    // Format date (Dec 12)
    string dateStr = appointmentArray[i].appointmentDate;
    string formattedDate = "Dec " + dateStr.substr(6, 2);
    // Format time (1000-1200)
    string startTime = convertToAmPm(appointmentArray[i].appointmentTimeSlot.startTime);
    string endTime = convertToAmPm(appointmentArray[i].appointmentTimeSlot.endTime);
    string formattedTime = startTime + " to " + endTime;
    // Format payment status
    string status = appointmentArray[i].paymentStatus ? "Paid" : "Unpaid";
    cout << left << setw(4) << indexNumber++
      << '|' << setw(15) << (appointmentArray[i].serviceType.length() > 14 ? appointmentArray[i].serviceType.substr(0, 12) + ".." : appointmentArray[i].serviceType)
      << '|' << setw(10) << (expertName.length() > 9 ? expertName.substr(0, 8) + ".." : expertName)
      << '|' << setw(12) << formattedDate
      << '|' << setw(20) << formattedTime
      << '|' << "\n";
  }
}
void viewCustomerList(CustomerAccount customerAccountArray[], int customerAccountArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize)
{
  cout << "=========== Customer List ===========" << endl;

  // Display customer IDs with names
  for (int i = 0; i < customerAccountArraySize; i++) {
    if (!customerAccountArray[i].customerID.empty()) {
      cout << customerAccountArray[i].customerID << " - "
        << customerAccountArray[i].firstName << " "
        << customerAccountArray[i].lastName << endl;
    }
  }

  cout << "\nEnter Customer ID to view details: ";
  string inputID;
  cin >> inputID;
  if (!inputID.empty() && isalpha(inputID[0])) {
    inputID[0] = static_cast<char>(toupper(inputID[0]));
  }
  else {
    cout << "Customer ID cannot be empty." << endl;
    return;
  }

  // Find customer
  int selectedIndex = -1;
  for (int i = 0; i < customerAccountArraySize; i++) {
    if (customerAccountArray[i].customerID == inputID) {
      selectedIndex = i;
      break;
    }
  }

  if (selectedIndex == -1) {
    cout << "Customer ID not found." << endl;
    return;
  }

  CustomerAccount selectedCustomer = customerAccountArray[selectedIndex];

  cout << "\n=========== Customer Details ===========" << endl;
  cout << "Customer ID\t: " << selectedCustomer.customerID << endl;
  cout << "Full Name\t: " << selectedCustomer.firstName << " "
    << selectedCustomer.lastName << "\n\n";

  bool hasAppointment = false;

  // Show appointments for this customer
  for (int j = 0; j < appointmentArraySize; j++)
  {
    if (appointmentArray[j].appointmentID.empty()) continue;

    if (appointmentArray[j].customerID == selectedCustomer.customerID) {
      hasAppointment = true;

      // Find expert info
      string expertName = "";
      string specialization = "";
      for (int k = 0; k < expertAccountArraySize; k++) {
        if (expertAccountArray[k].expertID == appointmentArray[j].expertID) {
          expertName = expertAccountArray[k].firstName + " " + expertAccountArray[k].lastName;
          specialization = expertAccountArray[k].specialization;
          break;
        }
      }

      cout << "Appointment ID\t: " << appointmentArray[j].appointmentID << endl;
      cout << "Service Type\t: " << appointmentArray[j].serviceType << endl;
      cout << "Date\t\t: " << appointmentArray[j].appointmentDate << endl;
      cout << "Time\t\t: " << convertToAmPm(appointmentArray[j].appointmentTimeSlot.startTime)
        << " - " << convertToAmPm(appointmentArray[j].appointmentTimeSlot.endTime) << endl;
      cout << "Expert\t\t: " << expertName << " (" << specialization << ")" << endl;
      cout << "Total Paid\t: RM" << appointmentArray[j].totalPaid << endl;
      cout << "Service Fee\t: RM" << appointmentArray[j].serviceFee << endl;
      cout << "Payment Status\t: " << (appointmentArray[j].paymentStatus ? "Paid" : "Pending") << endl;
      cout << "-----------------------------------------" << endl;
    }
  }

  if (!hasAppointment) {
    cout << "\nNo appointments found for this customer." << endl;
  }

}
void generateSalesReport(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize)
{
  int menuChoice;
  cout << "\n--- Sales Report Menu (December 2025 only) ---\n";
  cout << "1. Report by Day Range\n";
  cout << "2. Report by Service Category\n";
  cout << "3. Report by Expert\n";
  cout << "Enter your choice (1-3): ";
  cin >> menuChoice;

  int startDay = 1, endDay = 31;
  string category, expertID;

  switch (menuChoice) {
  case 1: {
    cout << "Enter start day (1-31): ";
    cin >> startDay;
    if (startDay < 1) startDay = 1;
    if (startDay > 31) startDay = 31;

    cout << "Enter end day (1-31): ";
    cin >> endDay;
    while (endDay < startDay || endDay > 31 || endDay < 1) {
      cout << "Invalid end day. It must be between " << startDay << " and 31.\n";
      cout << "Re-enter end day: ";
      cin >> endDay;
    }
    break;
  }

  case 2: {
    int serviceChoice;
    cout << "\n--- Select Service Category ---\n";
    cout << "1. Consultation\n";
    cout << "2. Treatment\n";
    cout << "Enter your choice (1-2): ";
    cin >> serviceChoice;

    switch (serviceChoice) {
    case 1: category = "Consultation"; break;
    case 2: category = "Treatment"; break;
    default:
      cout << "Invalid service category choice.\n";
      return;
    }
    break;
  }

  case 3: {
    cout << "\n--- Expert List ---\n";
    for (int i = 0; i < expertAccountArraySize; i++) {
      if (expertAccountArray[i].expertID != "") {
        cout << expertAccountArray[i].expertID << " | "
          << expertAccountArray[i].firstName << " " << expertAccountArray[i].lastName
          << " | Specialization: " << expertAccountArray[i].specialization << endl;
      }
    }
    cout << "Enter expert ID: ";
    cin >> expertID;

    if (!expertID.empty()) {
      expertID[0] = static_cast<char>(toupper(expertID[0]));
    }
    else {
      cout << "ExpertID cannot be empty.\n";
      return;
    }
    break;
  }

  default:
    cout << "Invalid menu choice.\n";
    return;
  }

  // Totals
  double subtotalConsultation = 0, feeConsultation = 0, paidConsultation = 0;
  double subtotalTreatment = 0, feeTreatment = 0, paidTreatment = 0;
  int consultationCount = 0, treatmentCount = 0;

  for (int i = 0; i < appointmentArraySize; i++) {
    if (appointmentArray[i].appointmentID == "" || !appointmentArray[i].paymentStatus) {
      continue;
    }

    int day = -1;
    if (appointmentArray[i].appointmentDate.length() == 8) {
      day = stoi(appointmentArray[i].appointmentDate.substr(6, 2));
    }
    if (day < 1 || day > 31) continue; // only Dec 2025

    bool match = true;
    switch (menuChoice) {
    case 1:
      if (day < startDay || day > endDay) match = false;
      break;
    case 2:
      if (appointmentArray[i].serviceType != category) match = false;
      break;
    case 3:
      if (appointmentArray[i].expertID != expertID) match = false;
      break;
    }

    if (match) {
      double subtotal = appointmentArray[i].totalPaid - appointmentArray[i].serviceFee;
      double fee = appointmentArray[i].serviceFee;
      double paid = appointmentArray[i].totalPaid;

      if (appointmentArray[i].serviceType == "Consultation") {
        subtotalConsultation += subtotal;
        feeConsultation += fee;
        paidConsultation += paid;
        consultationCount++;
      }
      else if (appointmentArray[i].serviceType == "Treatment") {
        subtotalTreatment += subtotal;
        feeTreatment += fee;
        paidTreatment += paid;
        treatmentCount++;
      }
    }
  }

  cout << fixed << setprecision(2);
  cout << "\n--- Sales Report (December 2025) ---\n";
  cout << left << setw(15) << "Service Type"
    << setw(8) << "Bookings"
    << right << setw(18) << "Subtotal(RM)"
    << setw(18) << "Service Fee(RM)"
    << setw(18) << "Total Paid(RM)\n";
  cout << "-------------------------------------------------------------------------------\n";

  cout << left << setw(15) << "Consultation"
    << setw(8) << consultationCount
    << right << setw(18) << subtotalConsultation
    << setw(18) << feeConsultation
    << setw(18) << paidConsultation << endl;

  cout << left << setw(15) << "Treatment"
    << setw(8) << treatmentCount
    << right << setw(18) << subtotalTreatment
    << setw(18) << feeTreatment
    << setw(18) << paidTreatment << endl;

  cout << "-------------------------------------------------------------------------------\n";

  cout << left << setw(15) << "TOTAL"
    << setw(8) << consultationCount + treatmentCount
    << right << setw(18) << subtotalConsultation + subtotalTreatment
    << setw(18) << feeConsultation + feeTreatment
    << setw(18) << paidConsultation + paidTreatment << endl;
}
void viewIndividualExpertSchedule(ExpertAccount expertAccountArray[], int expertAccountArraySize, Appointment appointmentArray[], int appointmentArraySize)
{
  cout << "\n--- Expert List ---\n";
  for (int i = 0; i < expertAccountArraySize; i++) {
    if (!expertAccountArray[i].expertID.empty()) {
      cout << expertAccountArray[i].expertID << " | "
        << expertAccountArray[i].firstName << " " << expertAccountArray[i].lastName
        << " | Specialization: " << expertAccountArray[i].specialization << endl;
    }
  }

  string selectedExpertID;
  cout << "Enter Expert ID to view schedule: ";
  cin >> selectedExpertID;

  if (!selectedExpertID.empty()) {
    selectedExpertID[0] = static_cast<char>(toupper(selectedExpertID[0]));
  }
  else {
    cout << "ExpertID cannot be empty.\n";
    return;
  }

  // find expert
  int expertIndex = -1;
  for (int i = 0; i < expertAccountArraySize; i++) {
    if (expertAccountArray[i].expertID == selectedExpertID) {
      expertIndex = i;
      break;
    }
  }

  if (expertIndex == -1) {
    cout << "Expert not found.\n";
    return;
  }

  ExpertAccount expert = expertAccountArray[expertIndex];

  cout << "\n====================================================\n";
  cout << "   Expert Schedule Report - December 2025\n";
  cout << "====================================================\n";
  cout << "Expert: " << expert.firstName << " " << expert.lastName
    << " (" << expert.expertID << ")\n";
  cout << "Specialization: " << expert.specialization << "\n";
  cout << "Regular Working Hours: " << expert.workingHours.day
    << " | " << expert.workingHours.startTime << " - " << expert.workingHours.endTime << "\n";
  cout << "====================================================\n";

  int week = 1;
  for (int startDay = 1; startDay <= 31; startDay += 7) {
    int endDay = (startDay + 6 > 31) ? 31 : startDay + 6;

    int weeklySessions = 0;
    double weeklyHours = 0.0;

    cout << "\n********** Week " << week << " (Days " << startDay << "-" << endDay << ") **********\n";

    for (int day = startDay; day <= endDay; day++) {
      bool hasAppointments = false;

      // First pass: check if this day has appointments
      for (int j = 0; j < appointmentArraySize; j++) {
        if (appointmentArray[j].appointmentID.empty() || !appointmentArray[j].paymentStatus) continue;
        if (appointmentArray[j].expertID != selectedExpertID) continue;

        if (appointmentArray[j].appointmentDate.length() == 8) {
          int apptDay = stoi(appointmentArray[j].appointmentDate.substr(6, 2));
          if (apptDay == day) {
            hasAppointments = true;
            break;
          }
        }
      }

      if (!hasAppointments) continue; // skip this day entirely

      // Print header only if there are appointments
      cout << "\nDay " << day << ":\n";
      cout << left
        << setw(15) << "AppointmentID"
        << setw(15) << "Service"
        << setw(20) << "Time"
        << setw(15) << "Customer"
        << setw(10) << "Hours" << "\n";
      cout << string(75, '-') << "\n";

      // Second pass: print appointments for this day
      for (int j = 0; j < appointmentArraySize; j++) {
        if (appointmentArray[j].appointmentID.empty() || !appointmentArray[j].paymentStatus) continue;
        if (appointmentArray[j].expertID != selectedExpertID) continue;

        if (appointmentArray[j].appointmentDate.length() == 8) {
          int apptDay = stoi(appointmentArray[j].appointmentDate.substr(6, 2));
          if (apptDay == day) {
            int startTime = stoi(appointmentArray[j].appointmentTimeSlot.startTime);
            int endTime = stoi(appointmentArray[j].appointmentTimeSlot.endTime);
            int duration = static_cast<int>((endTime - startTime) / 100.0);

            weeklySessions++;
            weeklyHours += duration;

            cout << left
              << setw(15) << appointmentArray[j].appointmentID
              << setw(15) << appointmentArray[j].serviceType
              << setw(20) << (convertToAmPm(appointmentArray[j].appointmentTimeSlot.startTime) +
                string("-") + convertToAmPm(appointmentArray[j].appointmentTimeSlot.endTime))
              << setw(15) << appointmentArray[j].customerID
              << setw(10) << duration << "\n";
          }
        }
      }
    }

    cout << "\n==== Week " << week << " Summary ============================================================\n";
    cout << "Total Sessions: " << weeklySessions << "\n";
    cout << "Total Hours Worked: " << weeklyHours << " hrs\n";
    week++;
  }
}
void viewExpertBonusEntitlement(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize)
{
  for (int expertArrayIndex = 0; expertArrayIndex < expertAccountArraySize; expertArrayIndex++)
  {
    viewEarningsBonusEntitlement(appointmentArray, appointmentArraySize, expertAccountArray, expertAccountArraySize, expertArrayIndex);
  }
}

// Expert Functions
string expertLogin(ExpertAccount expertAccountArray[], int expertArraySize) {
  string username, password, expertID;
  cout << "Enter Username: ";
  cin >> username;
  cout << "Enter Password: ";
  cin >> password;
  // Validate credentials
  for (int i = 0; i < expertArraySize; i++) {
    if (expertAccountArray[i].username == username && expertAccountArray[i].password == password) {
      cout << "Login successful. Welcome, " << expertAccountArray[i].firstName << "!\n";
      return expertAccountArray[i].expertID;
    }

  }
  cout << "Login failed. Please try again.\n";
  return "";
}
void viewAssignedCustomerList(CustomerAccount customerAccountArray[], int customerAccountArraySize, Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertIndex)
{
  string expertID = expertAccountArray[expertIndex].expertID;
  int indexNumber = 1;
  bool hasAssignedCustomers = false;

  // Set to track already displayed customers
  string displayedCustomers[200]; // Adjust size as needed
  int displayedCount = 0;

  cout << "\n\nYour Assigned Customers\n";
  cout << "====================================================================================\n";
  cout << left << setw(5) << "No."
    << setw(20) << "Customer Name"
    << setw(25) << "Service Type"
    << setw(15) << "Date"
    << setw(18) << "Time" << "\n";
  cout << "====================================================================================\n";

  // Loop through all appointments to find those assigned to this expert
  for (int i = 0; i < appointmentArraySize; i++)
  {
    // Skip empty appointments
    if (appointmentArray[i].appointmentID.empty()) {
      continue;
    }

    // Check if appointment is assigned to this expert
    if (appointmentArray[i].expertID == expertID)
    {
      // Check if this customer has already been displayed
      bool alreadyDisplayed = false;
      for (int k = 0; k < displayedCount; k++)
      {
        if (displayedCustomers[k] == appointmentArray[i].customerID)
        {
          alreadyDisplayed = true;
          break;
        }
      }

      if (alreadyDisplayed) {
        continue; // Skip duplicate customer
      }

      // Add customer to displayed list
      displayedCustomers[displayedCount++] = appointmentArray[i].customerID;

      hasAssignedCustomers = true;

      // Find customer details
      string customerName = "Unknown";
      for (int j = 0; j < customerAccountArraySize; j++)
      {
        if (customerAccountArray[j].customerID == appointmentArray[i].customerID)
        {
          customerName = customerAccountArray[j].firstName + " " + customerAccountArray[j].lastName;
          break;
        }
      }

      // Format date Example: Dec 12
      string dateStr = appointmentArray[i].appointmentDate;
      string formattedDate = "Dec " + dateStr.substr(6, 2);

      // Format time Example: 10AM-12PM
      int startTime = stoi(appointmentArray[i].appointmentTimeSlot.startTime);
      int endTime = stoi(appointmentArray[i].appointmentTimeSlot.endTime);
      string duration = to_string((endTime - startTime) / 100) + " Hours";


      // Display customer details with properly truncated strings
      cout << left << setw(5) << indexNumber++
        << setw(20) << customerName
        << setw(25) << appointmentArray[i].serviceType
        << setw(15) << formattedDate
        << setw(18) << duration << "\n";
    }
  }

  if (!hasAssignedCustomers)
  {
    cout << "No customers assigned to you yet.\n";
  }

  cout << "====================================================================================\n\n";

  // Wait for user to continue
  cout << "Press any key to return to menu...";
  cin.ignore();
  cin.get();
}
void viewIndividualSchedule(ExpertAccount expertAccountArray[], Appointment appointmentArray[], int appointmentArraySize, int expertIndex)
{
  int option;
  cout << "Select from the menu below. (1 - 3)\n";
  cout << "1. View Daily Schedule\n";
  cout << "2. View Weekly Schedule\n";
  cout << "3. Return to menu\n\n";
  cout << "Option: ";
  cin >> option;

  while (option < 1 || option > 3) {
    cout << "\nError! Please enter a valid option (1 - 3).\n";
    cout << "Option: ";
    cin >> option;
  }

  if (option == 3) {
    return; // back to main menu
  }

  if (option == 1) {
    // === DAILY SCHEDULE ===
    int dateInput;
    cout << "\nCalendar for December 2025\n";
    cout << "____________________________________\n\n";
    cout << "Select the day of the month to view your schedule (1 - 31): ";
    cin >> dateInput;

    while (dateInput < 1 || dateInput > 31) {
      cout << "Error! Please enter a valid day (1 - 31): ";
      cin >> dateInput;
    }

    cout << "\n\nViewing Daily Schedule\n";
    cout << "Expert: " << expertAccountArray[expertIndex].firstName << " "
      << expertAccountArray[expertIndex].lastName << "\n";
    cout << "Date: December " << dateInput << ", 2025\n";
    cout << "------------------------------------------------------------------\n";
    cout << left << setw(4) << "No."
      << setw(12) << right << "Start Time"
      << setw(12) << "End Time"
      << setw(20) << "Service Type"
      << setw(15) << "Customer ID" << "\n";
    cout << "------------------------------------------------------------------\n";

    int indexNumber = 1;
    bool found = false;

    for (int j = 0; j < appointmentArraySize; j++) {
      if (appointmentArray[j].appointmentID.empty()) continue;

      if (appointmentArray[j].expertID == expertAccountArray[expertIndex].expertID &&
        stoi(appointmentArray[j].appointmentDate.substr(6, 2)) == dateInput)
      {
        cout << left << setw(4) << indexNumber++
          << setw(12) << right << convertToAmPm(appointmentArray[j].appointmentTimeSlot.startTime)
          << setw(12) << convertToAmPm(appointmentArray[j].appointmentTimeSlot.endTime)
          << setw(20) << appointmentArray[j].serviceType
          << setw(15) << appointmentArray[j].customerID << "\n";
        found = true;
      }
    }

    if (!found) {
      cout << "No appointments booked. All slots available.\n";
    }
  }

  else if (option == 2) {
    // === WEEKLY SCHEDULE ===
    int weekInput;
    cout << "\nSelect the week of December 2025 to view (1 - 5): ";
    cin >> weekInput;

    while (weekInput < 1 || weekInput > 5) {
      cout << "Error! Please enter a valid week (1 - 5): ";
      cin >> weekInput;
    }

    int startDay = (weekInput - 1) * 7 + 1;
    int endDay = (weekInput == 5 ? 31 : weekInput * 7);

    cout << "\n\nViewing Weekly Schedule\n";
    cout << "Expert: " << expertAccountArray[expertIndex].firstName << " "
      << expertAccountArray[expertIndex].lastName << "\n";
    cout << "Week " << weekInput << " (Dec " << startDay << " - " << endDay << ")\n";
    cout << "------------------------------------------------------------------\n";
    cout << left << setw(4) << "No."
      << setw(12) << "Date"
      << setw(12) << right << "Start Time"
      << setw(12) << "End Time"
      << setw(20) << "Service Type"
      << setw(15) << "Customer ID" << "\n";
    cout << "------------------------------------------------------------------\n";

    int indexNumber = 1;
    bool found = false;

    for (int j = 0; j < appointmentArraySize; j++) {
      if (appointmentArray[j].appointmentID.empty()) continue;

      int day = stoi(appointmentArray[j].appointmentDate.substr(6, 2));
      if (appointmentArray[j].expertID == expertAccountArray[expertIndex].expertID &&
        day >= startDay && day <= endDay)
      {
        cout << left << setw(4) << indexNumber++
          << setw(12) << "Dec " + appointmentArray[j].appointmentDate.substr(6, 2)
          << setw(12) << right << convertToAmPm(appointmentArray[j].appointmentTimeSlot.startTime)
          << setw(12) << convertToAmPm(appointmentArray[j].appointmentTimeSlot.endTime)
          << setw(20) << appointmentArray[j].serviceType
          << setw(15) << appointmentArray[j].customerID << "\n";
        found = true;
      }
    }

    if (!found) {
      cout << "No appointments booked this week. All slots available.\n";
    }
  }
}
void viewEarningsBonusEntitlement(Appointment appointmentArray[], int appointmentArraySize, ExpertAccount expertAccountArray[], int expertAccountArraySize, int expertIDIndex)
{
  if (expertIDIndex < 0 || expertIDIndex >= expertAccountArraySize || expertAccountArray[expertIDIndex].expertID == "") {
    return;
  }

  ExpertAccount expert = expertAccountArray[expertIDIndex];

  double treatmentHours = 0, consultationHours = 0;
  double totalServiceCharges = 0;

  for (int i = 0; i < appointmentArraySize; i++) {
    if (appointmentArray[i].appointmentID == "" || !appointmentArray[i].paymentStatus) continue;

    // check if appointment belongs to this expert
    if (appointmentArray[i].expertID != expert.expertID) continue;

    // check if appointment is in December 2025
    if (appointmentArray[i].appointmentDate.length() == 8) {
      string year = appointmentArray[i].appointmentDate.substr(0, 4);
      string month = appointmentArray[i].appointmentDate.substr(4, 2);
      if (year != "2025" || month != "12") continue;
    }
    else {
      continue;
    }

    // calculate hours from timeslot
    int startHour = stoi(appointmentArray[i].appointmentTimeSlot.startTime.substr(0, 2));
    int endHour = stoi(appointmentArray[i].appointmentTimeSlot.endTime.substr(0, 2));
    double hours = endHour - startHour;

    if (appointmentArray[i].serviceType == "Treatment") {
      treatmentHours += hours;
    }
    else if (appointmentArray[i].serviceType == "Consultation") {
      consultationHours += hours;
    }

    totalServiceCharges += appointmentArray[i].totalPaid;
  }

  double totalHours = treatmentHours + consultationHours;

  double bonusPercent = 0;
  if (totalHours >= 30) bonusPercent = 50;
  else if (totalHours >= 25) bonusPercent = 25;

  double bonusEarned = (bonusPercent / 100.0) * totalServiceCharges;

  // display report
  cout << "\nExpert Bonus Report - December 2025\n";
  cout << "====================================\n";
  cout << "Expert: " << expert.expertID << " | "
    << expert.firstName << " " << expert.lastName
    << "\n";
  cout << "-------------------------------\n";
  cout << "Total Treatment Hours    : " << treatmentHours << "\n";
  cout << "Total Consultation Hours : " << consultationHours << "\n";
  cout << "Total Hours Completed    : " << totalHours << "\n";
  cout << fixed << setprecision(2);
  cout << "Total Service Charges    : RM" << totalServiceCharges << "\n";
  cout << "Bonus Percentage         : " << bonusPercent << "%\n";
  cout << "Bonus Earned             : RM" << bonusEarned << "\n";
}

// Miscellaneous Functions
int findExpertIndexByID(ExpertAccount expertAccountArray[], int expertAccountSize)
{
  string expertID;
  int expertIDIndex = -1;
  cout << "Enter ExpertID: ";
  cin >> expertID;

  // Check if expertID is not empty
  if (!expertID.empty()) {
    expertID[0] = static_cast<char>(toupper(expertID[0]));
  }
  else {
    cout << "ExpertID cannot be empty.";
    return -1;
  }

  bool found = false;

  for (int i = 0; i < expertAccountSize; i++) {
    if (expertID == expertAccountArray[i].expertID) {
      found = true;
      expertIDIndex = i;
      break; // Exit loop once found
    }
  }

  if (!found) {
    cout << "ExpertID not found.";
    return -1;
  }

  return expertIDIndex;
}
string serviceSelectionValidation()
{
  cout << "Available Services:\n";
  cout << "1. Massage Therapy\n";
  cout << "2. Aromatherapy\n";
  cout << "3. Reflexology\n";

  int choice;
  cout << "Enter desired service (1-3): ";
  cin >> choice;
  while (choice < 1 || choice > 3) {
    cout << "Invalid choice! Please enter a valid service number (1-3): ";
    cin >> choice;
  }

  switch (choice) {
  case 1: return "Massage Therapy"; break;
  case 2: return "Aromatherapy"; break;
  case 3: return "Reflexology"; break;
  }
  return "";
}
string convertToAmPm(string& time24) {
  // Extract hours and minutes
  int hours = stoi(time24.substr(0, 2));
  int minutes = stoi(time24.substr(2, 2));

  // Determine AM/PM
  string period = (hours < 12) ? "AM" : "PM";

  // Convert to 12-hour format
  if (hours == 0) {
    hours = 12; // Midnight case (00:00 becomes 12:00 AM)
  }
  else if (hours > 12) {
    hours -= 12;
  }

  // Format the output string without stringstream
  string result = to_string(hours) + ":";

  // Add leading zero to minutes if needed
  if (minutes < 10) {
    result += "0";
  }
  result += to_string(minutes) + " " + period;

  return result;
}
string convertToAmPm(int hour24) {
  // Validate input
  if (hour24 < 0 || hour24 > 23) {
    return "Invalid hour";
  }

  // Determine AM/PM
  string period = (hour24 < 12) ? "AM" : "PM";

  // Convert to 12-hour format
  int hour12;
  if (hour24 == 0) {
    hour12 = 12; // Midnight case (0 becomes 12 AM)
  }
  else if (hour24 > 12) {
    hour12 = hour24 - 12;
  }
  else {
    hour12 = hour24;
  }

  return to_string(hour12) + " " + period;
}
void eraseEmptyLinesFromFile(const string& fileName)
{
  ifstream inFile(fileName);
  if (!inFile.is_open()) {
    return;
  }

  string content, line;
  while (getline(inFile, line)) {
    // trim whitespace-only lines
    bool onlySpaces = true;
    for (size_t i = 0; i < line.size(); i++) {
      if (line[i] != ' ' && line[i] != '\t' && line[i] != '\r') {
        onlySpaces = false;
        break;
      }
    }

    if (!onlySpaces && !line.empty()) {
      content += line + "\n";
    }
  }
  inFile.close();

  ofstream outFile(fileName, ios::trunc);
  if (!outFile.is_open()) {
    return;
  }
  outFile << content;
  outFile.close();
}
void showExpertTimeTable(ExpertAccount expertAccountArray[], int expertIndex)
{
  if (expertAccountArray[expertIndex].expertID.empty()) {
    return; // Skip empty expert slots
  }

  cout << "ExpertID: " << expertAccountArray[expertIndex].expertID << "\n";
  cout << "Name: " << expertAccountArray[expertIndex].firstName << " " << expertAccountArray[expertIndex].lastName
    << " (" << expertAccountArray[expertIndex].specialization << ")\n";
  cout << "-------------------------------------------------------------------\n";

  // Header: Day/Time and hours 9AM - 5PM
  cout << setw(10) << left << "Day/Time";
  for (int hour = 9; hour <= 17; hour++) {
    cout << setw(6) << left << convertToAmPm(hour);
  }
  cout << "\n";

  // For each day in December (1..31)
  for (int day = 0; day < 31; day++)
  {
    cout << setw(10) << (day + 1); // Display day number (1-based)
    for (int hour = 9; hour <= 17; hour++)
    {
      // Use booked flag to display slot status
      if (expertAccountArray[expertIndex].timeSlots[day][hour].booked) {
        cout << "[X]   ";
      }
      else {
        cout << "[ ]   ";
      }
    }
    cout << "\n";
  }

  cout << "-------------------------------------------------------------------\n\n";
}

// File Loading Functions
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
void loadExpertTimeSlots(Appointment* appointmentArray, int appointmentArraySize, ExpertAccount* expertAccountArray, int expertAccountArraySize)
{
  for (int e = 0; e < expertAccountArraySize; e++) {
    if (expertAccountArray[e].expertID.empty()) continue; // skip unused experts
    for (int d = 0; d < 31; d++) {
      for (int h = 0; h < 24; h++) {
        expertAccountArray[e].timeSlots[d][h].booked = false;
        expertAccountArray[e].timeSlots[d][h].appointmentID = "";
      }
    }
  }
  for (int i = 0; i < appointmentArraySize; i++)
  {
    if (appointmentArray[i].appointmentID.empty()) {
      continue; // Skip empty appointments
    }
    else
    {
      int appointmentDay = stoi(appointmentArray[i].appointmentDate.substr(6, 2)) - 1; // Extract day
      int appointmentStartHour = stoi(appointmentArray[i].appointmentTimeSlot.startTime.substr(0, 2)); // Extract start hour


      int expertAccountIndex = -1; // Initialize to invalid value
      for (int j = 0; j < expertAccountArraySize; j++)
      {
        if (appointmentArray[i].expertID == expertAccountArray[j].expertID)
        {
          expertAccountIndex = j;
          break;
        }
      }

      // Skip if expert not found
      if (expertAccountIndex == -1) {
        continue;
      }

      if (appointmentArray[i].serviceType == "Consultation")
      {
        expertAccountArray[expertAccountIndex].timeSlots[appointmentDay][appointmentStartHour].booked = true;
        expertAccountArray[expertAccountIndex].timeSlots[appointmentDay][appointmentStartHour].appointmentID = appointmentArray[i].appointmentID;
      }
      else if (appointmentArray[i].serviceType == "Treatment")
      {
        // Check if treatment duration fits within the day
        if (appointmentStartHour + 2 < 24) {
          expertAccountArray[expertAccountIndex].timeSlots[appointmentDay][appointmentStartHour].booked = true;
          expertAccountArray[expertAccountIndex].timeSlots[appointmentDay][appointmentStartHour + 1].booked = true;
          expertAccountArray[expertAccountIndex].timeSlots[appointmentDay][appointmentStartHour + 2].booked = true;
          expertAccountArray[expertAccountIndex].timeSlots[appointmentDay][appointmentStartHour].appointmentID = appointmentArray[i].appointmentID;
        }
      }
    }
  }
}