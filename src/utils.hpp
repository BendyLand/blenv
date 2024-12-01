#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

using hex = unsigned char;

std::vector<std::string> split(const std::string& str, char delim);
std::string ltrim(const std::string& text);
std::string rtrim(const std::string& text);
std::string trim(const std::string& text);
void extract_path_and_name(const std::string& full_path, std::string& path, std::string& name);
std::vector<hex> read_file_as_hex(const std::string& file_path, size_t& file_size);

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
    std::cout << std::endl;
    return os;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T> vec)
{
    for (T item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return os;
}
