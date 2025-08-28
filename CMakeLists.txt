# Minimum CMake version required to configure this project
cmake_minimum_required(VERSION 3.20)
# Define the project name and languages used
project(IDJ LANGUAGES CXX)

# Emit compile_commands.json for IDEs and tooling (clangd, VS Code, etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build the executable from the source files
add_executable(idj ./src/main.cpp)
# Require C++17 features for this target
target_compile_features(idj PRIVATE cxx_std_17)

# Find SDL2 and companion libraries (installed via Homebrew paths provided at configure time)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
# Link the executable against SDL2 core and the selected extension libraries
target_link_libraries(idj PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf SDL2_mixer::SDL2_mixer)
