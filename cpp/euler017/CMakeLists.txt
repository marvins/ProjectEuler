#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/29/2017
#
#    Purpose: Build Project Euler 017 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler017_Sources
     euler017.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler017
                ${Euler017_Sources}
)

