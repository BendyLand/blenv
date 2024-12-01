#include "utils.hpp"
#include "os.hpp"

using hex = unsigned char;

std::string ltrim(const std::string& text)
{
    size_t pos = text.find_first_not_of(" \r\n\t");
    if (pos < 0) return text;
    size_t len = text.size() - pos + 1;
    std::string result = text.substr(pos, len);
    return result;
}

std::string rtrim(const std::string& text)
{
    size_t pos = text.find_last_not_of(" \r\n\t");
    if (pos < 0) return text;
    std::string result = text.substr(0, pos+1);
    return result;
}

std::string trim(const std::string& text)
{
    size_t pos_start = text.find_first_not_of(" \r\n\t");
    size_t pos_end = text.find_last_not_of(" \r\n\t");
    std::string result = text;
    if (pos_start >= 0) result = ltrim(result);
    if (pos_end >= 0) result = rtrim(result);
    return result;
}

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
