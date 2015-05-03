#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2015
#
#    Purpose: Build Project Euler 034 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler034_Sources
     euler034.cpp
     ../common/Math_Utilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler034
                ${Euler034_Sources}
)


