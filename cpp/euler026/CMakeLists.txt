#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2015
#
#    Purpose: Build Project Euler 026 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler026_Sources
     euler026.cpp
     ../common/Primesieve.hpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler026
                ${Euler026_Sources}
)

