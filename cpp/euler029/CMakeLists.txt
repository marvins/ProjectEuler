#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/2/2915
#
#    Purpose: Build Project Euler 029 C++ Example
#


#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler029_Sources
     euler029.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler029
                ${Euler029_Sources}
                $<TARGET_OBJECTS:BigInteger>
)


