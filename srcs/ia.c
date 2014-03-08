/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:02:58 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 14:54:29 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "puissance4.h"

char	**ft_copy_tab(char **tab, int x, int y)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	new_tab = (char **)ft_memalloc(sizeof(char *) * x + 1);
	while (i < x)
	{
		new_tab[i] = (char *)ft_memalloc(sizeof(char) * y + 1);
		j = 0;
		while (j < y)
		{
			new_tab[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (new_tab);
}

int		ia_add_to_grid(char **tab, int columns, int max[2], int player)
{
	int		i;

	if (columns == 0 || columns - 1 > max[1])
		return (0);
	i = 0;
	while (i + 1 < max[0] && tab[i + 1][columns - 1] == '\0')
		i++;
	if (tab[i][columns - 1] == '\0')
		tab[i][columns - 1] = (player) ? 'X' : 'O';
	else
		return (0);
	return (1);
}

int		ia_check_win(char **tab, int max[2])
{
	int		x;
	int		y;

	x = 0;
	while (x <= max[0] - 1)
	{
		y = 0;
		while (y <= max[1])
		{
			if (vertical_line(tab, x, y, max[0])
				|| horizontal_line(tab, x, y, max[1])
				|| cross1_line(tab, x, y, max)
				|| cross2_line(tab, x, y, max[1]))
			{
				if (tab[x][y] == 'O')
					return (0);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (-1);
}

void	ia_res(t_grid *grid, int i, int max[2])
{
	int		ran;

	if (i == max[1])
	{
		ran = rand_int(1, max[1]);
		ft_putnbr(ran);
		ft_putchar('\n');
		add_to_grid(&grid, ran, 0);
		return ;
	}
	ft_putnbr(i);
	ft_putchar('\n');
	add_to_grid(&grid, i, 0);
}

void	ia_play(t_grid *grid)
{
	int		i;
	char	**tab;
	char	**tab2;
	int		max[2];

	i = 0;
	max[0] = grid->lines;
	max[1] = grid->columns;
	while (i < max[1])
	{
		tab = ft_copy_tab(grid->grid, max[0], max[1]);
		tab2 = ft_copy_tab(grid->grid, max[0], max[1]);
		if (ia_add_to_grid(tab2, i, max, 0) && ia_check_win(tab2, max) == 0)
				break ;
		if (ia_add_to_grid(tab, i, max, 1) && ia_check_win(tab, max) == 1)
				break ;
		ft_free_tab_nb(&tab, max[0], max[1]);
		ft_free_tab_nb(&tab2, max[0], max[1]);
		i++;
	}
	ia_res(grid, i, max);
}
