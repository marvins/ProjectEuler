#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/28/2015
#
#    Purpose: Build Project Euler 013 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler013_Sources
     euler013.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler013
                ${Euler013_Sources}
)

