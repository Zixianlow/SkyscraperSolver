/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_in_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:49:07 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 18:53:06 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

void	ft_fill_verticle(t_sky *sky, int l)
{
	int	i;
	int	pos;

	i = 1;
	if (l / sky->size == 0)
	{
		pos = l;
		while (i <= sky->size)
		{
			sky->grid[pos] = i ;
			i++;
			pos += sky->size;
		}
	}
	else if (l / sky->size == 1)
	{
		pos = l - sky->size;
		i = sky->size;
		while (i >= 1)
		{
			sky->grid[pos] = i;
			i--;
			pos += sky->size;
		}
	}
}

void	ft_fill_horizontal(t_sky *sky, int l)
{
	int	i;
	int	pos;

	i = 1;
	if (l / sky->size == 2)
	{
		pos = (l - (2 * sky->size)) * sky->size;
		while (i <= sky->size)
		{
			sky->grid[pos] = i;
			i++;
			pos++;
		}
	}
	else if (l / sky->size == 3)
	{
		pos = (l - (3 * sky->size)) * sky->size;
		i = sky->size;
		while (i >= 1)
		{
			sky->grid[pos] = i;
			i--;
			pos++;
		}
	}
}

void	ft_fill_in_line(t_sky *sky, int l)
{
	if (l / sky->size < 2)
		ft_fill_verticle(sky, l);
	else if (l / sky->size < 4)
		ft_fill_horizontal(sky, l);
}
