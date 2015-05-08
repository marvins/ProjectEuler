#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/6/2015
#
#    Purpose: Build Project Euler 061 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler061_Sources
     euler061.cpp
     $<TARGET_OBJECTS:BigInteger>
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler061
                ${Euler061_Sources}
)


