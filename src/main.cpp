#include "file.hpp"
#include "directory.hpp"

int main()
{
	fs::path path = ".";
    Directory root = walk_dir(path);
    std::cout << root << std::endl;

	return 0;
}