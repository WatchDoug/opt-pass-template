cmake_minimum_required(VERSION 3.4.3)

if(APPLE)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif(APPLE)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")



add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fPIC -Wall -std=c++14")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fPIC -Wall -std=c++11 -fsanitize=address")


#llvm_map_components_to_libnames(llvm_libs support core irreader all)


add_subdirectory(src)

#target_link_libraries(FP ${llvm_libs})

if(APPLE)
    set_target_properties(libgsfpi PROPERTIES
            LINK_FLAGS "-undefined dynamic_lookup"
        )
endif(APPLE)
