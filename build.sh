#!/bin/sh

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
    make
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
    esac

done


#  If no arg given, use default
make_software

