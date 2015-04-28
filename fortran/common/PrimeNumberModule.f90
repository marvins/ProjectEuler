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

!  End of the Module
END MODULE PrimeNumberModule
