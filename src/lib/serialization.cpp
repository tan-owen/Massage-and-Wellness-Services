#include "serialization.hpp"
#include <string>

std::string getStringValueByKey(std::string inputDataString, std::string key)
{
    std::size_t keyIndex = inputDataString.find(key + "=");
    std::size_t keyLength = std::string(key + "=").length();
    std::size_t delimiterIndex = inputDataString.find(';', keyIndex);
    std::size_t dataStartIndex = keyIndex + keyLength;
    return inputDataString.substr(dataStartIndex, delimiterIndex - dataStartIndex);
}

int getIntValueByKey(std::string inputDataString, std::string key)
{
    std::string stringValue = getStringValueByKey(inputDataString, key);
    return std::stoi(stringValue);
}

double getDoubleValueByKey(std::string inputDataString, std::string key)
{
    std::string stringValue = getStringValueByKey(inputDataString, key);
    return std::stod(stringValue);
}

float getFloatValueByKey(std::string inputDataString, std::string key)
{
    std::string stringValue = getStringValueByKey(inputDataString, key);
    return std::stof(stringValue);
}

char getCharValueByKey(std::string inputDataString, std::string key)
{
    std::string stringValue = getStringValueByKey(inputDataString, key);
    return stringValue.at(0);
}

bool getBoolValueByKey(std::string inputDataString, std::string key)
{
    int intValue = getIntValueByKey(inputDataString, key);
    return intValue == 1;
}

std::string serializeString(std::string data, std::string key)
{
    return key + "=" + data + ";";
}

std::string serializeInt(int data, std::string key)
{
    return key + "=" + std::to_string(data);
}

std::string serializeDouble(double data, std::string key)
{
    return key + "=" + std::to_string(data);
}

std::string serializeFloat(float data, std::string key)
{
    return key + "=" + std::to_string(data);
}

std::string serializeChar(char data, std::string key)
{
    return key + "=" + std::to_string(data);
}

std::string serializeBool(bool data, std::string key)
{
    return key + "=" + std::to_string(data);
}
