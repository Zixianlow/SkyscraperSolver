/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:56:31 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/31 21:31:33 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int	sum_of_row_col(int n)
{
	int	sum;

	sum = 0;
	while (n > 0)
	{
		sum += n;
		n--;
	}
	return (sum);
}

int	col_is_filled(t_sky *sky, int col)
{
	int	r;
	int	col_value;

	r = -1;
	col_value = 0;
	while (++r < sky->size)
		col_value += sky->grid[r * sky->size + col];
	if (col_value == sum_of_row_col(sky->size))
		return (1);
	else
		return (0);
}

int	row_is_filled(t_sky *sky, int row)
{
	int	c;
	int	row_value;

	c = -1;
	row_value = 0;
	while (++c < sky->size)
		row_value += sky->grid[row * sky->size + c];
	if (row_value == sum_of_row_col(sky->size))
		return (1);
	else
		return (0);
}
