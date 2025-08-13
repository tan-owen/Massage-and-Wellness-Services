cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# specify name of the project and specify which language to compile for
project(Application LANGUAGES CXX)

#-----------------------------------------------------------------------------#
# define the data path in c++
set(DATA_DIR ${PROJECT_SOURCE_DIR}/res)
set(DEST_DIR ${CMAKE_BINARY_DIR}/res)

#-----------------------------------------------------------------------------#
# list of all source files
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "${SRC_DIR}/*.hpp")
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")

#-----------------------------------------------------------------------------#
# list all files that will either be used for compilation or that should show 
# up in the ide of your choice
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC src)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11) # use c++11

#-----------------------------------------------------------------------------#
# use strict compliation
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

#-----------------------------------------------------------------------------#
# Copy data folder
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${DATA_DIR} ${DEST_DIR}
    COMMENT "Copying data folder to build directory..."
)
