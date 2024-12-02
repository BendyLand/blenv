#pragma once

#include "utils.hpp"
#include "os.hpp"

using hex = unsigned char;

void extract_path_and_name(const std::string& full_path, std::string& path, std::string& name);
std::vector<hex> read_file_as_hex(const std::string& file_path, size_t& file_size);

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

inline std::ostream& operator<<(std::ostream& os, const File file)
{
    std::string full_path;
#if OS_UNIX_LIKE_DEFINED
    full_path = file.path + "/" + file.name;
#else
    full_path = file.path + "\\" + file.name;
#endif
    std::cout << "File: " << full_path << " (" << file.size << ")" << std::endl;
    std::cout << "Contents:\n" << file.contents << std::endl;

    return os;
}