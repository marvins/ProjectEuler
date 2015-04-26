%    File:    Fibonacci.m
%    Author:  Marvin Smith
%    Date:    4/25/2015
%
%    Purpose:  Perform the fibonacci operation
%

function result = Fibonacci(F)

    persistent fib_table;

    %  Check if fib table is empty
    if isempty(fib_table)
        fib_table = cell(1,2);
        fib_table{1,1} = 1;
        fib_table{1,2} = 2;
    end

    % Check Exit Conditions
    if F < 3
        result = fib_table{1,F};

    %  Check if value already solved
    else if size(fib_table)(2) >= F && isnumeric(fib_table{1,F}) == 1 
        result = fib_table{1,F};
       
    %  Standard method
    else
        fib_table{1,F} = Fibonacci(F-1) + Fibonacci(F-2);
        result = fib_table{1,F};
    end

end

