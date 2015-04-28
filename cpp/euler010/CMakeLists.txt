#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/27/2015
#
#    Purpose: Build Project Euler 010 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler010_Sources
     euler010.cpp
     Primesieve.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler010
                ${Euler010_Sources}
)

