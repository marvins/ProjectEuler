#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2015
#
#    Purpose: Build Project Euler 027 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler027_Sources
     euler027.cpp
     ../common/Primesieve.hpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler027
                ${Euler027_Sources}
)

