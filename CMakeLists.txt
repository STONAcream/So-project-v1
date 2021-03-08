cmake_minimum_required(VERSION 3.17)
project(playfair C)

set(CMAKE_C_STANDARD 99)

add_executable(playfair main.c keygen.c keygen.h readfile.h readfile.c key.h key.c codifica.h codifica.c decodifica.h decodifica.c playfair_utils.h playfair_utils.c)