/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:29:20 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 14:51:29 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "puissance4.h"

static void		display_inter(t_grid *grid)
{
	int		y;

	y = 0;
	ft_putstr("tqqq");
	while (y++ < grid->columns - 1)
		ft_putstr("nqqq");
	ft_putstr("u\n");
}

static void		display_strart(t_grid *grid)
{
	int		y;

	y = 0;
	ft_putstr("  ");
	while (y < grid->columns)
	{
		ft_putnbr(y + 1);
		y++;
		ft_putstr("   ");
	}
	ft_putstr("\n\033(0\033[34m");
	ft_putstr("lqqq");
	y = 0;
	while (y++ < grid->columns - 1)
		ft_putstr("wqqq");
	ft_putstr("k\n");
}

static void		display_end(t_grid *grid)
{
	int		y;

	y = 0;
	ft_putstr("mqqq");
	while (y++ < grid->columns - 1)
		ft_putstr("vqqq");
	ft_putstr("j\033(B\033[m\n");
}

static void		display_player(char c)
{
	if (c == 'O')
		ft_putstr("\033[43m\033[33mO\033[m");
	else
		ft_putstr("\033[41m\033[31mO\033[m");
}

void			display_grid(t_grid *grid)
{
	int		x;
	int		y;

	display_strart(grid);
	x = 0;
	while (x < grid->lines)
	{
		y = 0;
		while (y < grid->columns)
		{
			ft_putstr("\033[34mx ");
			if (!grid->grid[x][y])
				ft_putchar(' ');
			else
				display_player(grid->grid[x][y]);
			ft_putchar(' ');
			y++;
		}
		ft_putstr("\033[34mx\n");
		if (x != grid->lines - 1)
			display_inter(grid);
		x++;
	}
	display_end(grid);
}
