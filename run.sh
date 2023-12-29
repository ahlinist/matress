#!/bin/bash

#Compile
#g++ -g cpp/* -o main_cpp
#g++ -g cpp_shared_ptrs/* -o main_cpp_shared_ptrs
gfortran -g -c fortran/matrix_*.f90 -J./fortran && gfortran -g -c fortran/main.f90 -J./fortran && gfortran -g -o main_fortran *.o

#Run
sh run_cpp.sh
sh run_cpp_shared_ptrs.sh
sh run_fortran.sh
