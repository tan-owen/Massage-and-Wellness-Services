#include "menu.hpp"
using namespace std;


void organizationLogoScreen() {
    cout << "========================================\n";
    cout << "|                                      |\n";
    cout << "|          Massage & Wellness          |\n";
    cout << "|                                      |\n";
    cout << "========================================\n";
    cout << "\n";
};

void modeSelectScreen() {
    cout << "--- Mode Select ---\n";
    cout << "1. Customer Mode\n";
    cout << "2. Expert Mode\n";
    cout << "3. Admin Mode\n";
    cout << "Please select a mode to continue(1/2/3): ";
    int choice = 0;
    while (choice < 1 || choice > 3) {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\n";
                customerMode();
                break;
            case 2:
                // expertMode();
                break;
            case 3:
                // adminMode();
                break;
            default:
                cout << "Invalid. Please select again (1/2/3): ";
		}
	}
};


//user screens
void customerLoginRegistrationSelectionScreen() {
	cout << "Would you like to login or register?\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "Please select an option (1/2): ";
    int choice = 0;
    while (choice < 1 || choice > 2) {
        cin >> choice;
        switch (choice) {
            case 1:
                customerLoginScreen();
                break;
            case 2:
                custoemerRegistrationScreen();
                break;
            default:
                cout << "Invalid. Please select again (1/2): ";
        }
	}
}

void customerLoginScreen() {
    cout << "--- Login Screen ---\n";
     string username, password;
     cout << "Username: ";
     cin >> username;
     cout << "Password: ";
     cin >> password;
}

void custoemerRegistrationScreen() {
    cout << "--- Registration Screen ---\n";
     string newUsername, newPassword;
     cout << "Choose a username: ";
     cin >> newUsername;
     cout << "Choose a password: ";
     cin >> newPassword;
}


//void customerOptionScreen() {
//    cout << "--- Customer Options ---\n";
//    cout << "1. View Services\n";
//    cout << "2. Book Appointment\n";
//    cout << "3. View My Appointments\n";
//    cout << "4. Logout\n";
//}
//
//void appointmentSelectScreen() {//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    cout << "--- Select Appointment Date/Time ---\n";
//    cout << "Available dates: 2025-08-01, 2025-08-02...\n";
//    cout << "Available times: 9:00 AM, 10:00 AM...\n";
//
//}
//
//void serviceSelectScreen() {
//    cout << "--- Select a Service ---\n";
//    cout << "1. Haircut\n";
//    cout << "2. Massage\n";
//    cout << "3. Manicure\n";
//    cout << "4. Pedicure\n";
//
//}
//
//void expertSelectScreen() {
//    cout << "--- Select an Expert ---\n";
//    cout << "1. John Doe (Hair)\n";
//    cout << "2. Jane Smith (Massage)\n";
//    cout << "3. Peter Jones (Nails)\n";
//    // Logic to display available experts and get user selection
//}
//
//
//void dateSelectScreen(){//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//// 
//};
//void timeSlotSelectScreen(){//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    cout<<"Select a time slot for your appointment:"<< endl;
//
//    // cout<<"1. 0900 - 1000"<<endl;
//    //cout<<"2. 1000 - 1100"<<endl;
//
//};
//void paymentMethodSelectScreen(){
//    cout << "Select a payment method:" << endl;
//    // cout << "1. Cash" << endl;
//    // cout << "2. Debit & Credit Card" << endl;
//    // cout << "3. Touch N Go" << endl;
//    // cout << "4. Bank Transfer" << endl;
//};
//
//void paymentSuccessScreen(){
//    cout << "Payment successful!" << endl;
//    cout << "Thank you for your payment." << endl;
//};
//
//void viewBookingScreen(){
//    cout << "Here are your booking details:" << endl;
//};
//
//void adminOptionScreen(){
//    // cout << "Admin Options:" << endl;
//    // cout << "1. View All Appointments" << endl;
//    // cout << "2. Manage Accounts" << endl;
//    // cout << "3. View Overall Schedule" << endl;
//    // cout << "4. Exit" << endl;
//};
//
//void viewOverallScheduleScreen(){
//    cout << "Overall Schedule:" << endl;
//};
//
//// LSX
//
////admin screen
//void viewCustomerListScreen();
//    //cout << "List of Customers\n"; 
//    //cout << "--------------------------------------------------------\n";
//    //cout << left << setw(5) << "No. |" << setw(30) << "Customer Name" << setw(8) << "Date" << setw(6) << "Time" << setw(20) << "Payment Details" << setw(30) << "Expert Name" << setw(20) << "Service Type" << "\n";
//    //cout << "--------------------------------------------------------\n";
//    //cout << left << setw(5) << "1. " << setw(30) << "Name Name Name" << setw(8) << "Dec 12" << setw(6) << "1400" << setw(20) << "Credit Card" << setw(30) << "Expert Name Name" << setw(20) << "Massage" << "\n";
//    //cout << left << setw(5) << "2. " << setw(30) << "Name Name Name" << setw(8) << "Dec 12" << setw(6) << "1400" << setw(20) << "Credit Card" << setw(30) << "Expert Name Name" << setw(20) << "Massage" << "\n";
//
//void generateSalesReportScreen();
//    //cout << "Sales Report\n";
//    //cout << "--------------------------------------------------------\n";
//    //cout << "Sales Report\n";
//    //cout << "--------------------------------------------------------\n";
//    //cout << left << setw(5) << "No. |" << setw(30) << "Service Type" << setw(16) << "Total Bookings" << setw(18) << "Sales Total (RM)" << "\n";
//    //cout << "--------------------------------------------------------\n";
//    //cout << left << setw(5) << "1. " << setw(30) << "Consultations" << setw(16) << "25" << setw(18) << "RM 2,500.00" << "\n";
//    //cout << left << setw(5) << "2. " << setw(30) << "Example Treatments" << setw(16) << "18" << setw(18) << "RM 1,800.00" << "\n";
//    //cout << left << setw(5) << "3. " << setw(30) << "Example Treatments" << setw(16) << "12" << setw(18) << "RM 1,200.00" << "\n";
    
