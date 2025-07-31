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
//
//
//
////expert screens
//void viewScheduleScreen();
//
//
//void viewAssignedCustomerScreen();
//
//
//void viewEarningBonusScreen_EXPERT();

void customerMode() {
    void customerLoginRegistrationSelectionScreen();
}