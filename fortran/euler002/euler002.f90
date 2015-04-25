!    file:    euler002.f90
!    author:  Marvin Smith
!    date:    4/25/2015
!
!    Purpose:  Solves Project Euler 002 using Fortran 90
!

PROGRAM Euler002
    USE FibonacciModule
    IMPLICIT none
    INTEGER :: sum, counter, temp_value, max_fib_number, Fmax

!  Set running sum (Start with 2 as that is automatic)
sum = 2

!  Define the max value to find fibonacci numbers for
max_fib_number=4000000

!  Find the max Fn such that it is closest but less than max
Fmax = Find_Max_Fibonacci( max_fib_number )

!  Start Iterating over Fibonacci Values
do counter = 2, Fmax

    !  Call the fibonacci number for the current counter
    temp_value = Fibonacci(counter)
    
    !  Check if it is even
    if (MODULO(temp_value,2) == 0) then
        sum = sum + temp_value
    endif

end do

!  Print the Sum
print*, 'Sum:', sum

!  Exit Program
end



