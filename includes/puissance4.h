/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:22:07 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/08 14:50:46 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

int		error(const char *s1, char *s2);

typedef struct		s_grid
{
	int				lines;
	int				columns;
	char			**grid;
}					t_grid;

void	display_grid(t_grid *grid);
int		check_win(t_grid *grid);
void	print_start_round(int player);
void	print_win(int win);
int		error(const char *s1, char *s2);
int		rand_int(int min, int max);
void	ia_play(t_grid *grid);
int		add_to_grid(t_grid **grid, int columns, int player);
int		vertical_line(char **grid, int x, int y, int max);
int		horizontal_line(char **grid, int x, int y, int max);
int		cross1_line(char **grid, int x, int y, int max[2]);
int		cross2_line(char **grid, int x, int y, int max);
void	ft_free_tab_nb(char ***tab, int x, int y);
int		have_winer(char **tmp, int x, int y, int max[2]);

#endif /* !PUISSANCE4_H */
