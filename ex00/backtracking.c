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
int    check_top(t_data *data, int j);
int    check_bot(t_data *data, int j);
int    check_right(t_data *data, int i);
int    check_left(t_data *data, int i);

static int    is_double(t_data *data, int i, int j)
{
	int    k;

	k = 0;
	while (k < 4)
	{
		if (k != i)
		{
            if (data->grid[i][j] == data->grid[k][j])
				return 1;
		}
		if (k != j)
		{
            if (data->grid[i][j] == data->grid[i][k])
				return 1;
		}
		k++;
	}
	return 0;
}

static int    checker(t_data *data, int i, int j)
{
	if (is_double(data, i, j))
		return 0;
	if (i == 3)
	{
        if (!check_top(data, j) || !check_bot(data, j))
			return 0;
	}
	if (j == 3)
	{
	    if (!check_right(data, i) || !check_left(data, i))
			return 0;
	}	
    return 1;
}

int    backtracking(t_data *data, int tracking, int i, int j)
{
	int    number;

	number = 1;
	if (tracking == 16)
		return 1;
	if (j > 3)
	{
		j = 0;
		i++;
	}
	while (number <= 4)
	{
		data->grid[i][j] = number;
        if (checker(data, i, j))
		{
			if (backtracking(data, tracking + 1, i, j + 1) == 1)
				return 1;
		}
		data->grid[i][j] = 0;
		number++;
	}
	return 0;
}
