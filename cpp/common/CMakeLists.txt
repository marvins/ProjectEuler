#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/29/2015
#
#    Purpose: Build common C++ Utilities
#

#--------------------------------------------#
#-     Define our Big Integer Libraries     -#
#--------------------------------------------#
set( BigInteger_SOURCES 
     BigInteger.cc
     BigInteger.hh
     BigIntegerUtils.cc
     BigIntegerUtils.hh
     BigUnsigned.cc
     BigUnsigned.hh
     BigUnsignedInABase.cc
     BigUnsignedInABase.hh
)


#-------------------------------#
#-      Create the Library     -#
#-------------------------------#
add_library( BigInteger OBJECT
             ${BigInteger_SOURCES}
)

