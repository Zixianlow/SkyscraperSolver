/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:22:51 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/31 21:49:52 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sky.h"

int	ft_isgood(int n)
{
	if (n % 4 == 0)
		return (1);
	return (0);
}

int	ft_numeric(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_free_nums(t_sky *sky)
{
	int	i;

	i = 0;
	while (sky->nums[i])
	{
		free(sky->nums[i]);
		i++;
	}
	return (1);
}

int	ft_number_count(char *s, t_sky *sky)
{
	int	n;

	sky->nums = ft_split(s, ' ');
	n = 0;
	while (sky->nums[n])
	{
		if (!ft_numeric(sky->nums[n]))
			return (ft_free_nums(sky));
		n++;
	}
	if (!ft_isgood(n))
		return (ft_free_nums(sky));
	sky->size = n / 4;
	sky->n = sky->size * sky->size;
	sky->grid = malloc(sizeof(int *) * sky->n);
	sky->max = malloc(sizeof(int *) * sky->n);
	sky->cond = malloc(sizeof(int *) * n);
	n = 0;
	while (sky->nums[n])
	{
		sky->cond[n] = ft_atoi(sky->nums[n]);
		n++;
	}
	n = 0;
	while (n < sky->n)
	{
		sky->grid[n] = 0;
		sky->max[n] = 0;
		n++;
	}
	ft_free_nums(sky);
	return (0);
}
