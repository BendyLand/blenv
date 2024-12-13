#include "directory.hpp"

Directory walk_dir(const fs::path& dir_path, const std::vector<std::string>& mut_files) 
{
    if (!fs::exists(dir_path) || !fs::is_directory(dir_path)) {
        std::cerr << "Invalid directory." << std::endl;
        exit(EXIT_FAILURE);
    }
    Directory current_dir(dir_path.string());
    std::vector<File> mutable_files;
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        if (fs::is_directory(entry)) {
            // Recursively process subdirectories
            current_dir.subdirs.emplace_back(walk_dir(entry.path().string(), mut_files));
        } 
        else if (fs::is_regular_file(entry)) {
            // Add file to the current directory
            bool is_mut = {
                contains(mut_files, entry.path().string()) || 
                contains(mut_files, fs::relative(entry.path(), dir_path).string())
            };
            if (is_mut) {
                mutable_files.emplace_back(File(entry.path().string(), true));
            }
            else {
                current_dir.files.emplace_back(entry.path().string());
            }
        }
    }
    for (const auto& entry : mutable_files) {
        current_dir.files.emplace_back(entry);
    }
    return current_dir;
}
