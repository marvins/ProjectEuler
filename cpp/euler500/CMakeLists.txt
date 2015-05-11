#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/8/2015
#
#    Purpose: Build Project Euler 500 C++ Example
#


#---------------------------------#
#-     Find Boost Libraries      -#
#---------------------------------#
find_package( Boost
                COMPONENTS
                    multiprecision
)
include_directories( ${Boost_INCLUDE_DIRS} )

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( Euler500_Sources
     euler500.cpp
)

#----------------------------------#
#-      Build the Executable      -#
#----------------------------------#
add_executable( euler500
                ${Euler500_Sources}
)


