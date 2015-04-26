%    File:    Find_Max_Fibonacci.m
%    Author:  Marvin Smith
%    Date:    4/25/2015
%
%    Purpose:  Find the Max Fibonacci number given a max value.
%

function Fmax = Find_Max_Fibonacci( max_value )
    
    %  Start Iterating
    counter = 2;
    while (1==1) 

        %  Compute Fibonacci
        value = Fibonacci( counter )

        %  Check Result
        if value >= max_value 
            Fmax = counter-1
            break
        end

        %  Increment Counter
        counter++;
    end

end

