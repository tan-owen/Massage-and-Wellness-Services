#include "serialization.hpp"
#include <string>

std::string deserializeString(std::string inputDataString, std::string key)
{
    std::size_t keyIndex = inputDataString.find(key + "=");
    std::size_t keyLength = std::string(key + "=").length();
    std::size_t delimiterIndex = inputDataString.find(';', keyIndex);
    std::size_t dataStartIndex = keyIndex + keyLength;
    return inputDataString.substr(dataStartIndex, delimiterIndex - dataStartIndex);
}

std::string serializeString(std::string data, std::string key)
{
    std::string outputString = key + "=" + data + ";";
    return outputString;
}