project(simple_trie)
cmake_minimum_required(VERSION 3.5)
include_directories(${PROJECT_SOURCE_DIR}/include)

# main source code
set(SOURCES
    src/simple_trie.cpp)

add_library(simple_trie SHARED ${SOURCES})
target_link_libraries(simple_trie)

add_library(simple_trie_static STATIC ${SOURCES})
set_target_properties(simple_trie_static PROPERTIES OUTPUT_NAME "simple_trie")
target_link_libraries(simple_trie)

# tools(cmd) source code
set(TOOLS
        tools/build.cpp
        tools/lookup.cpp)

set(EXES ${TOOLS})

foreach(sourcefile ${EXES})
    string(REPLACE ".cpp" "" exename ${sourcefile})
    string(REGEX REPLACE "^((.+)/)+" "" exename ${exename})
    add_executable(${exename} ${sourcefile})
    target_link_libraries(${exename} simple_trie)
endforeach(sourcefile ${EXES})
    
# test source code
#set(TEST
#        benchmark/simple_trie_test.cpp)
#add_executable(simple_trie_test ${TEST})
#target_link_libraries(simple_trie_test simple_trie)
