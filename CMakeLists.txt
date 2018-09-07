cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 11)
project(PrimeCounter C)

link_libraries(pthread)

add_executable(PrimeCounter count_primes.c)