cmake_minimum_required(VERSION 3.0.0)
project(template-vsc VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(template-vsc
  main.cpp
  generador.cpp
  generador.h
  vectores.cpp
  vectores.h
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
