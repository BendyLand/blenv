#include "directory.hpp"
#include "os.hpp"

Directory walk_dir(const fs::path& dir_path) 
{
    if (!fs::exists(dir_path) || !fs::is_directory(dir_path)) {
        std::cerr << "Invalid directory." << std::endl;
        exit(EXIT_FAILURE);
    }
    Directory current_dir(dir_path.string());
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        if (fs::is_directory(entry)) {
            // Recursively process subdirectories
            current_dir.subdirs.emplace_back(walk_dir(entry.path()));
        } 
        else if (fs::is_regular_file(entry)) {
            // Add file to the current directory
            current_dir.files.emplace_back(entry.path().string());
        }
    }
    return current_dir;
}
