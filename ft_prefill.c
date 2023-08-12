/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:00:08 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 18:53:04 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

void	ft_max_horizontal(t_sky *sky, int sum, int pos, int l)
{
	sum = sky->cond[l] + sky->cond[l + sky->size];
	pos = (l - (2 * sky->size)) * sky->size + sky->cond[l] - 1;
	if (sum == sky->size + 1)
		sky->grid[pos] = sky->size;
	if (sky->cond[l] == 1)
	{
		sky->grid[(l % sky->size) * sky->size] = sky->size;
		if (sky->cond[l + sky->size] == 2)
			sky->grid[(l % sky->size) * sky->size + sky->size - 1]
				= sky->size - 1;
	}
	if (sky->cond[l + sky->size] == 1)
	{
		sky->grid[(l % sky->size) * sky->size + sky->size - 1] = sky->size;
		if (sky->cond[l] == 2)
			sky->grid[(l % sky->size) * sky->size] = sky->size - 1;
	}
}

void	ft_max_verticle(t_sky *sky, int sum, int pos, int l)
{
	sum = sky->cond[l] + sky->cond[l + sky->size];
	pos = l + (sky->cond[l] * sky->size) - sky->size;
	if (sum == sky->size + 1)
		sky->grid[pos] = sky->size;
	if (sky->cond[l] == 1)
	{
		sky->grid[l] = sky->size;
		if (sky->cond[l + sky->size] == 2)
			sky->grid[l + sky->size * (sky->size - 1)] = sky->size - 1;
	}
	if (sky->cond[l + sky->size] == 1)
	{
		sky->grid[l + sky->size * (sky->size - 1)] = sky->size;
		if (sky->cond[l] == 2)
			sky->grid[l] = sky->size - 1;
	}
}

void	ft_fill_max(t_sky *sky, int l)
{
	int	sum;
	int	pos;

	if (l / sky->size == 0)
		ft_max_verticle(sky, sum, pos, l);
	else if (l / sky->size == 2)
		ft_max_horizontal(sky, sum, pos, l);
}

void	ft_prefill(t_sky *sky)
{
	int	l;

	l = -1;
	while (sky->cond[++l])
	{
		if (sky->cond[l] == sky->size)
			ft_fill_in_line(sky, l);
	}
	l = -1;
	while (sky->cond[++l])
	{
		if ((l / sky->size) % 2 == 0)
			ft_fill_max(sky, l);
	}
}

// int	row;
// int	col;
// row = pos / sky->size;
// col = pos % sky->size;
// sky->grid[row * sky->size + col] = i;
