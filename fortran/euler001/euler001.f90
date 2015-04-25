!  euler001.f
!  Computes the sum of integers which are multiples of 3 or 5.
!

PROGRAM Euler001
IMPLICIT none
INTEGER :: max_value, sum, I

!  Get the Max Value
max_value = 1000

!  Set sum
sum = 0

!  Iterate over range
DO I=3,999

    !  Check if a multiple of 3
    if (modulo(I,3) == 0) then
        sum = sum + I

    !  Check if a multiple of 5
    else if ( modulo(I,5) == 0) then
        sum = sum + I
    end if

end do

!  Print the Sum
print*, 'Sum:', sum

!  Exit Program
end
