#include "ArgParser.hpp"

#include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::find;

namespace fs = boost::filesystem;

vector<string> ArgParser::parse(int argc, char** argv) {
    vector<string> filepaths;
    // skip the first (executable path) and second (number of questions) arguments
    for (int i = 2; i < argc; i++) {
        fs::path tempPath(argv[i]);
        bool isDirectory;
        if (tempPath.has_extension()) {
            isDirectory = false;
        } else {
            isDirectory = true;
        }
        
        try {
            fs::recursive_directory_iterator iter;
            if (isDirectory) {
                string temp = argv[i];
                string dirPath = "categories" + temp;
                iter = fs::recursive_directory_iterator(dirPath);
            } else {
                try {
                    iter = fs::recursive_directory_iterator("categories");
                } catch (fs::filesystem_error& e) {
                    cout << e.what() << endl;
                }
            }

            fs::recursive_directory_iterator end;

            while (iter != end) {
                if (isDirectory) {
                    if (iter->path().extension() == ".csv") {
                        filepaths.push_back(iter->path().generic_string());
                    }
                } else {
                    if (iter->path().extension() == ".csv" && iter->path().filename() == argv[i]) {
                        filepaths.push_back(iter->path().generic_string());
                    }
                }
                
                boost::system::error_code ec;
                iter.increment(ec);
                if (ec) {
                    std::cerr << "Skipping entry: " << ec.message() << endl;
                }
            }
        } catch (fs::filesystem_error& e) {
            cout << "Could not find file/directory " << tempPath << endl;
        }
    }
    
    return filepaths;
}
