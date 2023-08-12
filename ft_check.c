/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:59:22 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 19:00:56 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int	used_in_row(t_sky *sky, int row, int num)
{
	int	c;

	c = -1;
	while (++c < sky->size)
	{
		if (sky->grid[row * sky->size + c] == num)
			return (1);
	}
	return (0);
}

int	used_in_col(t_sky *sky, int col, int num)
{
	int	r;

	r = -1;
	while (++r < sky->size)
	{
		if (sky->grid[r * sky->size + col] == num)
			return (1);
	}
	return (0);
}

int	check_constraints(t_sky *sky, int pos, int num)
{
	int	row;
	int	col;

	row = pos / sky->size;
	col = pos % sky->size;
	sky->grid[row * sky->size + col] = num;
	if (row_is_filled(sky, row))
	{
		if (!(left_chk(sky, row) && right_chk(sky, row)))
		{
			sky->grid[row * sky->size + col] = 0;
			return (0);
		}
	}
	if (col_is_filled(sky, col))
	{
		if (!(up_chk(sky, col) && down_chk(sky, col)))
		{
			sky->grid[row * sky->size + col] = 0;
			return (0);
		}
	}
	return (1);
}

int	is_safe(t_sky *sky, int pos, int num)
{	
	int	row;
	int	col;

	row = pos / sky->size;
	col = pos % sky->size;
	if (used_in_row(sky, row, num) || used_in_col(sky, col, num))
		return (0);
	if (!check_constraints(sky, pos, num))
		return (0);
	return (1);
}
