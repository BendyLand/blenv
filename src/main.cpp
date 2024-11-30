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
        std::cout << "Contents: " << test.contents << std::endl;
        std::cout << "Size: " << test.size << std::endl << std::endl;
    }

	return 0;
}
