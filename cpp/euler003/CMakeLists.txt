#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/25/2015
#
#    Purpose: Build Project Euler 003 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler003_Sources
     euler003.cpp
     Primesieve.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler003
                ${Euler003_Sources}
)

