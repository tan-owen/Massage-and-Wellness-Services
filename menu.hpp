#pragma once
#include <iostream>
#include <string>
#include "function.hpp"
using namespace std;


string organizationLogoScreen()  ;
void loginScreen();
void registrationScreen();

//user screens
void customerOptionScreen();
void appointmentSelectScreen();
void serviceSelectScreen();
void expertSelectScreen();
void dateSelectScreen();
void timeSlotSelectScreen();
void paymentMethodSelectScreen();
void paymentSuccessScreen();
void viewBookingScreen();

//admin screens
void adminOptionScreen();
void viewOverallScheduleScreen();
void viewCustomerListScreen();
void generateSalesReportScreen();
void viewExpertBonusScreens_ADMIN();

//expert screens
void viewScheduleScreen();
void viewAssignedCustomerScreen();
void viewEarningBonusScreen_EXPERT();
