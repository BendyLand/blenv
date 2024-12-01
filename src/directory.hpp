#pragma once

#include <string>
#include <vector>
#include "file.hpp"

class Directory
{
public:
    std::string name;
    std::vector<File> files;
    std::vector<Directory> subdirs;

    Directory(const std::string& n) : name(n) {}
    Directory(const std::string& n, std::vector<File> f) 
        : name(n), files(f) 
    {}
    Directory(const std::string& n, std::vector<File> f, std::vector<Directory> d) 
        : name(n), files(f), subdirs(d) 
    {}
};

Directory walk_dir(const fs::path& dir_path);

inline std::ostream& operator<<(std::ostream& os, const Directory dir)
{
    std::cout << "Directory: " << dir.name << std::endl;
    std::cout << "Files:" << std::endl;
    for (File file : dir.files) {
        std::cout << file << std::endl;
    }

    std::cout << "Subdirectories:" << std::endl;
    for (Directory dir : dir.subdirs) {
        std::cout << dir << std::endl;
    }

    return os;
}