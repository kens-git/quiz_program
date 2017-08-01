cmake_minimum_required(VERSION 3.0)

project (unit_tests)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS system filesystem regex REQUIRED)

add_executable(${PROJECT_NAME} 
		tests.cpp
		../source/ArgParser.cpp
		../source/QuizParser.cpp
		../source/Question.cpp
		../source/Quiz.cpp
		../CSVparser/CSVparser.cpp)

include_directories(../include
		    ../CSVparser)

target_link_libraries(${PROJECT_NAME}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_REGEX_LIBRARY})
