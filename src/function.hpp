#pragma once
#include <iostream>
#include <string>
#include "struct.hpp"
#include <fstream>
#include <sstream>

int fileLineCount(const std::string& fileName);
void loadFromAccountFile(struct Account* account, int lineIndex);
void printLoadFromAccountStruct(struct Account& account);