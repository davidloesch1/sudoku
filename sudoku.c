#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int will_it_work(char array[9][9], int a, int b)
{
	/*
	loop through the other 8 entries in the row
	{
		if (value of other == value at row, column) 
		{
			return 0;
		}
	}
	loop through the other 8 entries in the column
	{
		if (value of other == value at row, column) 
		{
			return 0;
		}
	}
	loop through the other 8 entries in the grid
	{
		if (value of other == value at row, column) 
		{
			return 0;
		}
	}
	return 1;
	*/

	int i;
	int j;

	j = 0;
	i = 0;

	while(i < 9 && j < 9)
	{	
		if(array[a][b] == array[a][j] && b != j)
		{	
			return (0);
		}
		j++;

		if(array[a][b] == array[i][b] && a != i)
		{	
			return (0);
		}
		i++;
	}
	return 1;
}
int solve(char array [9][9]) 
{
	/*
	find the first empty space:
	loop through '1' - '9' {
		
		try putting that character in the empty space
		if		there's a conflict:
				keep moving on
		else:
			try calling solve(new_board with character added)
			if solve returns success:
				return success
			else (if solve returns failure):
				try the next character
	}
	if you  run out of character '1' - '9' to try:
		return failure
		*/
	int x;
	int y;
	char i;

	x = 0;
	y = 0;
	i = '1';

	while(x < 9)
	{
		if (i > '9')
		{
			return(0); /*not a solveable sodoku*/
		}
		if(array[x][y] != '.')
		{
			y++;
			if (y == 9) 
			{
				y = 0;
				x++;
			}
		}
		else if(array[x][y] == '.')
		{
			array[x][y] = i;
			if(will_it_work(array, x, y))
			{
				if(solve(array))
				{
					return(1); /*success*/
				}
				else
				{
					array[x][y] = '.';
					i++; /*try the next number*/
				}
			}
			else
			{
				array[x][y] = '.';
				i++;
			}
		}
	}
	return(1);
}

int		main(int argc, char const *argv[])
{
	int x;
	int y;
	char array[9][9];
	//char *str[] = {"1.3456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",};
	
	// array = malloc(sizeof(*array) * 82);
	x = 0;
	y = 0;
	while(x < 9)
	{
		y = 0;
		while (y < 9)
		{
			array[x][y] = argv[x + 1][y];
			y++;
		}
		x++;
	}
	//*(array + 81) = '\0';
	
	solve(array);

	x = 0;
	y = 0;
	while(x < 9)
	{
		y = 0;
		while (y < 9)
		{
			write(1, &(array[x][y]), 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}

	//printf("%s\n", array);
	return 0;
}
