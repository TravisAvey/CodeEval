using System;
using System.IO;
using System.Linq;

class LowerCase
{
    class Lower
    {
        ///<summary>
        /// Returns the string in lower case
        ///</summary>    
        public string ToLower(string word)
        {
            string loweredWord = "";
            foreach (char ch in word)
                loweredWord += GetLower(ch);
            return loweredWord;
        }

        /// <summar>
        /// Returns the char in lowercase
        /// </summary>
        private char GetLower(char c)
        {
            // if the char is in between A-Z, return lowered version
            if (c >= 'A' && c <= 'Z')
                return (char)(c+32);
            else
                return c;
        }
    }

    public static void Main (string[] args)
    {
        // for each line in the file
        foreach (string line in File.ReadLines(args[0]))
        {
            // init a new lower object
            Lower lower = new Lower();

            // write to stdout the lin in lower case
            Console.WriteLine(lower.ToLower(line));
        }
    }
}
