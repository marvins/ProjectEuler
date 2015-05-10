#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/9/2015
#
#    Purpose: Build Project Euler 067 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler067_Sources
     euler067.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler067
                ${Euler067_Sources}
)

