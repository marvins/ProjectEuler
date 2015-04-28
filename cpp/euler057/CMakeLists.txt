#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/27/2015
#
#    Purpose: Build Project Euler 057 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler057_Sources
     euler057.cpp
)

include_directories( ../common )

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler057
                ${Euler057_Sources}
                $<TARGET_OBJECTS:BigInteger>
)


