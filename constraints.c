/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:04:03 by nsyazril          #+#    #+#             */
/*   Updated: 2023/03/31 19:57:23 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int	up_chk(t_sky *sky, int col)
{
	int	r;
	int	col_sight;
	int	r_tall;

	col_sight = 1;
	r = 0;
	r_tall = 0;
	while (++r < sky->size)
	{
		if (sky->grid[r_tall * sky->size + col] < sky->grid[r * sky->size + col])
		{
			r_tall = r;
			col_sight++;
		}
	}
	if (sky->cond[col] == col_sight)
	{
		return (1);
	}
	else
		return (0);
}

int	down_chk(t_sky *sky, int col)
{
	int	r;
	int	col_sight;
	int	r_tall;

	col_sight = 1;
	r = sky->size - 1;
	r_tall = sky->size - 1;
	while (--r >= 0)
	{
		if (sky->grid[r_tall * sky->size + col] < sky->grid[r * sky->size + col])
		{
			r_tall = r;
			col_sight++;
		}
	}
	if (sky->cond[col + sky->size] == col_sight)
		return (1);
	else
		return (0);
}

int	right_chk(t_sky *sky, int row)
{
	int	c;
	int	row_sight;
	int	c_tall;

	row_sight = 1;
	c = sky->size - 1;
	c_tall = sky->size - 1;
	while (--c >= 0)
	{
		if (sky->grid[row * sky->size + c_tall] < sky->grid[row * sky->size + c])
		{
			c_tall = c;
			row_sight++;
		}
	}
	if (sky->cond[row + sky->size * 3] == row_sight)
		return (1);
	else
		return (0);
}

int	left_chk(t_sky *sky, int row)
{
	int	c;
	int	row_sight;
	int	c_tall;

	row_sight = 1;
	c = 0;
	c_tall = 0;
	while (++c < sky->size)
	{
		if (sky->grid[row * sky->size + c_tall] < sky->grid[row * sky->size + c])
		{
			c_tall = c;
			row_sight++;
		}
	}
	if (sky->cond[row + sky->size * 2] == row_sight)
		return (1);
	else
		return (0);
}
