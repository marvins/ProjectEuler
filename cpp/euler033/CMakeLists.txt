#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/3315
#
#    Purpose: Build Project Euler 033 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler033_Sources
     euler033.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler033
                ${Euler033_Sources}
)


