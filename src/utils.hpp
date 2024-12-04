#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <uuid/uuid.h>
#include <vector>

namespace fs = std::filesystem;

using hex = unsigned char;

std::string generate_uuid_v4();
std::vector<std::string> split(const std::string& str, char delim);
std::string ltrim(const std::string& text);
std::string rtrim(const std::string& text);
std::string trim(const std::string& text);

template <typename T>
inline std::string join(const std::vector<T>& vec, const std::string& delim) 
{
    std::string result = "";
    size_t size = vec.size();
    for (size_t i = 0; i < size; i++) {
        result += vec[i];
        if (i < size-1) result += delim;
    }
    return result;
}

inline std::ostream& operator<<(std::ostream& os, const std::vector<hex> vec)
{
    for (hex item : vec) {
        std::cout << item;
    }
    std::cout << std::endl << "EOF" << std::endl;
    return os;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T> vec)
{
    for (T item : vec) {
        std::cout << item << std::endl;
    }
    return os;
}
