#include <fstream>
#include <sstream>
#include "FileData.h"
#include "readFileData.h"

bool isInteger(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '-') {
            return false;
        }
    }
    return true;
}

bool isDouble(const std::string& str) {
    std::istringstream ss(str);
    double testDouble;
    ss >> std::noskipws >> testDouble;

    return ss.eof() && !ss.fail();
}

template <typename T>
FileData<T> readFileData(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        throw std::runtime_error("File with data is empty.");
    }

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file with data.");
    }

    std::string buffer1, buffer2;
    FileData<T> data;

    if (!(file >> buffer1))
    {
        throw std::runtime_error("Invalid value for 'n' in the file.");
    }
    if (isInteger(buffer1)) data.n = std::stoi(buffer1);
    else throw std::runtime_error("Invalid value for 'n' in the file.");

    if (data.n < 0)
    {
        throw std::runtime_error("Negative value for 'n' in the file.");
    }

    if (data.n == 0)
    {
        throw std::runtime_error("Zero value for 'n' in the file.");
    }

    file >> buffer1 >> buffer2;
    if (isDouble(buffer1) && isDouble(buffer2)) data.initialPoint = std::make_pair(std::stod(buffer1), std::stod(buffer2));
    else throw std::runtime_error("Invalid value for initial point in the file.");

    while (file >>  buffer1 >> buffer2)
    {
        if (isDouble(buffer1) && isDouble(buffer2)) data.baseCoords.push_back(std::make_pair(std::stod(buffer1), std::stod(buffer2)));
        else throw std::runtime_error("Invalid value for a base point in the file.");
    }

    file.close();
    return data;
}