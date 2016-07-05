using System;
using System.IO;
using System.Collections.Generic;


class Program
{
    public class Penultimate
    {
        #region MemberVariables
        
        private List<string> mWords;
        private int mNumWords;
        
        #endregion
        
        #region GetterSetter

        /// <summary>
        /// Returns the number of words in the sentence
        /// </summary>
        int WordsLength
        {
            get { return mNumWords; }
        }

        #endregion
        
        #region Constructors
        /// <summary>
        /// Constructor.  Pass in sentence to find the word in question
        /// </summary>        
        public Penultimate (string words)
        {
            Parse(words);
        }

        #endregion

        #region PrivateMethods
        
        /// <summary>
        /// Parses the string into a list of words and sets the number of words
        /// </summary>
        private void Parse(string words)
        {
            // when using Array.ConvertAll on strings, gotta use lambda expression
            mWords = new List<string>(Array.ConvertAll(words.Split(' '), e => e.ToString()));
            mNumWords = mWords.Count;
        }

        #endregion

        #region PublicMethods
        /// <summary>
        /// Returns the word from the string at index indicated
        /// </summary>
        public string GetWord()
        {
            // get the second to last index
            int i = mNumWords - 2;
            // return that word
            return mWords[i];
        }

        #endregion
    }

    public static void Main (string[] args)
    {
        // for each line in the file
        foreach (var line in File.ReadLines(args[0]))
        {
            // create a penultimate object with the line
            var penultimate = new Penultimate (line);
            // write to stdout the second to last word
            Console.WriteLine(penultimate.GetWord());
        }
    }
}