#include "directory.hpp"
#include "file.hpp"

int main()
{
	fs::path path = ".";
	Directory root = walk_dir(path);
	std::cout << root << std::endl;

	return 0;
}
