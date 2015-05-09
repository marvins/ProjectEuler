#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/8/2015
#
#    Purpose: Build Project Euler 084 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler084_Sources
     euler084.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler084
                ${Euler084_Sources}
)


