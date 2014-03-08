/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:56:23 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 14:15:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_tab(int x, int y)
{
	char	**tab;
	int		i;

	tab = (char **)ft_memalloc(sizeof(char *) * x);
	i = 0;
	while (i < x)
	{
		tab[i] = ft_memalloc(sizeof(char) * y);
		i++;
	}
	return (tab);
}
