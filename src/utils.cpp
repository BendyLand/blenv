#include "utils.hpp"
#include "os.hpp"

using hex = unsigned char;

std::string generate_uuid_v4() 
{
    uuid_t uuid;
    char uuidStr[37]; // UUID string representation
    uuid_generate(uuid);
    uuid_unparse(uuid, uuidStr);
    return std::string(uuidStr);
}

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
