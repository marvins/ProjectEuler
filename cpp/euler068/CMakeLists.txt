#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/8/2015
#
#    Purpose: Build Project Euler 068 C++ Example
#

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler068_Sources
     euler068.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler068
                ${Euler068_Sources}
)


