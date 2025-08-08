#include <iostream>
#include <string>
#include <fstream>
#include "function.hpp"
#include "struct.hpp"
#include "menu.hpp"
using namespace std;

void main() {
	int accountArraySize = fileLineCount("account.txt");
	Account* account = new Account[accountArraySize];
    for (int i = 0; i < fileLineCount("account.txt"); i++) {
        loadFromAccountFile(account, i);
    }

    for (int i = 0; i < fileLineCount("account.txt"); i++) {
		cout << "------------------------" << endl;
        printLoadFromAccountStruct(account[i]);
    }
}

