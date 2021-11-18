cmake_minimum_required(VERSION 3.8)
project(tpi)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

file(GLOB DIR_TESTS_EN "test/*.cpp")

set(SOURCE_FILES
        main.cpp
        auxiliares/ej3.cpp
        auxiliares/ej4.cpp auxiliares/ej5.cpp auxiliares/ej5.h test/ejercicio5TEST.cpp auxiliares/ej6.cpp auxiliares/ej6.h test/ejercicio6TEST.cpp auxiliares/ej7.h auxiliares/ej7.cpp test/ejercicio7TEST.cpp auxiliares/ej9.cpp auxiliares/ej9.h test/ejercicio9TEST.cpp auxiliares/ej10.cpp auxiliares/ej10.h test/ejercicio10TEST.cpp auxiliares/ej14.cpp auxiliares/ej14.h test/ejercicio14TEST.cpp auxiliares/ej16.cpp auxiliares/ej16.h test/ejercicio16TEST.cpp auxiliares/ej17.cpp auxiliares/ej17.h test/ejercicio17TEST.cpp auxiliares/ej18.cpp auxiliares/ej18.h test/ejercicio18TEST.cpp)

add_executable(p9 ${SOURCE_FILES}
        ${DIR_TESTS_EN}
        )

set(CMAKE_CXX_FLAGS "-g --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(p9 gtest gtest_main)
