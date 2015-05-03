#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/3/2015
#
#    Purpose: Build Project Euler 035 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler035_Sources
     euler035.cpp
     ../common/Math_Utilities.hpp
     ../common/Primesieve.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler035
                ${Euler035_Sources}
)


