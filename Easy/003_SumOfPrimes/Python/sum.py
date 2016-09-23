#!/usr/bin/env python3

'''
    This method checks if the number 
    is a prime number or not
'''
def IsPrime (n):
    
    # loop from 2 to n (exclusive)
    for i in range (2, n):
        # if n is divisible by i, then we dont have a prime number
        if (n % i == 0):
            return False
    # if we get here, the number is prime
    return True

'''
    This method returns the sum of the first x number
    of prime numbers, where x = limit
'''
def Prime (limit):

    # declare variables
    count, result = 0, 0
    # we will start at 2, because 0 & 1 are not primes
    i = 2

    # while the count is less than the limit
    while (count < limit):
        # check if current number is a prime
        if (IsPrime (i)):
            # if prime, then add to result
            result += i
            # increment the number of primes
            count += 1
        # go to the next number
        i+=1
    
    # return the sum of limit number of primes
    return result
    
# print to stdout the sum of the first 1000 prime numbers
print (Prime(1000))


