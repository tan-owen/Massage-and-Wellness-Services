#pragma once
#include <iostream>
#include <string>
#include "struct.hpp"
#include <fstream>
#include <sstream>

int fileLineCount(const std::string& fileName);
void loadFromCustomerAccountFile(struct CustomerAccount* account, int lineIndex);
void loadToCustomerAccountStruct(struct CustomerAccount* account, int lineIndex);

// TEST FUNCTION
void printLoadFromAccountStruct(struct CustomerAccount& account);
void printLoadFromAccountStruct(struct ExpertAccount& account);