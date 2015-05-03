#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/3/2015
#
#    Purpose: Build Project Euler 038 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler038_Sources
     euler038.cpp
     ../common/Math_Utilities.hpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler038
                ${Euler038_Sources}
)


