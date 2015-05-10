#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/8/2015
#
#    Purpose: Build Project Euler 080 C++ Example
#

#--------------------------------#
#-     Boost Multiprecision     -#
#--------------------------------#
find_package( Boost
                COMPONENTS
                    multiprecision
             )
include_directories( ${Boost_INCLUDE_DIRS})

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler080_Sources
     euler080.cpp
     ../common/StringUtilities.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler080
                ${Euler080_Sources}
)


