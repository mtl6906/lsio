project(lsio)

cmake_minimum_required(VERSION 3.10)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0 -g)

aux_source_directory(src/ls/io SRC)

aux_source_directory(sample SRC_SAMPLE)

include_directories(include)

add_library(lsio SHARED ${SRC})

add_executable(testcase ${SRC_SAMPLE} ${SRC})

target_link_libraries(testcase lsbuffer lsexception)
	
install(TARGETS lsio DESTINATION lib)

install(DIRECTORY include/ls/io DESTINATION include/ls)
