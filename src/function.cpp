#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstring>
#include "function.hpp"
#include "struct.hpp"

int fileLineCount(const std::string& fileName)
{
    string fileText;
    ifstream accountFileLineCount(fileName);
    int lineCount = 0;

    while (getline(accountFileLineCount, fileText)) {
        lineCount++;
    }
    accountFileLineCount.close();
	return lineCount;
}

// Customer Account Struct Functions
void loadToCustomerAccountStruct(struct CustomerAccount* account, int lineIndex) {
    for (int i = 0; i < lineIndex; i++) {
        loadFromCustomerAccountFile(account, i);
    }
}
void loadFromCustomerAccountFile(struct CustomerAccount* account, int lineIndex) {
    string fileText;
    ifstream accountFile("AccountCustomer.txt");

    int currentLine = 0;
    while (getline(accountFile, fileText)) {
        if (currentLine == lineIndex) {
            // C0001;username=john;password=1234;firstName=John;lastName=Black;

            // Get accountID
            account[lineIndex].customerID = fileText.substr(0, 5);

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

        }
        currentLine++;
    }

    accountFile.close();
}

// Test Function to print Customer Account Struct
void printLoadFromAccountStruct(struct CustomerAccount& account) {
    cout << "Account ID\t: " << account.customerID << endl;
    cout << "Username\t: " << account.username << endl;
    cout << "Password\t: " << account.password << endl;
    cout << "First Name\t: " << account.firstName << endl;
    cout << "Last Name\t: " << account.lastName << endl;

};
