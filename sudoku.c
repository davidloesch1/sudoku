#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char const *argv[])
{
	int x;
	int y;
	char *array;
	char *str[] = {"123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",};
	
	array = malloc(sizeof(*array) * 91);
	x = 0;
	y = 0;
	while(x < 9)
	{	
		while(str[x][y] != '\0')
		{
			*array = str[x][y];
			y++;
		}
		*array = '\n';
		array++;
		y = 0;
		x++;
	}
	*array = '\0';
	printf("%s\n", array);
	return 0;
}
