#!/usr/bin/env octave -qf
%  
%    File:    euler002.m
%    Author:  Marvin Smith
%    Date:    4/25/2015
% 

%  Update Path
addpath('octave/common')

%   Summation
result = 0

%  Set our max value
max_value = 4000000

%  Get the Max Fib Number
Fmax = Find_Max_Fibonacci( max_value );

%  Iterate over fibonacci numbers
for n = (1:Fmax)

    %  Get the value
    value = Fibonacci(n)

    %  Check if the value is even
    if mod(value,2) == 0
        result += value;
    end

end

%  Print Result
fprintf('%d\n', result)

