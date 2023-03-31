/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:03:13 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/31 22:28:53 by lzi-xian         ###   ########.fr       */
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

int	solve_puzzle(t_sky *sky, int pos)
{
	int	i;

	if (pos == sky->n)
		return (1);
	if (sky->grid[pos])
		if (solve_puzzle(sky, pos + 1))
			return (1);
	i = 0;
	while (++i <= sky->size)
	{
		if (is_safe(sky, pos, i))
		{
			sky->grid[pos] = i;
			if (solve_puzzle(sky, pos + 1))
				return (1);
			sky->grid[pos] = 0;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_sky	sky;

	if (ac != 2)
	{
		printf("Invalid number of arguments!!!");
		return (1);
	}
	if (ft_number_count(av[1], &sky))
	{
		printf("Bad Format!!!");
		return (1);
	}
	ft_prefill(&sky);
	ft_set_max_in_line(&sky);
	// ft_print_grid(sky.grid, sky.size);
	// ft_print_grid(sky.max, sky.size);
	if (solve_puzzle(&sky, 0))
		ft_print_grid(sky.grid, sky.size);
	else
		printf("No solution found");
	free(sky.grid);
	free(sky.cond);
	return (0);
}
