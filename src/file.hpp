#pragma once

#include "utils.hpp"

using hex = unsigned char;

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
#if defined(OS_UNIX_LIKE)
    full_path = file.path + "/" + file.name;
#else
    full_path = file.path + "\\" + file.name;
#endif
    std::cout << "\nFile: " << full_path << " (" << file.size << ")" << std::endl;
    std::cout << "Contents:\n" << file.contents << std::endl;

    return os;
}