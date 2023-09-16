#pragma once

#include <iostream>
#include <vector>
#include <random>

template<typename T>
class FuncObj {
private:
    std::vector<std::pair<T, T>> base_coords;//базові координати
    std::mt19937 generator;//генератор
    std::uniform_int_distribution<int> distribution;//розподіл для вибору базової точки

    std::pair<T, T>& generate();
    //Повертає одну випадкову базову точку
public:
    FuncObj(std::vector<std::pair<T, T>>);
    //Приймає на вхід базові координати

    std::pair<T, T> operator () (std::pair<T, T>);
    //Оператор виклику функції, приймає
    // одну точку як аргумент
};