#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/8/2015
#
#    Purpose: Build Project Euler 066 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler066_Sources
     euler066.cpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler066
                ${Euler066_Sources}
)


