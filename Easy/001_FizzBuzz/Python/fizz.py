#!/usr/bin/env python3

from sys import argv

'''
    This method prints out the fizz buzz 
    of numbers of 1 to the limit 
'''
def FizzBuzz(fizz, buzz, limit):
    # declare a string
    output = ""
    # loop through each number up to limit
    for i in range(1, limit+1):
        # if num is divisible by fizz and buzz, append FB
        if i%fizz == 0 and i%buzz ==0:
            output += "FB "
        # if divisible by fizz, append F
        elif i%fizz == 0:
            output += "F "
        # if divisible by buzz, append B
        elif i%buzz == 0:
            output += "B "
        # all else, append the number (not divisble by fizz or buzz)
        else:
            output += str(i) + " "
    # output the results
    print (output)

# with the file open for reading
with open(argv[1], 'r') as file:
    # for each line in the file
    for line in file:
        # split the line into a list
        data = line.split()
        # call the method to print the fizz buzz
        FizzBuzz(int(data[0]), int(data[1]), int(data[2]))
