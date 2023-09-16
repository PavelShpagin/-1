#include <fstream>
#include "FileData.h"
#include "readFileData.h"

template <typename T>
FileData<T> readFileData(const std::string &fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file with data.");
    }

    FileData<T> data;

    if (!(file >> data.n))
    {
        throw std::runtime_error("Invalid value for 'n' in the file.");
    }

    if (data.n < 0)
    {
        throw std::runtime_error("Negative value for 'n' in the file.");
    }

    T x, y;
    file >> x >> y;
    data.initialPoint = std::make_pair(x, y);

    while (file >> x >> y)
    {
        data.baseCoords.push_back(std::make_pair(x, y));
    }

    file.close();
    return data;
}