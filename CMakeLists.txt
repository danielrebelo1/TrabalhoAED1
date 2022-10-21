cmake_minimum_required(VERSION 3.23)
project(aedtp1)

set(CMAKE_CXX_STANDARD 14)

add_executable(aedtp1
        Code/main.cpp Code/Menu.cpp Code/Menu.h Code/FileReader.cpp Code/FileReader.h Code/Turma.h Code/Turma.cpp Code/Student.cpp Code/Student.h Code/Slot.cpp Code/Slot.h)