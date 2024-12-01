#include "file.hpp"
#include "directory.hpp"

int main()
{
	fs::path path = ".";
    Directory entries = walk_dir(path);
    std::cout << entries << std::endl;

	return 0;
}