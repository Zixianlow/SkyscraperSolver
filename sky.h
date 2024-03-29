/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:01:02 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 19:00:48 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKY_H
# define SKY_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_sky
{
	int		n;
	int		size;
	char	**nums;
	int		*grid;
	int		*max;
	int		*cond;
}	t_sky;

int		up_chk(t_sky *sky, int col);
int		down_chk(t_sky *sky, int col);
int		right_chk(t_sky *sky, int row);
int		left_chk(t_sky *sky, int row);
int		ft_atoi(const char *str);
int		is_safe(t_sky *sky, int pos, int num);
void	ft_fill_in_line(t_sky *sky, int l);
int		ft_number_count(char *s, t_sky *sky);
void	ft_prefill(t_sky *sky);
void	ft_print_grid(int *grid, int size);
void	ft_set_max_in_line(t_sky *sky);
char	**ft_split(const char *str, char c);
int		col_is_filled(t_sky *sky, int col);
int		row_is_filled(t_sky *sky, int row);

#endif