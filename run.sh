#!/bin/bash

#Compile
g++ -g cpp/* -o main_cpp
g++ -g cpp_shared_ptrs/* -o main_cpp_shared_ptrs
gfortran -g fortran/* -o main_fortran

#Run
sh run_cpp.sh
sh run_cpp_shared_ptrs.sh
sh run_fortran.sh
