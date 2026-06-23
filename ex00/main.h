// add header

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>

typedef struct s_data
{
	int	grid[4][4];
	int	nbrs[16];
}	t_data;

//   PARSING   //
int		check_arg(char *str);
void	fill_tab(char *str, t_data *data);
void	init_grid(t_data *data);
int     backtracking(t_data *data, int tracking, int i, int j);

#endif
