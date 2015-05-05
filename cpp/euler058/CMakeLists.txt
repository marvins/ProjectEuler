#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/4/2015
#
#    Purpose: Build Project Euler 058 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler058_Sources
     euler058.cpp
     ../common/Primesieve.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler058
                ${Euler058_Sources}
)


