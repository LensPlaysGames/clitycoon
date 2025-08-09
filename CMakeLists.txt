cmake_minimum_required(VERSION 3.14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(project_clitycoon LANGUAGES CXX)

add_executable(clitycoon src/clioptions.cpp src/main.cpp)
target_include_directories(clitycoon PUBLIC src)

# Copy compile commands to top level so language servers can find it
add_custom_target(language_server_helper ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR})
add_dependencies(clitycoon language_server_helper)
