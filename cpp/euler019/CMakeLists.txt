#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/29/2015
#
#    Purpose: Build Project Euler 019 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler019_Sources
     euler019.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler019
                ${Euler019_Sources}
)

