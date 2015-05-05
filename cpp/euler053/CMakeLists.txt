#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/4/2015
#
#    Purpose: Build Project Euler 053 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler053_Sources
     euler053.cpp
     ../common/StringUtilities.hpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler053
                ${Euler053_Sources}
)


