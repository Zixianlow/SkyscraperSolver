/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_max_in_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:50:44 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/31 22:06:51 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

void	ft_max_in_line(t_sky *sky, int i)
{
	int	h_min;
	int	v_min;

	h_min = i;
	v_min = i;
	while (h_min % sky->size != 0)
		h_min--;
	while (v_min / sky->size != 0)
		v_min -= sky->size;
	i = 0;
	while (i < sky->size)
	{
		sky->max[h_min] = 1;
		h_min++;
		i++;
	}
	i = 0;
	while (i < sky->size)
	{
		sky->max[v_min] = 1;
		v_min += sky->size;
		i++;
	}
}

void	ft_set_max_in_line(t_sky *sky)
{
	int	i;

	i = 0;
	while (i < sky->n)
	{
		if (sky->grid[i] == sky->size)
			ft_max_in_line(sky, i);
		i++;
	}
}
