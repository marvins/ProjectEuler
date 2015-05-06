#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/5/2015
#
#    Purpose: Build Project Euler 060 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler060_Sources
     euler060.cpp
     ../common/Primesieve.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler060
                ${Euler060_Sources}
)


