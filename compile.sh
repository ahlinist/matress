#!/bin/bash

#Compile
g++ -g cpp/* -o main_cpp
g++ -g cpp_unique_ptrs/* -o main_cpp_unique_ptrs
gfortran -g -c fortran/matrix_*.f90 -J./fortran && gfortran -g -c fortran/main.f90 -J./fortran && gfortran -g -o main_fortran *.o
