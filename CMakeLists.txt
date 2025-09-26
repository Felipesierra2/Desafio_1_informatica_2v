cmake_minimum_required(VERSION 3.16)

project(Desafio_1_informatica_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Desafio_1_informatica_2 main.cpp
    crypto.h crypto.cpp
)

include(GNUInstallDirs)
install(TARGETS Desafio_1_informatica_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
