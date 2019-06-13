cmake_minimum_required(VERSION 2.8)

project(CppConfig)

set(CMAKE_CXX_STANDARD 11)

# *.h
include_directories(source)
include_directories(example)
# - jsoncpp
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../jsoncpp/include")

# sources
file(GLOB EXAMPLE "${PROJECT_SOURCE_DIR}/example/*.*")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/source/*.*")


add_executable(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/main.cpp"
    ${SOURCES}
    ${EXAMPLE})

# libs
#  - static link to jsoncpp
target_link_libraries(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/../jsoncpp/lib/libjsoncpp.a")
