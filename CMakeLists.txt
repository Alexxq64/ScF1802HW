cmake_minimum_required(VERSION 3.10)

project(ChatApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set file permissions for Users.txt and Messages.txt
file(WRITE ${CMAKE_SOURCE_DIR}/users.txt "")
execute_process(COMMAND chmod 600 ${CMAKE_SOURCE_DIR}/users.txt)
file(WRITE ${CMAKE_SOURCE_DIR}/messages.txt "")
execute_process(COMMAND chmod 600 ${CMAKE_SOURCE_DIR}/messages.txt)

# Add executable target
add_executable(ChatApp user.cpp message.cpp main.cpp)

# Set output directory for executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

# Set executable name and location
set_target_properties(ChatApp PROPERTIES 
    OUTPUT_NAME "ChatApp"
    RUNTIME_OUTPUT_DIRECTORY "${EXECUTABLE_OUTPUT_PATH}")

# Enable debugging and all warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

# Set a build type
set(CMAKE_BUILD_TYPE Debug)
