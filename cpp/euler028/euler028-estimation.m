#!/usr/bin/env octave -qf

%  Define our inputs
x = [  3    5    7];
y = [ 24   76  160];

%  create our system of equations to solve
A = [  x(1,1)^2  x(1,1)  1;
       x(1,2)^2  x(1,2)  1;
       x(1,3)^2  x(1,3)  1];

%  Define our solution
b = [ y(1,1);
      y(1,2);
      y(1,3)];

%  Compute output
A\b

