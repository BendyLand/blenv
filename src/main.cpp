#include "file.hpp"

int main()
{
	fs::path path = ".";
	std::vector<std::string> names;
	walk_dir(path, names);
    for (std::string name : names) {
        File test(name);
        std::cout << "Name: " << test.name << std::endl;
        std::cout << "Path: " << test.path << std::endl;
        std::cout << "Contents:" << std::endl;
        for (auto c : test.contents) {
            std::cout << c;
        }
        std::cout << std::endl;
        std::cout << "Size: " << test.size << std::endl << std::endl;
    }

	return 0;
}
