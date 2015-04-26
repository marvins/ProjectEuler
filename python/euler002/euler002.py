#!/usr/bin/env python

#---------------------------------#
#-    Fibonacci Lookup Table     -#
#---------------------------------#
fib_table = {0:0, 1:1, 2:1, 3:2}

#---------------------------------#
#-    Compute Fibonacci Value    -#
#---------------------------------#
def Fibonacci( F ):
    
    #  Check exit
    if F < 2:
        return F

    #  Check for item already answered
    if F in fib_table:
        return fib_table[F]

    #  Otherwise, update the table
    fib_table[F] = Fibonacci(F-1) + Fibonacci(F-2)
    
    #  Return
    return fib_table[F]

#----------------------------------#
#-    Find Max Fibonacci Value    -#
#----------------------------------#
def Find_Max_Fibonacci( max_value ):
	
    #  Iterate until you hit the max
    counter = 2
    Fmax = counter
    while True:
			
        #  Update Fmax
        Fmax = counter-1

        #  Check Fibonacci
        if Fibonacci(counter) >= max_value:
            return Fmax

        #  Increment
        counter += 1

#--------------------------#
#-     Main Function      -#
#--------------------------#
def main():

    #  Max value
    max_value = 4000000

    #  Find the Max Fib Number
    Fmax = Find_Max_Fibonacci(max_value)

    #  Iterate
    result = 0
    for x in xrange(0,Fmax+1):
        
        #  Compute value
        value = Fibonacci(x)

        #  Check if even
        if value % 2 == 0:
            result += value

    print result

if __name__ == '__main__':
	main()


