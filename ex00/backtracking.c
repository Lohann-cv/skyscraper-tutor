/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 06:30:45 by lcoant--          #+#    #+#             */
/*   Updated: 2026/06/23 06:33:04 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* --- STRUCT --- */
typedef struct s_data
{
	int	grid[4][4];
	int	nbrs[16];
}	t_data;

/* --- PROTOTYPE --- */
int    check_top(int grid[4][4], int nbrs[16], int j);
int    check_bot(int grid[4][4], int nbrs[16], int j);
int    check_right(int grid[4][4], int nbrs[16], int i);
int    check_left(int grid[4][4], int nbrs[16], int i);

static int    is_double(int grid[4][4], int i, int j)
{
	int    k;

	k = 0;
	while (k < 4)
	{
		if (k != i)
		{
            if (grid[i][j] == grid[k][j])
				return 1;
		}
		if (k != j)
		{
            if (grid[i][j] == grid[i][k])
				return 1;
		}
		k++;
	}
	return 0;
}

static int    checker(int grid[4][4], int nbrs[16], int i, int j)
{
	if (is_double(grid, i, j))
		return 0;
	if (i == 3)
	{
        if (!check_top(grid, nbrs, j) || !check_bot(grid, nbrs, j))
			return 0;
	}
	if (j == 3)
	{
	    if (!check_right(grid, nbrs, i) || !check_left(grid, nbrs, i))
			return 0;
	}	
    return 1;
}

int    backtracking(int grid[4][4], int nbrs[16], int i, int j)
{
	int    number;

	number = 1;
	if (j == 4 && i == 3)
		return 1;
	if (j > 3)
	{
		j = 0;
		i++;
	}
	while (number <= 4)
	{
		grid[i][j] = number;
        if (checker(grid, nbrs, i, j))
		{
			if (backtracking(grid, nbrs, i, j + 1) == 1)
				return 1;
		}
		grid[i][j] = 0;
		number++;
	}
	return 0;
}
