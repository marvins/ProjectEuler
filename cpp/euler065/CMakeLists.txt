#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/7/2015
#
#    Purpose: Build Project Euler 065 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler065_Sources
     euler065.cpp
     $<TARGET_OBJECTS:BigInteger>
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler065
                ${Euler065_Sources}
)


