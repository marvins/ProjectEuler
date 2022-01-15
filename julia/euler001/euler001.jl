result = 0

for i = 1:1000
    if ( i % 3 == true ) || ( i % 5 == true )
       global result = result + i 
    end
end
println("Result: $result")