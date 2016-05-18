#!/usr/bin/env python3

'''
    This method will print everyother number
    from x to y (not inclusive)
'''
def print_odds(x, y):
    # for each number from x -> y, counting by 2
	for i in range(x, y, 2):
        # print the number
		print(i)

# call method to print to stdout 1-99 odds
print_odds(1, 100)
