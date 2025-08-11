#pragma once
#include <string>
#include <fstream>

template <typename DataStruct>
void loadFromFile(std::string filename, DataStruct *array, DataStruct (*fromString)(std::string stringData), int *arrayLength)
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