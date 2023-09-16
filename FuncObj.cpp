
#include "FuncObj.h"

template<typename T>
FuncObj<T>::FuncObj(std::vector<std::pair<T, T>> coords) : base_coords(coords) {
    if (base_coords.empty()) {
        throw std::invalid_argument("Empty coordinates");
    }
    std::random_device rd;
    generator = std::mt19937(rd());
    distribution = std::uniform_int_distribution<int>(0, base_coords.size() - 1);
};

template<typename T>
std:: pair<T, T>& FuncObj<T>::generate() {
    return base_coords.at(distribution(generator));
};

template<typename T>
std::pair<T, T> FuncObj<T>::operator () (std::pair<T, T> point) {
    auto& base_coord = generate();
    return std::pair<T, T>((base_coord.first + point.first) / 2., (base_coord.second + point.second) / 2.);
};
