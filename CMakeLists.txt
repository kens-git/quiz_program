cmake_minimum_required(VERSION 3.0)

project (quiz)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS system filesystem regex REQUIRED)

file(GLOB sources "source/*.cpp")

add_executable(quiz main.cpp 
                ${sources}
                CSVparser/CSVparser.cpp)

target_include_directories(quiz PUBLIC include CSVparser)

target_link_libraries(quiz
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_REGEX_LIBRARY})
