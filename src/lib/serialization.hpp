#pragma once
#include <string>

std::string getStringValueByKey(std::string inputDataString, std::string key);
int getIntValueByKey(std::string inputDataString, std::string key);
double getDoubleValueByKey(std::string inputDataString, std::string key);
float getFloatValueByKey(std::string inputDataString, std::string key);
char getCharValueByKey(std::string inputDataString, std::string key);
bool getBoolValueByKey(std::string inputDataString, std::string key);

std::string serializeString(std::string data, std::string key);
std::string serializeInt(int data, std::string key);
std::string serializeDouble(double data, std::string key);
std::string serializeFloat(float data, std::string key);
std::string serializeChar(char data, std::string key);
std::string serializeBool(bool data, std::string key);