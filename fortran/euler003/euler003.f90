!    file:    euler003.f90
!    author:  Marvin Smith
!    date:    4/25/2015
!
!    Purpose:  Solves Project Euler 003 using Fortran 90
!

PROGRAM Euler003
    USE PrimeNumberModule
    IMPLICIT none
    INTEGER :: max_prime_factor, i
    LOGICAL, ALLOCATABLE, DIMENSION(:) :: prime_list

!  Set original
max_prime_factor = 600851475143/2

!  Allocate Memory
ALLOCATE( prime_list(2:max_prime_factor ))

!  Generate Prime Factors
prime_list = Prime_Sieve( max_prime_factor )

!  Start Iterating Over Prime Factors of the output



!  Exit Program
end



