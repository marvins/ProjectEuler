#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2015
#
#    Purpose: Build Project Euler 028 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler028_Sources
     euler028.cpp
     ../common/Primesieve.hpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler028
                ${Euler028_Sources}
)

