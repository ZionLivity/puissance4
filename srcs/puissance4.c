/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:22:14 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 14:56:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include <libft.h>
#include "puissance4.h"

t_grid	*create_grid(int lines, int columns)
{
	t_grid	*grid;

	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	if (!grid)
		return (NULL);
	if (lines < 6 || columns < 7)
	{
		error("minimum: 6 lines, 7 columns", NULL);
		return (NULL);
	}
	grid->lines = lines;
	grid->columns = columns;
	grid->grid = ft_malloc_tab(lines, columns);
	return (grid);
}

int		add_to_grid(t_grid **grid, int columns, int player)
{
	int		i;

	if (columns == 0 || columns - 1 > (*grid)->columns)
	{
		error("wrong input: ", NULL);
		return (0);
	}
	i = 0;
	while (i + 1 < (*grid)->lines && (*grid)->grid[i + 1][columns - 1] == '\0')
		i++;
	if ((*grid)->grid[i][columns - 1] == '\0')
		(*grid)->grid[i][columns - 1] = (player) ? 'O' : 'X';
	else
	{
		error("full !", NULL);
		return (0);
	}
	return (1);
}

void	ft_round(t_grid *grid, int *player)
{
	char	*line;

	line = NULL;
	print_start_round(*player);
	if (*player == 1)
	{
		get_next_line(0, &line);
		if ((add_to_grid(&grid, ft_atoi(line), *player)))
			*player = !*player;
	}
	else
	{
		ia_play(grid);
		*player = !*player;
	}
	ft_putstr("\033[m");
	if (line)
		free(line);
	display_grid(grid);
}

int		main(int argc, char const *argv[])
{
	t_grid	*grid;
	int		player;
	int		win;

	srand(time(NULL));
	if (argc != 3)
		return (error("usage: ./puissance4 [lines] [columns]", NULL));
	grid = create_grid(ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (!grid)
		return (0);
	ft_putstr("You are player \033[43m\033[33mO\033[m");
	ft_putendl(", IA is \033[41m\033[31mO\033[m");
	display_grid(grid);
	player = rand_int(0, 1);
	win = -1;
	while (1)
	{
		ft_round(grid, &player);
		win = check_win(grid);
		if (win != -1)
			break ;
	}
	ft_free_tab_nb(&(grid)->grid, grid->lines, grid->columns);
	print_win(win);
	return (0);
}
