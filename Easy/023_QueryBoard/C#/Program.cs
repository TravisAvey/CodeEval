using System;
using System.IO;
using System.Text.RegularExpressions;

class Program
{
    public class Board
    {
        // private board
        private int[,] mBoard;

        /// <summary>
        /// Public constructor, intis a multi array of [256][256]
        public Board()
        {
            mBoard = new int[256, 256];
        }

        /// <summary>
        /// Inserts into the board the value at the row passed
        /// </summary>
        public void InsertRow(int row, int val)
        {
            for (int i=0; i<256; ++i)
                mBoard[row, i] = val;
        }

        /// <summary>
        /// Insert into the board the value at the column 
        public void InsertCol(int col, int val)
        {
            for (int i=0; i<256; ++i)
                mBoard[i, col] = val;
        }

        /// <summary>
        /// Sum the row at passed row
        /// </summary>
        public int SumRow(int row)
        {
            int sum = 0;
            for (int i=0; i<256; ++i)
                sum += mBoard[row, i];
            return sum;
        }

        /// <summary>
        /// Sum the col at the passed col
        /// </summary>
        public int SumCol(int col)
        {
            int sum = 0;
            for (int i=0; i<256; ++i)
                sum += mBoard[i, col];
            return sum;
        }
    }

    
    public static void Main (string[] args)
    {
        // init a new board
        Board board = new Board();
        
        foreach (var line in File.ReadLines(args[0]))
        {
            // get the line into an array
            string[] data = Regex.Split(line, @"\W+");
            // get the instructions
            string ins = data[0];
            // declare, column, row, and value
            int col;
            int row;
            int val;

            // check the instructions, and conduct the specified instructions
            switch (ins)
            {
                case "SetCol":
                    col = int.Parse( data[1] );
                    val = int.Parse( data[2] );
                    
                    board.InsertCol(col, val);
                break;
                case "SetRow":
                    row = int.Parse( data[1] );
                    val = int.Parse( data[2] );
                    
                    board.InsertRow(row, val);
                break;
                case "QueryCol":
                    col = int.Parse( data[1] );
                    
                    Console.WriteLine ( board.SumCol(col) );
                break;
                case "QueryRow":
                    row = int.Parse( data[1] );
                    
                    Console.WriteLine ( board.SumRow(row) );
                break;
            }
            
        }
    }
}