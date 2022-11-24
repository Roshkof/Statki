cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

	add_library(Statki_core src/Statki.cpp)
	target_include_directories(Statki_core PUBLIC include)

	add_executable(Statki src/main.cpp)
	target_link_libraries(Statki Statki_core)
