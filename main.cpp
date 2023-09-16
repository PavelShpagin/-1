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

    FuncObj<double> obj(std::vector<std::pair<double, double>>({{1, 2.}, {-1.2, 5.1}}));
    auto coord1 = obj(std::pair<double, double>{5., -7.});
    auto coord2 = obj(std::pair<double, double>{5., -7.});
    auto coord3 = obj(std::pair<double, double>{5., -7.});
    for (auto coord : {coord1, coord2, coord3})
    {
        printf("%.2f, %.2f\n", coord.first, coord.second);
    }

    return 0;
}