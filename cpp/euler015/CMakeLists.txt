#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/28/2015
#
#    Purpose: Build Project Euler 015 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler015_Sources
     euler015.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler015
                ${Euler015_Sources}
)

