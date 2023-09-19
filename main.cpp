#include <iostream>
#include <vector>
#include "FuncObj.cpp"
#include "readFileData.cpp"
#include "writeResultToFile.cpp"

int main()  
{
    FileData<double> fileData = readFileData<double>("data.txt");

    int n = fileData.n;
    std::pair initialPoint = fileData.initialPoint;
    std::vector<std::pair<double, double>> baseCoords = fileData.baseCoords;

    FuncObj<double> obj(baseCoords, n, initialPoint);

    for (const auto &coord : obj())
    {
        std::cout << coord.first << " " << coord.second << std::endl;
        writeResultToFile("result.txt", std::to_string(coord.first) + " " + std::to_string(coord.second));
    }

    return 0;
}