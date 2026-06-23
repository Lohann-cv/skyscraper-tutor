/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 06:30:23 by lcoant--          #+#    #+#             */
/*   Updated: 2026/06/23 06:32:35 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* --- STRUCT --- */
typedef struct s_data
{
	int	grid[4][4];
	int	nbrs[16];
}	t_data;

int    check_top(int grid[4][4],int nbrs[16], int j)
{
	int    i;
	int    seen;
	int    max;

	i = 0;
	seen = 0;
    max = 0;
	while (i < 4)
	{
        if (grid[i][j] > max)
		{
            max = grid[i][j];
			seen++;
		}
		i++;
	}
	if (seen == nbrs[j])
		return 1;
	return 0;
}

int    check_bot(int grid[4][4],int nbrs[16], int j)
{
	int    i;
	int    seen;
	int    max;

	i = 3;
	seen = 0;
    max = 0;
	while (i >= 0)
	{
        if (grid[i][j] > max)
		{
            max = grid[i][j];
			seen++;
		}
		i--;
	}
	if (seen == nbrs[4 + j])
		return 1;
	return 0;
}

int    check_right(int grid[4][4],int nbrs[16], int i)
{
	int    j;
	int    seen;
	int    max;

	j = 3;
	seen = 0;
	max = 0;
	while (j >= 0)
	{
		if (grid[i][j] > max)
		{
			max = grid[i][j];
			seen++;
		}
		j--;
	}
	if (seen == nbrs[12 + i])
		return 1;
	return 0;
}

int    check_left(int grid[4][4],int nbrs[16], int i)
{
	int    j;
	int    seen;
	int    max;

	j = 0;
	seen = 0;
	max = 0;
	while (j < 4)
	{
		if (grid[i][j] > max)
		{
			max = grid[i][j];
			seen++;
		}
		j++;
	}
	if (seen == nbrs[8 + i])
		return 1;
	return 0;
}
