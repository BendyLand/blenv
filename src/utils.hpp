#pragma once

#include <vector>
#include <iostream>
#include<string>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<std::string> split(const std::string& str, char delim);
void walk_dir(const fs::path& dir_path, std::vector<std::string>& file_names);

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