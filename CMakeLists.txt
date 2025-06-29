cmake_minimum_required(VERSION 3.10)
project(cod2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Singleplayer executable
add_executable(CoD2SP_s unix/unix_main.cpp)

# Multiplayer executable  
add_executable(CoD2MP_s unix/unix_main.cpp)

# Dedicated server executable
add_executable(cod2_lnxded unix/unix_main.cpp)