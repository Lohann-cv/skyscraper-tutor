// add header

# include <unistd.h>

typedef struct s_data
{
	int	grid[4][4];
	int	nbrs[16];
}	t_data;

int		check_arg(char *str);
void	fill_tab(char *str, t_data *data);
void	init_grid(t_data *data);
int     backtracking(t_data *data, int tracking, int i, int j);

static void    print_tab(t_data *data)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = data->grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

static void    print_error(void)
{
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !check_arg(av[1]))
	{
		print_error();
		return (1);
	}
	fill_tab(av[1], &data);
	init_grid(&data);
	if (backtracking(&data, 0, 0, 0))
	{
        print_tab(&data);
	    return (0);
	}
	print_error();
	return (1);
}
