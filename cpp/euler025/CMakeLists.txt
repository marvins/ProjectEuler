#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2015
#
#    Purpose: Build Project Euler 025 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler025_Sources
     euler025.cpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler025
                ${Euler025_Sources}
)


