#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

/*
    Armstrong number is an n-digit number equal to the sum of the nth powers of its digits
    
    6 : 6^1 = 6
    1634 : 1^4 + 6^4 + 3^4 + 4^4 = 1634
*/

void ArmstrongNumber(int, int);
void GetDigits(std::vector<int> &, int);
int SumOfPowers(std::vector<int> &, int);

int main (int argc, char *argv[])
{
    // open file
    std::fstream file(argv[1], std::ios::in);
    // check if opened
    if (file)
    {
        // get each line store in string
        std::string data;
        while (std::getline(file, data))
            // Check if armstrong number
            ArmstrongNumber(std::stoi(data), data.length());
        
    }
    // close file
    file.close();
    return 0;
}


/*
    This method checks if the number is an Armstrong Number
    Outputs True if it is, or False if not
*/
void ArmstrongNumber(int num, int len)
{
    // declare a vector to hold each digit
    std::vector<int> numbers;
    // get each digit from number
    GetDigits(numbers, num);
    // get the result of the sum of the powers
    int result = SumOfPowers(numbers, len);
    // if num == result ? armstrongNumber : not
    if (num == result)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

/*
    This method gets each digit from the number 
    and puts in a vector
*/
void GetDigits(std::vector<int> &nums, int n)
{
 
    // while n is still greater than 0
    while (n > 0)
    {
        // put in the last digit of the number
        nums.push_back(n%10);
        // effectively remove last digit ( 15 / 10 = 1.5 :: n is an int so 1)
        n /= 10;
    }
}

/*
    This method returns the sum of power of each digit
*/
int SumOfPowers(std::vector<int> &nums, int y)
{
    // init the sum
    int sum = 0;
    
    // for each digit in the vector
    for (auto i : nums)
    {
        // get the power of current digit ^ lenght of number
        int power = std::pow(i, y);
        // add to sum
        sum += power;
    }
    // return the sum
    return sum;
}
