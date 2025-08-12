#pragma once
#include <string>
#include <fstream>

// Load data from file into `array` given, will update `arrayLength` variable with the count of data loaded.
// `fromString` function - impl of how to convert from single line of string to struct
template <typename DataStruct>
void loadFromFile(std::string filename, DataStruct *array, int *arrayLength, DataStruct (*fromString)(std::string stringData))
{
    std::string line;
    std::ifstream inputStream(filename);
    *arrayLength = 0;
    while (getline(inputStream, line))
    {
        DataStruct data = fromString(line);
        array[*arrayLength] = data;
        (*arrayLength)++;
    }
}

// Save an array of struct into a file
// `toString` function - impl of how to convert struct to a single line of string
template <typename DataStruct>
void saveToFile(std::string filename, DataStruct *array, int length, std::string (*toString)(DataStruct data))
{
    std::ofstream outputFile;
    outputFile.open(filename);

    for (int i = 0; i < length; i++)
    {
        DataStruct data = array[i];
        std::string dataString = toString(data);
        outputFile << dataString << std::endl;
    }

    outputFile.close();
}