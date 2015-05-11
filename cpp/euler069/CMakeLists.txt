#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/10/2015
#
#    Purpose: Build Project Euler 069 C++ Example
#

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler069_Sources
     euler069.cpp
     ../common/Math_Utilities.hpp
     ../common/Primesieve.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler069
                ${Euler069_Sources}
)


