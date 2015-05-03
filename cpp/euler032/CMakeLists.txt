#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/3215
#
#    Purpose: Build Project Euler 032 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler032_Sources
     euler032.cpp
     ../common/Permutation_Engine.hpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler032
                ${Euler032_Sources}
)


