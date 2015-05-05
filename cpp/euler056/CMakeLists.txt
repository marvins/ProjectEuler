#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/4/2015
#
#    Purpose: Build Project Euler 056 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler056_Sources
     euler056.cpp
     ../common/StringUtilities.hpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler056
                ${Euler056_Sources}
)


