/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:57:38 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 14:33:08 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "puissance4.h"

int			error(const char *s1, char *s2)
{
	ft_putstr_fd("puissance4: \033[31m", 2);
	if (!s2)
	{
		ft_putendl_fd(s1, 2);
		ft_putstr_fd("\033[m", 2);
	}
	else
	{
		ft_putstr_fd(s1, 2);
		ft_putstr_fd("\033[m", 2);
		ft_putendl_fd(s2, 2);
	}
	return (-42);
}

void		ft_free_tab_nb(char ***tab, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	if (i < y)
	{
		j = 0;
		while (j < x)
		{
			free((*tab)[j]);
			(*tab)[j] = NULL;
			j++;
		}
		free(*tab);
		*tab = NULL;
		i++;
	}
}

int			have_winer(char **tmp, int x, int y, int max[2])
{
	if (vertical_line(tmp, x, y, max[0])
		|| horizontal_line(tmp, x, y, max[1])
		|| cross1_line(tmp, x, y, max)
		|| cross2_line(tmp, x, y, max[1]))
	{
		return (1);
	}
	return (0);
}

int			rand_int(int min, int max)
{
	int		ran;

	ran = rand() % ((max + 1) - min) + min;
	return (ran);
}
