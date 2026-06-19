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

int	main(int ac, char **av)
{
	// t_data	data;

	if (ac != 2 || !check_arg(av[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	return	(0);
}
