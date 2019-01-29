cmake_minimum_required(VERSION 3.1.0)

# project name
project(civsimul VERSION 1.0 LANGUAGES CXX)

# project sources
file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE HEADER src/*.h)

# Qt 5
find_package(Qt5Widgets CONFIG REQUIRED)
if(Qt5Widgets_FOUND)
    # project executable
    add_executable(civsimul ${SRC} ${HEADER})
    # link Qt
    target_link_libraries(civsimul Qt5::Widgets)
else()
    message("Erreur Qt library not found")
endif()
