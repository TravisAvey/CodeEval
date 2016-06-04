#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> GetDigits(int);
bool SquareOfDigits(int);

int main(int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // if file is opened
    if (file)
    {
        // get each line
        std::string line;
        while(std::getline(file, line))
        {
            // call method to find if number is happy or not
            bool happy = SquareOfDigits(std::stoi(line));
            // output the bool (1||0)
            std::cout << happy << std::endl;
        }
    }
    
    // close file
    file.close();
    return 0;
}

/*
    This method takes in a number and returns
    t/f if number is happy: square the digits and add
    them up->if == 1 happy, else if we go (guessing > 20)
    then num not happy
*/
bool SquareOfDigits(int num)
{
    // short circuit this method, if already 1 return true
    if (num == 1) return true;
    
    // copy number
    int n = num;
    // init a counter
    int count = 0;
    // ?? not sure about 20 iterations to find if num == happy or not
    while (count <20)
    {
        // init a sum
        int sum = 0;
        // call method that puts each digit into a vector
        std::vector<int> digits = GetDigits(n);
        // square each digit and add to sum
        for (int i : digits)
            sum += i * i;
        
        // if the sum is 1, happy!
        if (sum == 1) return true;
        // place sum into n
        n = sum;
        // increment counter
        count++;
    }
    
    // we got here, number not happy
    return false;
}

/*
    This method takes in a number and takes
    each digit and places into a vector
    123 -> vector { 3, 2, 1}
    (if want in order, reverse this vector)
*/
std::vector<int> GetDigits(int val)
{
    // declare vector
    std::vector<int> digits;
    
    // while val > 0, divide value by 10 each iteration
    for ( ; val > 0; val /= 10)
        // put the last digit into the vector
        digits.push_back(val%10);
    
    // return vector
    return digits;
    
    /*
        How this works
        ==============
        num = 123
        
        1) push back num % 10
          - this puts in 3
          - divide num by 10, num is 12 (still greater than 0)
        2) push back num % 10
          - this puts in 2
          - divide by 10, num is 1 (still greater than 0)
        3) push back num % 10
          - this puts in 1
          - divide by 10 (num would be 0.1) num is 0: done with for loop
    */
}
