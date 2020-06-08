#!/bin/bash

#----------------------------#
#-       Global Flags       -#
#----------------------------#
NUM_THREADS_FLAG=0
NUM_THREADS=1
CMAKE_ARGS=''

#--------------------------------#
#-        Clean Software        -#
#--------------------------------#
clean_software(){

    #  Clean Software
    echo '-> Cleaning Software'
    rm -r release

}

#---------------------------------#
#-       Build Directory         -#
#---------------------------------#
build_module(){

    #  Get the Module
    MODULE=$1

    #  Create the directory
    mkdir -p $MODULE
    
    #  Enter the directory
    pushd $MODULE

    #  Run CMake 
    cmake ../../$MODULE
    if [ ! "$?" = '0' ]; then
        echo 'Error with CMake. Aborting.'
        exit 1
    fi

    #  Run Make
    make -j${NUM_THREADS}
    if [ ! "$?" = '0' ]; then
        echo 'Error with Make. Aborting.'
        exit 1
    fi

    #  Exit the directory
    popd

}

#---------------------------------#
#-       Make the software       -#
#---------------------------------#
make_software(){
    
    #  Create release directory
    mkdir -p release/cpp
    mkdir -p release/fortran

    #  Enter Release
    pushd release
    
    #  Build CPP
    build_module cpp

    #  Build Fortran
    build_module fortran
    
    #  Exit Release
    popd
    
}

#--------------------------------------------------#
#-     Iterate through Command-Line Arguments     -#
#--------------------------------------------------#
for ARG in "$@"; do

    case $ARG in
        
        #  Clean Code
        '-c'|'--clean')
            clean_software
            exit 0
            ;;
        
        #  Build Software
        '-m'|'--make')
            make_software
            exit 0
            ;;

        #  Set number of threads
        '-j')
            NUM_THREADS_FLAG=1
            ;;

        #  Set debugging
        '-d') 
            CMAKE_ARGS="$CMAKE_ARGS -DCMAKE_BUILD_TYPE=Debug"
            ;;

        #  Parse other args
        *)
            
            #  Check if Num Threads flag requested
            if [ "$NUM_THREADS_FLAG" = '1' ]; then
                NUM_THREADS_FLAG=0
                NUM_THREADS=$ARG

            # Otherwise, error
            else
                echo "error: Unknown argument ($ARG)"
                exit 1
            fi
    esac

done


#  If no arg given, use default
make_software

