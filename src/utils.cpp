#include "utils.hpp"

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> result;
    std::string temp = "";
    for (char c : str) {
        if (c == delim) {
            result.push_back(temp);
            temp = "";
            continue;
        }
        temp += c;
    }
    if (temp.size() > 0) result.push_back(temp);
    return result;
}

void walk_dir(const fs::path& dir_path, std::vector<std::string>& file_names) 
{
    if (!fs::exists(dir_path) || !fs::is_directory(dir_path)) {
        std::cerr << "Invalid directory: " << dir_path << "\n";
        return;
    }
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        file_names.emplace_back(entry.path().string());
        if (fs::is_directory(entry)) {
            walk_dir(entry, file_names); // Recursive call for subdirectory
        }
    }
}