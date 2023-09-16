#pragma once

#include <iostream>
#include <vector>

template <typename T>
struct FileData
{
    int n;
    std::pair<T, T> initialPoint;
    std::vector<std::pair<T, T>> baseCoords;
};