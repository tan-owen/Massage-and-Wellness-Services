#pragma once
#include <iostream>
#include <string>
#include "function.hpp"


void organizationLogoScreen();
void modeSelectScreen();

//user screens
void customerMode();
void customerRegistrationScreen();
void customerLoginScreen(struct Account *account);
void customerOptionScreen(struct Account *account);
void appointmentSelectScreen();
void serviceSelectScreen();
void expertSelectScreen();
void dateSelectScreen();
void timeSlotSelectScreen();
void paymentMethodSelectScreen();
void paymentSuccessScreen();
void viewBookingScreen();

//admin screens
void adminLoginScreen();
void adminOptionScreen();
void viewOverallScheduleScreen();
void viewCustomerListScreen();
void generateSalesReportScreen();
void viewExpertBonusScreens_ADMIN();

//expert screens
void expertLoginScreen();
void viewScheduleScreen();
void viewAssignedCustomerScreen();
void viewEarningBonusScreen_EXPERT();

