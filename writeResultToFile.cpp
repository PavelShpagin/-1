#include <fstream>
#include "writeResultToFile.h"

void writeResultToFile(const std::string &filename, const std::string &text)
{
    std::ofstream file(filename, std::ios_base::app);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file with data.");
    }

    file << text << std::endl;
    if (file.fail())
    {
        throw std::runtime_error("Error writing result in file.");
    }

    file.close();
}