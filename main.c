/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:03:13 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/12 19:00:18 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

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
	if (solve_puzzle(&sky, 0))
		ft_print_grid(sky.grid, sky.size);
	else
		printf("No solution found");
	free(sky.grid);
	free(sky.cond);
	return (0);
}

	// ft_print_grid(sky.grid, sky.size);
