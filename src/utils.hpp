#pragma once

#include <vector>
#include <iostream>
#include<string>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<std::string> split(std::string str, char delim);
void walk_dir(const fs::path& dir_path, std::vector<std::string>& file_names);