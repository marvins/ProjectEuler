#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/3/2015
#
#    Purpose: Build Project Euler 037 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler037_Sources
     euler037.cpp
     ../common/Math_Utilities.hpp
     ../common/Primesieve.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler037
                ${Euler037_Sources}
)


