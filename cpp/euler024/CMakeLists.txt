#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2015
#
#    Purpose: Build Project Euler 024 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler024_Sources
     euler024.cpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler024
                ${Euler024_Sources}
)


