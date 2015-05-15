!    File:    PrimeNumberModule.f90
!    Author:  Marvin Smith
!    Date:    4/25/2015
!
!    Purpose:  Contains Prime Number Utilities.
!
MODULE PrimeNumberModule

!  Define Everything As Public
PUBLIC

!  List of Procedures in the PrimeNumber Module
CONTAINS

!  Find the Number of Primes below a given value
FUNCTION Find_Number_Primes_Below_Value (max_value) result (Pmax)
    integer, intent(in) :: max_value
    integer :: Pmax

!  Iterate over range, looking for primes


END FUNCTION


!  Find the List of Primes Below a Number
FUNCTION Prime_Sieve( max_value ) result ( prime_list )
    integer max_value, i,j,start_j
    logical, allocatable, dimension(:) :: prime_list

!  Allocate Memory
allocate( prime_list(2:max_value))

!  Initialize the array
prime_list(2:max_value) = (/(.TRUE., i=2,max_value)/)

!  Start the sieve
do i=2,max_value
    do j = (i+i), max_value, i
        prime_list(j) = .FALSE.
    end do
end do

END FUNCTION


!  End of the Module
END MODULE PrimeNumberModule
