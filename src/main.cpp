#include <iostream>
#include <string>
#include <fstream>
#include "function.hpp"
#include "struct.hpp"
#include "menu.hpp"
using namespace std;

int main() {
    int accountArraySize = fileLineCount("AccountCustomer.txt");
    CustomerAccount* customerAccountArry = new CustomerAccount[accountArraySize];
    loadToCustomerAccountStruct(customerAccountArry, accountArraySize);

    // TEST PRINT ALL CUSTOMER STRUCTS
    for (int i = 0; i < accountArraySize; i++) {
		cout << "________________________________" << endl;
        printLoadFromAccountStruct(customerAccountArry[i]);
    }


    // Clean up allocated memory
    delete[] customerAccountArry;
    return 0;
}

