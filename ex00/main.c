// add header

#include "main.h"
#include <stdio.h> // a supp

int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
		}
		else
		{
			if (!(str[i] == ' '))
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	fill_tab(char *str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 16)
	{
		data->nbrs[j] = str[i] - '0';
		i += 2;
		j++;
	}
}

void	init_grid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			data->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !check_arg(av[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	fill_tab(av[1], &data);
	init_grid(&data);
	return (0);
}
