# MakkajaiTest
Description of the code is as follows:

This code starts with the Class - GameOfLife, having 4 private members.
Members are:
Coords: For storing coordinates of live cells
matrix: For Storing First set of live matrix
matrix: for storing the copy of the matrix
The class contains 1 private method getNeighbour(), for getting the count of live members of any specific cell

The class further contains 2 public functions:
getInput(): To take input from user in pair of coordinates of live cells.
performOneTick(): This method performs the one tick on the matrix formed from the coordinates.

The program starts with the main function. The main function creates the object, g1, of class GameOfLife.
g1, then calls getInput() and then performOneTick()

Input:
  I Have taken the dynamic input using a while loop. So to end the input we have to press Ctrl + D
  Input is taken in the pair of 2, that is the coordinates of the live cells in the universe.
Output:
  The output is the State of the Universe after one tick, that is after an iteration on the matrix.
