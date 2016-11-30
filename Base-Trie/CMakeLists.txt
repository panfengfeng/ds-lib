project(basic_trie)
cmake_minimum_required(VERSION 3.5)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
        src/basic_trie.cpp)

add_library(basic_trie SHARED ${SOURCES})
target_link_libraries(basic_trie)

add_library(basic_trie_static STATIC ${SOURCES})
    SET_TARGET_PROPERTIES(basic_trie_static PROPERTIES OUTPUT_NAME "basic_trie")
target_link_libraries(basic_trie)

# Test

set(BENCHMARK
    benchmark/bench.cpp)
add_executable(bench ${BENCHMARK})
target_link_libraries(bench basic_trie)
