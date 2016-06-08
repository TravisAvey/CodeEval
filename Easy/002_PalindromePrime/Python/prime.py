#!/usr/bin/env python3

'''
    This method creates a sieve of boolean
    values
'''
def Sieve(max):
    # init a list
    s = {}
    # loop through the list, setting all to true
    for i in range(0, max+1):
        s[i] = True
    
    # 0 & 1 are not primes
    s[0] = False
    s[1] = False
    
    # set the rest nonprimes to false
    for i in range(2, int(max/2)):
        for j in range(i*i, max, i):
            s[j] = False
    # return the sieve        
    return s

'''
    This method finds the highest palindrome in the
    set of prime numbers passed to method
'''
def Palindrome(primes, max):
    # var to hold highest
    hi = 0
    # loop through each in list
    for i in range(0, max+1):
        # if current is a prime number
        if primes[i] == True:
            # declares some variables
            n = i
            num = n
            reverse = 0
            digit = 0
            # while num is greater than 0, we still have digits
            # to pop off the back of the number
            while (num > 0):
                # pop the last digit off the number
                digit = int(num % 10)
                # add to the reverse
                reverse = int(reverse * 10 + digit)
                # divide the number by 10
                num = int(num / 10)
            # if the n is same as reverse and highest so far
            if n == reverse and n > hi:
                # set the hi
                hi = n
    # return the highest palindrome
    return hi

prime = Sieve(1000)
print (Palindrome(prime, 1000))
