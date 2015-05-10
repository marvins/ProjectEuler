#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/7/2015
#
#    Purpose: Build Project Euler 062 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler062_Sources
     euler062.cpp
     ../common/Math_Utilities.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler062
                ${Euler062_Sources}
)


