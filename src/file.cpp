#include "file.hpp"

std::vector<hex> parse_contents(const std::string& contents)
{
    std::string temp;
    std::regex reg(R"(\{([^}]*)\})");
    std::smatch matches;
    std::sregex_iterator begin = std::sregex_iterator(contents.begin(), contents.end(), reg);
    std::sregex_iterator end = std::sregex_iterator();
    for (std::sregex_iterator it = begin; it != end; it++) {
        std::string text = (*it)[1].str();
        temp = text;
    }
    std::vector<std::string> chars = split(temp, ',');
    std::vector<hex> result;
    result.reserve(chars.size());
    for (std::string c : chars) {
        c = trim(c);
        c = c.substr(2, 2);
        hex value = (hex)std::stoi(c, nullptr, 16);
        result.emplace_back(value);
    }
    return result;
}