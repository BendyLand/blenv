#pragma once

#include "os.hpp"
#include "utils.hpp"

using hex = unsigned char;

void extract_path_and_name(const std::string& full_path, std::string& path, std::string& name);
std::vector<hex> read_file_as_hex(const std::string& file_path, size_t& file_size);

class File
{
public:
    std::string name;
    std::string path;
    std::string key;
    std::vector<hex> contents;
    bool is_mutable;
    size_t size;
    File(const std::string& full_path) 
    {
        extract_path_and_name(full_path, this->path, this->name);
        this->key = this->name + "_" + generate_uuid_v4();
        this->contents = read_file_as_hex(full_path, this->size);
        this->is_mutable = false;
    };
    File(const std::string& full_path, bool is_mut) 
    {
        extract_path_and_name(full_path, this->path, this->name);
        this->key = this->name + "_" + generate_uuid_v4();
        this->contents = read_file_as_hex(full_path, this->size);
        this->is_mutable = is_mut;
    };
};

std::vector<std::string> get_mutable_files(int argc, char** argv);

inline std::ostream& operator<<(std::ostream& os, const File file)
{
    std::string full_path;
#if OS_UNIX_LIKE_DEFINED
    full_path = file.path + "/" + file.name;
#else
    full_path = file.path + "\\" + file.name;
#endif
    std::string mut = file.is_mutable ? "mutable" : "immutable";
    std::cout << "Key: " << file.key << " (" << mut << ")" << std::endl;
    std::cout << "Path: " << full_path << " (" << file.size << ")" << std::endl;
    std::cout << "Contents:\n" << file.contents << std::endl;

    return os;
}