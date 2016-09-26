var fs  = require("fs");

/*
    This method prints the longest word in the line
*/
function PrintLongestWord (line)
{
    // split the line into an array of words
    var words = line.split(' ');

    // init variables
    var longest = 0;
    var pos = 0;
    // loop through words array
    for (var i=0; i<words.length; ++i)
    {
        // if the current word's length is greater than the longest
        if (words[i].length > longest)
        {
            // set the longest to the current word's length
            longest = words[i].length;
            // set the position to the current
            pos = i;
        }
    }
    // output the longest word
    console.log (words[pos]);
}

fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) 
{
    if (line != "")
    {
        PrintLongestWord (line);
    }
});
