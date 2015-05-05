#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/4/2015
#
#    Purpose: Build Project Euler 055 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler055_Sources
     euler055.cpp
     ../common/StringUtilities.hpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler055
                ${Euler055_Sources}
)


