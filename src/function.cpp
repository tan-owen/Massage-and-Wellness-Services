#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstring>
#include "function.hpp"
#include "struct.hpp"
#include "menu.hpp"

int fileLineCount(const std::string& fileName)
{
    string fileText;
    ifstream accountFileLineCount("account.txt");
    int lineCount = 0;

    while (getline(accountFileLineCount, fileText)) {
        lineCount++;
    }
    accountFileLineCount.close();
	return lineCount;
}

void loginVerification() {
    int accountType;
    cout << "--- Select your identify ---" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Expert" << endl;
    cout << "3. Admin" << endl;
    cout << "Please select your account type (1/2/3): ";
    cin >> accountType;
    switch(accountType){
        case 1: customerMode(); break;
        case 2: expertLoginScreen(); break;
        case 3: adminLoginScreen(); break;
    }
}

void loadFromAccountFile(struct Account* account, int lineIndex) {
    string fileText;
    ifstream accountFile("account.txt");

    int currentLine = 0;
    while (getline(accountFile, fileText)) {
        if (currentLine == lineIndex) {
            // C0001;username=john;password=1234;firstName=John;lastName=Black;

            // Get accountID
            if (account[lineIndex].accountID.empty()) {
                account[lineIndex].accountID = fileText.substr(0, 5);
            }

            // Get accountType
            switch (fileText[0]) {
            case 'C':  account[lineIndex].accountType = "Customer"; break;
            case 'E':  account[lineIndex].accountType = "Expert";   break;
            case 'A':  account[lineIndex].accountType = "Admin";    break;
            default:
                cout << "Invalid account type" << endl;
                break;
            }

            // Get username 
            if (account[lineIndex].username.empty()) {
                account[lineIndex].username = fileText.substr(
                    fileText.find("username=") + string("username=").length(),
                    fileText.find(';', fileText.find("username=")) - (fileText.find("username=") + string("username=").length())
                );
            }

            // Get password 
            if (account[lineIndex].password.empty()) {
                account[lineIndex].password = fileText.substr(
                    fileText.find("password=") + string("password=").length(),
                    fileText.find(';', fileText.find("password=")) - (fileText.find("password=") + string("password=").length())
                );
            }

            // Get firstName 
            if (account[lineIndex].firstName.empty()) {
                account[lineIndex].firstName = fileText.substr(
                    fileText.find("firstName=") + string("firstName=").length(),
                    fileText.find(';', fileText.find("firstName=")) - (fileText.find("firstName=") + string("firstName=").length())
                );
            }

            // Get lastName 
            if (account[lineIndex].lastName.empty()) {
                account[lineIndex].lastName = fileText.substr(
                    fileText.find("lastName=") + string("lastName=").length(),
                    fileText.find(';', fileText.find("lastName=")) - (fileText.find("lastName=") + string("lastName=").length())
                );
            }

            break; // Done with this line, exit loop
        }
        currentLine++;
    }

    accountFile.close();
}


void printLoadFromAccountStruct(Account& account) {
    cout << "Account ID\t: " << account.accountID << endl;
    cout << "Account Type\t: " << account.accountType << endl;
    cout << "Username\t: " << account.username << endl;
    cout << "Password\t: " << account.password << endl;
    cout << "First Name\t: " << account.firstName << endl;
    cout << "Last Name\t: " << account.lastName << endl;
};