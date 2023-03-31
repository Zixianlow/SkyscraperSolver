/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:00:08 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/31 21:46:07 by lzi-xian         ###   ########.fr       */
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

void	ft_fill_max(t_sky *sky, int l)
{
	int	sum;
	int	pos;

	if (l / sky->size == 0)
	{
		sum = sky->cond[l] + sky->cond[l + sky->size];
		pos = l + (sky->cond[l] * sky->size) - sky->size;
		if (sum == sky->size + 1)
			sky->grid[pos] = sky->size;
	}
	else if (l / sky->size == 2)
	{
		sum = sky->cond[l] + sky->cond[l + sky->size];
		pos = (l - (2 * sky->size)) * sky->size + sky->cond[l] - 1;
		if (sum == sky->size + 1)
			sky->grid[pos] = sky->size;
	}
}

void	ft_prefill(t_sky *sky)
{
	int	l;

	l = 0;
	while (sky->cond[l])
	{
		if (sky->cond[l] == sky->size)
			ft_fill_in_line(sky, l);
		l++;
	}
	l = 0;
	while (sky->cond[l])
	{
		if ((l / sky->size) % 2 == 0)
			ft_fill_max(sky, l);
		l++;
	}
}
// int	row;
// int	col;
// row = pos / sky->size;
// col = pos % sky->size;
// sky->grid[row * sky->size + col] = i;
