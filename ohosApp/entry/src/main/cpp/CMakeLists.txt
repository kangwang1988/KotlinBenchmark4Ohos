# the minimum version of CMake.
cmake_minimum_required(VERSION 3.5.0)
project(KotlinBenchmark4Ohos)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(DEFINED PACKAGE_FIND_FILE)
    include(${PACKAGE_FIND_FILE})
endif()
include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

#message(FATAL_ERROR ${CMAKE_CURRENT_LIST_DIR})

add_library(entry SHARED napi_init.cpp)
target_link_directories(entry PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../libs/${OHOS_ARCH})
target_link_libraries(entry PUBLIC libace_napi.z.so libTBKMP.so)