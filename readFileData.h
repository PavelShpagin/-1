#pragma once

#include <iostream>
#include <string>

bool isInteger(const std::string& str);

bool isDouble(const std::string& str);

template <typename T>
FileData<T> readFileData(const std::string &fileName);