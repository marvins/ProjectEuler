#!/usr/bin/env octave -qf
%  
%    File:    euler001.m
%    Author:  Marvin Smith
%    Date:    4/25/2015
% 

%   Summation
result = 0

%   Iterate from 3 to 999
for x = (3:999)

    %  Check if value divisible
    if mod(x,3) == 0 || mod(x,5) == 0
        result += x;
    end
end

%  Print Result
fprintf('%d\n', result)

