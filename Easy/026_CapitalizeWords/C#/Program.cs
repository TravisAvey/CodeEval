using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    public class Capital
    {
        // Member variables
        private List<string> mWords;
        private int mLength;
        private string mSentence;

    
        /// <summary>
        /// Set the sentence to captialize
        /// </summary>
        public string Sentence
        {
            set 
            { 
                mSentence = value;
                Parse (mSentence);
            }
        }

        // private methods

        /// <summary>
        /// Converts the string into a list of words
        /// </summary>
        private void Parse (string line)
        {
            mWords = new List<string>(Array.ConvertAll(line.Split(' '), e => e.ToString()));
            mLength = mWords.Count;
        }

        /// <summary>
        /// Helper method to replace each word with a capitalized version
        /// </summary>
        private string ReplaceWord(string word)
        {
            // cache the first letter
            var ch = word[0];
            // if not a letter, return the word
            if (ch < 'a' || ch > 'z') return word;

            // return the word with the first letter captialized
            return char.ToUpper(word[0]) + word.Substring(1);

        }

        // public methods

        /// <summary>
        /// returns the sentence passed to constructor
        /// now with each word capitalized
        /// </summary>
        public string Capitalize ()
        {
            // initiliaze an empty string
            string capital = "";

            // for each word, append the capitalized word to string
            foreach (var word in mWords)
                capital += ReplaceWord(word) + ' ';
            
            // return said string
            return capital;
        }
    }

    public static void Main (string[] args)
    {
        var capital = new Capital();
        
        // foreach line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // set the sentence
            capital.Sentence = line;            
            // write to stdout the capitalized sentence
            Console.WriteLine(capital.Capitalize());
        }
    }
}