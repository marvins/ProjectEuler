#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/27/2015
#
#    Purpose: Build Project Euler 022 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler022_Sources
     euler022.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler022
                ${Euler022_Sources}
)


