!    File:    Fibonacci.f90
!    Author:  Marvin Smith
!    Date:    4/25/2015
!
!    Purpose: Contains some Fibonacci utilities written in Fortran.
!
!    Fibonacci Module
MODULE FibonacciModule

!  Define Everything As Public
PUBLIC

!  List of Procedures in the Fibonacci Module
CONTAINS

!   Recursive Fibonacci Function
RECURSIVE FUNCTION Fibonacci (n) result (fnum)
     integer, intent(in) :: n
     integer :: fnum

    !  Handle Exit Conditions
    if (n<2) then
        fnum = n
    
    !  Handle Normal Conditions
    else
        fnum = Fibonacci(n-1) + Fibonacci(n-2)

    endif
end function Fibonacci


!   Find the Max Fibonacci Number given Max Value
FUNCTION Find_Max_Fibonacci (max_value) result (Fmax)
    integer, intent(in) :: max_value
    integer :: Fmax, I, val


!  Start iterating
I = 2
Fmax = I
do

    !  Compute the Fibonacci Number
    val = Fibonacci(I)

    !  Check if we are at the max number
    if ( val >= max_value ) then
        EXIT
    endif

    !  Increment the Counter
    Fmax = I
    I = I + 1

END DO
END FUNCTION

!   End of the Module
END MODULE FibonacciModule

