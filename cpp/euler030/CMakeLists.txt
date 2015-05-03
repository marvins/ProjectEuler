#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2015
#
#    Purpose: Build Project Euler 030 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler030_Sources
     euler030.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler030
                ${Euler030_Sources}
)


