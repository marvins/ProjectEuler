#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/4/2015
#
#    Purpose: Build Project Euler 059 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler059_Sources
     euler059.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler059
                ${Euler059_Sources}
)


