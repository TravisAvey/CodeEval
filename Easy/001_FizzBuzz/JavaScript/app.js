// node's file system library
var fs  = require("fs");

// This method prints out the fizz buzz
// argument : array of data 
function FizzBuzz (data)
{
    // get the variables out of the array
    var x = data[0];
    var y = data[1];
    var limit = data[2];
    // declare a string for the answer
    var answer = '';
    // loop over the numbers 1->limit
    for (var i=1; i<=limit; ++i)
    {
        // if divisible by both x and y, FIZZUBZZ
        if (i % x == 0 && i % y == 0)
            answer += "FB";
        // if only divisible by x, FIZZ
        else if (i%x == 0)
            answer += "F";
        // if divisible by y, BUZZ
        else if (i%y == 0)
            answer += "B";
        // else just output the number
        else
            answer += i.toString ();
        // put a spacer after number or fb
        answer += ' ';
    }

    // remove the last space
    answer = answer.slice (0, answer.length-1);
    // output the string
    console.log (answer);
}

// Helper method that will parse the string
// and return an array of the data
function Parse (line)
{
    // return array, split on the ' '
    return line.split(' ');
}

// grab the file passed as the argument, split on new line.  Foreach line call the function
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) 
{
    // if we have data
    if (line != "") 
    {
        // get the data array from the line
        var data = Parse(line);
        // call method that will output the fizz buzz
        FizzBuzz (data);
    }
});
