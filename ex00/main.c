/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 06:30:11 by lcoant--          #+#    #+#             */
/*   Updated: 2026/06/23 07:02:13 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* --- PROTOTYPE --- */
int		check_arg(char *str);
int		backtracking(int grid[4][4], int nbrs[16], int i, int j);
void	fill_tab(char *str, int nbrs[16]);
void	init_grid(int grid[4][4]);

static void	print_tab(int grid[4][4])
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
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

static void	print_error(void)
{
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	int	grid[4][4];
	int	nbrs[16];

	if (ac != 2 || !check_arg(av[1]))
	{
		print_error();
		return (1);
	}
	fill_tab(av[1], nbrs);
	init_grid(grid);
	if (backtracking(grid, nbrs, 0, 0))
	{
		print_tab(grid);
		return (0);
	}
	print_error();
	return (1);
}
