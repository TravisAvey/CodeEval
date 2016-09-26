import sys

# This method prints the longest word in the string
def PrintLongestWord (line):
    # decalare variables
    longest = 0
    pos = 0
    # with python have to remove the newlines
    line = line.replace('\n', '')
    # create an list on the string, spliting on spaces
    words = [item for item in line.split(' ') if item]
    # for each word in the words list
    for i in range(0, len(words)):
        # if the current word is longer than longest
        if (len (words[i]) > longest):
            # set the longest to current word length
            longest = len(words[i])
            # set pos to current
            pos = i
    
    # print the longest word
    print (words[pos])

with open(sys.argv[1], 'r') as test_cases:
    for test in test_cases:
        PrintLongestWord (test)
