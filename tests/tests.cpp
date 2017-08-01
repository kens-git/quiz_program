#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::find;

#include "ArgParser.hpp"
#include "QuizParser.hpp"

int argc = 3;
char* argv[] = { "exe_path", "25", "test1.csv" };

ArgParser testArgParser;
vector<string> filepaths = testArgParser.parse(argc, argv);

TEST_CASE("ArgParser filepath tests") {
  REQUIRE(filepaths.size() == 1);
  REQUIRE((find(filepaths.begin(), filepaths.end(), "categories/test1.csv") != filepaths.end()) == true);
}


int argc2 = 3;
char* argv2[] = { "exe_path", "25", "/test_folder" };

vector<string> filepaths2 = testArgParser.parse(argc2, argv2);

TEST_CASE("ArgParser root directory tests") {
  REQUIRE(filepaths2.size() == 3);
  REQUIRE((find(filepaths2.begin(), filepaths2.end(), "categories/test_folder/test2.csv") != filepaths2.end()) == true);
  REQUIRE((find(filepaths2.begin(), filepaths2.end(), "categories/test_folder/test3.csv") != filepaths2.end()) == true);
  REQUIRE((find(filepaths2.begin(), filepaths2.end(), "categories/test_folder/test_folder2/test4.csv") != filepaths2.end()) == true);
}


int argc3 = 3;
char* argv3[] = { "exe_path", "25", "/test_folder/test_folder2" };

vector<string> filepaths3 = testArgParser.parse(argc3, argv3);

TEST_CASE("ArgParser specific directory tests") {
  REQUIRE(filepaths3.size() == 1);
  REQUIRE((find(filepaths3.begin(), filepaths3.end(), "categories/test_folder/test_folder2/test4.csv") != filepaths3.end()) == true);
}