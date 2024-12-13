#include "directory.hpp"
#include "file.hpp"

//todo: design binary format so that mutable section is at the end,
//todo: 	and updates work through truncation and appending.
int main(int argc, char** argv)
{
	fs::path path = ".";
	std::vector<std::string> mut_files = get_mutable_files(argc, argv);
	Directory root = walk_dir(path, mut_files);
	std::cout << root << std::endl;

	return 0;
}
