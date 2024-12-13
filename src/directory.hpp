#pragma once

#include <string>
#include <vector>
#include "file.hpp"
#include "os.hpp"
#include "utils.hpp"

class Directory
{
public:
    // Fields
    std::string name;
    std::vector<File> files;
    std::vector<Directory> subdirs;

    // Constructors
    Directory(const std::string& n) : name(n) {}
    Directory(const std::string& n, std::vector<File> f) 
        : name(n), files(f) 
    {}
    Directory(const std::string& n, std::vector<File> f, std::vector<Directory> d) 
        : name(n), files(f), subdirs(d) 
    {}
};

Directory walk_dir(const fs::path& dir_path, const std::vector<std::string>& mut_files);

inline void collect_files(const Directory& dir, std::vector<File>& immutable_files, std::vector<File>& mutable_files)
{
    // Collect files from the current directory
    for (const auto& file : dir.files) {
        if (file.is_mutable) mutable_files.emplace_back(file);
        else immutable_files.emplace_back(file);
    }
    // Recurse into subdirectories
    for (const auto& subdir : dir.subdirs) {
        collect_files(subdir, immutable_files, mutable_files);
    }
}

inline std::ostream& operator<<(std::ostream& os, const Directory& dir)
{
    std::vector<File> immutable_files;
    std::vector<File> mutable_files;

    // Collect files from the entire directory tree
    collect_files(dir, immutable_files, mutable_files);
    os << "Directory: " << dir.name << std::endl;
    os << "Immutable Files:\n" << std::endl;
    for (const auto& file : immutable_files) {
        os << file << std::endl;
    }
    os << "Mutable Files:\n" << std::endl;
    for (const auto& file : mutable_files) {
        os << file << std::endl;
    }
    return os;
}
