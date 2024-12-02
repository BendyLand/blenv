#include "file.hpp"

std::vector<hex> read_file_as_hex(const std::string& file_path, size_t& file_size) 
{
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << file_path << std::endl;
        exit(EXIT_FAILURE);
    }
    file.seekg(0, std::ios::end);
    file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<hex> buffer(file_size);
    file.read(reinterpret_cast<char*>(buffer.data()), file_size);
    return buffer;
}

void extract_path_and_name(const std::string& full_path, std::string& path, std::string& name) 
{
    size_t pos = full_path.find_last_of("/\\");
    if (pos == std::string::npos) {
    #if OS_UNIX_LIKE_DEFINED
        path = "./";
    #else
        path = ".\\";
    #endif
        name = full_path;
    } 
    else {
        path = full_path.substr(0, pos);
        name = full_path.substr(pos+1);
    }
}
