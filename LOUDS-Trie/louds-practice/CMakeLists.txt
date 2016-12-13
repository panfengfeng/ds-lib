project(louds)
cmake_minimum_required(VERSION 3.5)
include_directories(${PROJECT_SOURCE_DIR}/include)


# Test

set(BENCHMARK
    benchmark/benchsbv.cpp)
add_executable(benchsbv ${BENCHMARK})
