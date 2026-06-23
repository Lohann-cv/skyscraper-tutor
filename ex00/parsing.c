/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 06:30:36 by lcoant--          #+#    #+#             */
/*   Updated: 2026/06/23 06:32:12 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_data
{
	int	grid[4][4];
	int	nbrs[16];
}	t_data;

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

void	fill_tab(char *str, int nbrs[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 16)
	{
		nbrs[j] = str[i] - '0';
		i += 2;
		j++;
	}
}

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
