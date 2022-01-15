
function Fibonacci( x, y )
        x + y
end

max_value = 4000000

result = 0

x1 = 0
x2 = 1
value = 2
count = 0
while value < max_value
    global value = Fibonacci( x1, x2 )
    global x1 = x2
    global x2 = value
    if value % 2 == 0
        global result = result + value
    end
end
println("Result: $result")