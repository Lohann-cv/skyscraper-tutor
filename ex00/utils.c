/*42*/
#include "main.h"

int    check_top(t_data *data, int j)
{
	int    i;
	int    seen;
	int    max;

	i = 0;
	seen = 0;
    max = 0;
	while (i < 4)
	{
        if (data->grid[i][j] > max)
		{
            max = data->grid[i][j];
			seen++;
		}
		i++;
	}
	if (seen == data->nbrs[j])
		return 1;
	return 0;
}

int    check_bot(t_data *data, int j)
{
	int    i;
	int    seen;
	int    max;

	i = 3;
	seen = 0;
    max = 0;
	while (i >= 0)
	{
        if (data->grid[i][j] > max)
		{
            max = data->grid[i][j];
			seen++;
		}
		i--;
	}
	if (seen == data->nbrs[4 + j])
		return 1;
	return 0;
}

int    check_right(t_data *data, int i)
{
	int    j;
	int    seen;
	int    max;

	j = 3;
	seen = 0;
	max = 0;
	while (j >= 0)
	{
		if (data->grid[i][j] > max)
		{
			max = data->grid[i][j];
			seen++;
		}
		j--;
	}
	if (seen == data->nbrs[12 + i])
		return 1;
	return 0;
}

int    check_left(t_data *data, int i)
{
	int    j;
	int    seen;
	int    max;

	j = 0;
	seen = 0;
	max = 0;
	while (j < 4)
	{
		if (data->grid[i][j] > max)
		{
			max = data->grid[i][j];
			seen++;
		}
		j++;
	}
	if (seen == data->nbrs[8 + i])
		return 1;
	return 0;
}
