cmake_minimum_required (VERSION 3.10.2)
project(StaffDemo)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(StaffDemo_lib ${SRC_FILES}
        include/Interfaces.h
        include/Personal.h
        include/Engineer.h
        include/Factory.h
        include/Manager.h)
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

add_executable(StaffDemo ${PROJECT_SOURCE_DIR}/src/main.cpp
        include/Interfaces.h
        include/Personal.h
        include/Engineer.h
        include/Factory.h
        include/Manager.h
        )
target_link_libraries(StaffDemo StaffDemo_lib)

