/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 22:38:21 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 14:56:19 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "puissance4.h"

int		vertical_line(char **grid, int x, int y, int max)
{
	int		i;

	i = 0;
	if (x + 4 > max || grid[x][y] == '\0')
		return (0);
	while (i < 4 && grid[x + i][y] == grid[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		horizontal_line(char **grid, int x, int y, int max)
{
	int		i;

	i = 0;
	if (y + 4 > max || grid[x][y] == '\0')
		return (0);
	while (i < 4 && grid[x][y + i] == grid[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		cross1_line(char **grid, int x, int y, int max[2])
{
	int		i;

	i = 0;
	if (y + 4 > max[1] || x + 4 > max[0] ||
		grid[x][y] == '\0')
		return (0);
	while (i < 4 && grid[x + i][y + i] == grid[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		cross2_line(char **grid, int x, int y, int max)
{
	int		i;

	i = 0;
	if (y + 4 > max || x - 4 < 0 || grid[x][y] == '\0')
		return (0);
	while (i < 4 && grid[x - i][y + i] == grid[x][y])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		check_win(t_grid *grid)
{
	int		x;
	int		y;
	int		max[2];
	char	**tmp;

	x = 0;
	max[0] = grid->lines;
	max[1] = grid->columns;
	tmp = grid->grid;
	while (x < grid->lines)
	{
		y = 0;
		while (y <= grid->columns)
		{
			if (have_winer(tmp, x, y, max))
			{
				if (grid->grid[x][y] == 'O')
					return (0);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (-1);
}
