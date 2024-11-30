#pragma once

#include "utils.hpp"
#include <regex>

using hex = unsigned char;

std::vector<hex> parse_contents(const std::string& contents);

class File
{
public:
    std::string name;
    std::string path;
    std::vector<hex> contents;
    size_t size;
    File(const std::string& full_path) 
    {
        extract_path_and_name(full_path, this->path, this->name);
        this->contents = read_file_as_hex(full_path, this->size);
    };
};
