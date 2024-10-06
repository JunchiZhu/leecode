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

# Add executable for day_eight
add_executable(day_eight day_eight/day_eight.cpp
        day_twelve/day_twelve.cpp
        linkedlist.h)

# Add executable for day_nine
add_executable(day_nine day_nine/day_nine.cpp
        day_nine/day_nine.cpp)

# Add executable for day_ten
add_executable(day_ten day_ten/day_ten.cpp
        day_ten/day_ten.cpp)

# Add executable for day_eleven
add_executable(day_eleven day_eleven/day_eleven.cpp
        day_eleven/day_eleven.cpp
        treenode.h)

# Add executable for day_twelve
add_executable(day_twelve day_twelve/day_twelve.cpp
        treenode.h)

add_executable(day_thirteen day_thirteen/day_thirteen.cpp
        treenode.h
        day_thirteen/day_thirteen.cpp)

add_executable(day_fourteen day_fourteen/day_fourteen.cpp
        treenode.h
        linkedlist.h)

add_executable(day_fifteen day_fifteen/day_fifteen.cpp
        linkedlist.h)

add_executable(day_sixteen day_sixteen/day_sixteen.cpp
        linkedlist.h)

add_executable(day_seventeen_tree2 day_seventeen_tree2/day_seventeen_tree2.cpp
        treenode.h)

add_executable(day_seventeen_hash day_seventeen_hash/day_seventeen_hash.cpp
        helper.h)

add_executable(day_eighteen day_eighteen/day_eighteen.cpp
        helper.h)

add_executable(day_nineteen day_nineteen/day_nineteen.cpp
        helper.h)

add_executable(day_twenty day_twenty/day_twenty.cpp
        helper.h)

add_executable(day_twenty_one day_twenty_one/day_twenty_one.cpp
        helper.h
        stack.h
        queue.h)

add_executable(day_twenty_two day_twenty_two/day_twenty_two.cpp
        helper.h
        stack.h
        queue.h)

add_executable(day_twenty_three day_twenty_three/day_twenty_three.cpp
        helper.h
        stack.h
        queue.h)

add_executable(day_twenty_four day_twenty_four/day_twenty_four.cpp
        helper.h
        stack.h
        queue.h)

add_executable(day_twenty_five day_twenty_five/day_twenty_five.cpp
        helper.h
        stack.h
        queue.h)

add_executable(day_twenty_six day_twenty_six/day_twenty_six.cpp
        helper.h)

add_executable(day_twenty_seven day_twenty_seven/day_twenty_seven.cpp
        helper.h)

add_executable(day_twenty_eight day_twenty_eight/day_twenty_eight.cpp
        helper.h)

add_executable(day_twenty_nine day_twenty_nine/day_twenty_nine.cpp
        helper.h)

add_executable(day_thirty day_thirty/day_thirty.cpp
        helper.h)

add_executable(day_thirty_one day_thirty_one/day_thirty_one.cpp
        helper.h)

add_executable(day_thirty_two day_thirty_two/day_thirty_two.cpp
        helper.h)

add_executable(day_thirty_three day_thirty_three/day_thirty_three.cpp
        helper.h)

add_executable(day_thirty_four day_thirty_four/day_thirty_four.cpp
        helper.h)

add_executable(day_thirty_five day_thirty_five/day_thirty_five.cpp
        helper.h)

add_executable(day_thirty_six day_thirty_six/day_thirty_six.cpp
        helper.h)

add_executable(day_thirty_seven day_thirty_seven/day_thirty_seven.cpp
        helper.h)

add_executable(day_thirty_eight day_thirty_eight/day_thirty_eight.cpp
        helper.h)

add_executable(day_thirty_nine day_thirty_nine/day_thirty_nine.cpp
        helper.h)

add_executable(day_forty day_forty/day_forty.cpp
        helper.h)

add_executable(day_forty_one day_forty_one/day_forty_one.cpp
        helper.h)

add_executable(day_forty_two day_forty_two/day_forty_two.cpp
        helper.h)

add_executable(sorts sorts/sort_algorithms.cpp
        helper.h)