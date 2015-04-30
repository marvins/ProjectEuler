#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/28/2015
#
#    Purpose: Build Project Euler 014 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler014_Sources
     euler014.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler014
                ${Euler014_Sources}
)

