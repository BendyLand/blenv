#pragma once

#include "os.hpp"
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
        size_t idx = full_path.rfind("/");
        if (idx < 0) {
            this->path = "./";
            this->name = full_path;
        }
        else {
            this->path = full_path.substr(0, idx);
            size_t len = full_path.size() - idx;
            this->name = full_path.substr(idx+1, len);
        }
        std::string command = "xxd -i " + full_path;
        std::pair<int, std::string> result = OS::run_command(command);
        if (result.first < 0) {
            std::cerr << "Error executing command." << std::endl;
            exit(EXIT_FAILURE);
        }
        for (hex c : result.second) {
            this->contents.emplace_back(c);
            if (c == ';') break;
        }
        std::vector<std::string> words = split(result.second, ' ');
        size_t last = words.size() - 1;
        std::string num_str = words[last].substr(0, words[last].size()-1);
        try {
            this->size = static_cast<size_t>(std::stoi(num_str));
        }
        catch (std::invalid_argument _) {
            this->size = 0;
        }
    };
};