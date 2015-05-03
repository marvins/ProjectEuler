#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/3/2015
#
#    Purpose: Build Project Euler 039 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler039_Sources
     euler039.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler039
                ${Euler039_Sources}
)


