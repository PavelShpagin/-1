
#include "FuncObj.h"

template <typename T>
FuncObj<T>::FuncObj(std::vector<std::pair<T, T>> coords, int _n, std::pair<T, T> initial) : base_coords(coords), n(_n), initialPoint(initial)
{
    if (base_coords.empty())
    {
        throw std::invalid_argument("Empty coordinates");
    }
    std::random_device rd;
    generator = std::mt19937(rd());
    distribution = std::uniform_int_distribution<int>(0, base_coords.size() - 1);
};

template <typename T>
std::pair<T, T> &FuncObj<T>::generate()
{
    return base_coords.at(distribution(generator));
};

template <typename T>
std::vector<std::pair<T, T>> FuncObj<T>::operator()()
{
    generatedCoords.push_back(initialPoint);

    for (int i = 0; i < n; ++i)
    {
        auto &base_coord = generate();
        auto &previousCoord = generatedCoords[generatedCoords.size() - 1];
        generatedCoords.push_back(std::pair<T, T>((base_coord.first + previousCoord.first) / 2., (base_coord.second + previousCoord.second) / 2.));
    }

    return generatedCoords;
};
