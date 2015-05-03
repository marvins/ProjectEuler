#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/3115
#
#    Purpose: Build Project Euler 031 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler031_Sources
     euler031.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler031
                ${Euler031_Sources}
)


