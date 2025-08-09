#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "function.hpp"
#include "struct.hpp"
#include "menu.hpp"
using namespace std;

int main() {
	int accountArraySize = fileLineCount("account.txt");
	Account* account = new Account[accountArraySize];
    for (int i = 0; i < fileLineCount("account.txt"); i++) {
        loadFromAccountFile(account, i);
    }

    loginVerification();

    
   
    


    // cout << account[5].username << endl;
    // for (int i = 0; i < fileLineCount("account.txt"); i++) {
	// 	cout << "------------------------" << endl;
    //     printLoadFromAccountStruct(account[i]);
    // }
    return 0;
}