//    //cout << "1. Date Range\n";
//    //cout << "2. Service Category\n";
//    //cout << "3. Expert\n\n";
//    //cout << "Select from the option above (1 - 3): \n\n";
//    
//    //cout << "Enter date range: \n\n";
//    //cout << "Total sales for date range: $20000 \n\n";
//    
//    //cout << "Enter service category: \n\n";
//    //cout << "Total sales for service category: $20101 \n\n";
//    
//    //cout << "Enter expert name: \n\n";
//    //cout << "Total sales for expert name: $10000 \n\n";
//
//
//void viewExpertBonusScreens_ADMIN();

//    //cout << "Expert Bonus Summary\n";
//    //cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
//    //cout << left << setw(5) << "No. |" << setw(15) << "Expert Name" << setw(18) << "Treatment Hours" << setw(20) << "Consultation Hours" << setw(16) << "Combined Hours" << setw(18) << "Service Value (RM)" << setw(15) << "Bonus Rate (%)" << setw(18) << "Bonus Amount (RM)" << "\n";
//    //cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
//    //cout << left << setw(5) << "1. " << setw(15) << "Name 12345" << setw(18) << "25" << setw(20) << "15" << setw(16) << "40" << setw(18) << "RM 2,500.00" << setw(15) << "8%" << setw(18) << "RM 200.00" << "\n";
//    //cout << left << setw(5) << "2. " << setw(15) << "Name 12345" << setw(18) << "18" << setw(20) << "12" << setw(16) << "30" << setw(18) << "RM 1,800.00" << setw(15) << "7%" << setw(18) << "RM 126.00" << "\n";
//    //cout << left << setw(5) << "3. " << setw(15) << "Name 12345" << setw(18) << "12" << setw(20) << "8" << setw(16) << "20" << setw(18) << "RM 1,200.00" << setw(15) << "6%" << setw(18) << "RM 72.00" << "\n";
    

	
////expert screens
//void viewScheduleScreen();
//cout << "Expert Schedule\n";
//    //cout << "Name: Name 12345\n";
//    //cout << "Week: 3\n";
//    //cout << "-------------------------------------------------------------------------\n";
//    //cout << left << setw(6) << "No." 
//    //<< setw(15) << "Date" 
//    //<< setw(12) << "Start Time" 
//    //<< setw(12) << "End Time" 
//    //<< setw(20) << "Service Type" 
//    //<< setw(20) << "Customer Name" << "\n";
//    //cout << "-------------------------------------------------------------------------\n";
//    //cout << left << setw(6) << "1." 
//    //<< setw(15) << "Dec 12 (FRI)" 
//    //<< setw(12) << "9 AM" 
//    //<< setw(12) << "11 AM" 
//    //<< setw(20) << "Massage" 
//    //<< setw(20) << "John Smith" << "\n";
//    //cout << left << setw(6) << "2." 
//    //<< setw(15) << "Dec 12 (FRI)" 
//    //<< setw(12) << "2 PM" 
//    //<< setw(12) << "4 PM" 
//    //<< setw(20) << "Consultation" 
//    //<< setw(20) << "Mary Johnson" << "\n";
//    //cout << left << setw(6) << "3." 
//    //<< setw(15) << "Dec 12 (FRI)" 
//    //<< setw(12) << "5 PM" 
//    //<< setw(12) << "6 PM" 
//    //<< setw(20) << "Facial" 
//    //<< setw(20) << "David Lee" << "\n";
//    //cout << "-------------------------------------------------------------------------\n";
//    //cout << "Total Working Hours: " << "\n";
//
//void viewAssignedCustomerScreen();
//
//    //cout << "View Booked Customers\n";
//    //cout << "------------------------------------------------------------------------------------------\n";
//    //cout << left << setw(6) << "No." 
//    //<< setw(20) << "Customer Name" 
//    //<< setw(15) << "Date" 
//    //<< setw(12) << "Start Time" 
//    //<< setw(12) << "End Time" 
//    //<< setw(20) << "Service Type" 
//    //<< setw(10) << "Duration" << "\n";
//    //cout << "------------------------------------------------------------------------------------------\n";
//    //cout << left << setw(6) << "1." 
//    //<< setw(20) << "John Smith" 
//    //<< setw(15) << "Dec 12 (FRI)" 
//    //<< setw(12) << "9 AM" 
//    //<< setw(12) << "11 AM" 
//    //<< setw(20) << "Massage" 
//    //<< setw(10) << "2 hrs" << "\n";
//    //cout << left << setw(6) << "2." 
//    //<< setw(20) << "Mary Johnson" 
//    //<< setw(15) << "Dec 12 (FRI)" 
//    //<< setw(12) << "2 PM" 
//    //<< setw(12) << "4 PM" 
//    //<< setw(20) << "Consultation" 
//    //<< setw(10) << "2 hrs" << "\n";
//    //cout << left << setw(6) << "3." 
//    //<< setw(20) << "David Lee" 
//    //<< setw(15) << "Dec 12 (FRI)" 
//    //<< setw(12) << "5 PM" 
//    //<< setw(12) << "6 PM" 
//    //<< setw(20) << "Facial" 
//    //<< setw(10) << "1 hr" << "\n";
//    //cout << "------------------------------------------------------------------------------------------\n";


//
//void viewEarningBonusScreen_EXPERT();
//    //cout << "Bonus Summary\n\n";
//    //cout << "---------------------------------------\n";
//    //cout << std::left << std::setw(25) << "Consultation Hours :" << "6" << '\n';
//    //cout << std::left << std::setw(25) << "Treatment Hours :" << "24" << '\n';
//    //cout << std::left << std::setw(25) << "Combined Hours :" << "30" << '\n';
//    //cout << std::left << std::setw(25) << "Total Service Value :" << "RM 2100.00" << '\n';
//    //cout << std::left << std::setw(25) << "Eligible Bonus :" << "50%" << '\n';
//    //cout << std::left << std::setw(25) << "Bonus Amount:" << "RM 1050.00" << '\n';

void customerMode() {
    void customerLoginRegistrationSelectionScreen();
}
