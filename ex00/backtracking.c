/* DONT FORGET 42 HEADER*/

#include "main.h"

static int    checker(t_data *data)
{
	if (/*All check function called */)
		return 1;
    return 0;
}

int    backtracking(t_data *data, int tracking, int i, int j)
{
	int    number;

	number = 1;
	if (tracking == 16)
		return 1;
	if (i > 3)
	{
		i = 0;
		j++;
	}
	while (number < 4)
	{
        if (checker(data))
		{
			data->grid[i][j] = number;
			if (backtracking(data, tracking + 1, i + 1, j) == 1)
				return 1;
		}
		number++;
	}
	return 0;
}
