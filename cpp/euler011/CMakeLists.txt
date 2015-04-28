#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/27/2015
#
#    Purpose: Build Project Euler 011 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler011_Sources
     euler011.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler011
                ${Euler011_Sources}
)

