cmake_minimum_required(VERSION 3.10)
project(clusters VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include/)
include_directories(.)

add_executable(${PROJECT_NAME} main.cpp kMeans.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Установка флагов компиляции для Debug сборки
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Установка флагов компиляции для Release сборки
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
