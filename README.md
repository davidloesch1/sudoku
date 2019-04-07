# sudoku
# I think I have the general idea for how to approach it.  
# initialize your array, by copying over each parameter provided. 

here are the actual instructions for the project;

Functions allowed:
free, malloc, write;

• Your source code will be compiled as follows: gcc -Wall -Wextra -Werror -o
rush-1 *.c
• Your submission directory must have all files required to compile your program.
• Create a program that resolves a sudoku.
• A valid sudoku has only one possible solution.
• Here’s how we’ll launch your program :
> ./rush-1 line0 line1 line2 line3 line4 line5 line6 line7 line8
• LineN represents a characters string of values ranged between ’1’ and ’9’ or ’.’ (for
empty boxes).
• Here’s an example of intended input/output for a valid sudoku.

>./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68."
".9..5.741" "47......." | cat -e

9 1 4 3 7 5 2 6 8$
2 8 7 4 9 6 1 5 3$
3 6 5 8 1 2 4 7 9$
8 4 6 5 2 1 3 9 7$
5 2 9 6 3 7 8 1 4$
7 3 1 9 8 4 5 2 6$
1 5 3 7 4 9 6 8 2$
6 9 8 2 5 3 7 4 1$ 
4 7 2 1 6 8 9 3 5$
>

• In case of error, display "Error" followed by a line break.


#initial approach would be once you create your own array with the provided parameters, using recursion, you would test each available slot in the array with a number starting with the lowest available digit that works.  then, recall the function to do the same for the next available slot.  if the next available slot has no numbers that works, then it would go back to the previous iteration and increase that slot by the next available number and then re-continue. 

you would need to develop a test function that could check to see if the newly placed digit is a allowable digit using the most current iteration of the sudoku.  if it is, great, keep going, if it is false, then that iteration of the latest array index is reset to available, and the previous slot is increased to the next digit and checked again if its allowed, if it is, continue as before, if not, then it needs to be increased again.  if that slot cycles through all the digits and there is no digit that works, then it will bump backwards to the previous iteration and try the process again.

the eventuality would be that it would either finish, or it is a non - possible sudoku.
