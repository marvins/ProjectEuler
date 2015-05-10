#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/7/2015
#
#    Purpose: Build Project Euler 063 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler063_Sources
     euler063.cpp
     ../common/Math_Utilities.hpp
     ../common/StringUtilities.hpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler063
                ${Euler063_Sources}
)


