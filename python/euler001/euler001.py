#!/usr/bin/env python


#-----------------------------#
#-       Main Function       -#
#-----------------------------#
def main():
    
    #  Define the sum
    result = 0

    #  Iterate over range
    for i in xrange(3,1000):
        if i % 3 == 0 or i % 5 == 0:
            result += i
	
  	#  Print the Result
    print(result)

if __name__ == '__main__':
    main()

