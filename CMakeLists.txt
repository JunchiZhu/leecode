cmake_minimum_required(VERSION 3.27)
project(leecode)

set(CMAKE_CXX_STANDARD 14)

# Add executable for day_one
add_executable(day_one day_one/day_one.cpp)

# Add executable for day_two
add_executable(day_two day_two/day_two.cpp)

# Add executable for day_three
add_executable(day_three day_three/day_three.cpp)
add_executable(day_three_recursive day_three/recursive_test.cpp)

# Add executable for day_four
add_executable(day_four day_four/day_four.cpp)


# Add executable for day_six
add_executable(day_six day_six/day_six.cpp)

# Add executable for day_seven
add_executable(day_seven day_seven/day_seven.cpp)