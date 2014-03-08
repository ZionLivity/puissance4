/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:37:39 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 11:40:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "puissance4.h"

void	print_start_round(int player)
{
	ft_putstr("Player: ");
	if (player == 0)
		ft_putstr("\033[41m\033[31mO\033[m\033[31m");
	else
		ft_putstr("\033[43m\033[33mO\033[m\033[33m");
	ft_putstr(": ");
}

void	print_win(int win)
{
	if (win != -1)
	{
		ft_putstr("player: ");
		if (win == 0)
			ft_putstr("\033[43m\033[33mO\033[m");
		else
			ft_putstr("\033[41m\033[31mO\033[m");
		ft_putendl(" WIN !");
	}
}
