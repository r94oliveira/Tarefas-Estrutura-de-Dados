cmake_minimum_required(VERSION 3.21)
project(ed2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ed2
        main.c
        t_time.c
        t_time.h
        t_timetable.c
        t_timetable.h)
