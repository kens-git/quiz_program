#pragma once

#include <vector>
#include <string>

using std::string;
using std::vector;

using std::vector;

class ArgParser {
    public:
        vector<string> parse(int argc, char** argv);
};

