#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/29/2016
#
#    Purpose: Build Project Euler 016 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler016_Sources
     euler016.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler016
                ${Euler016_Sources}
)

