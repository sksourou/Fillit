/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:13:28 by dmathe            #+#    #+#             */
/*   Updated: 2015/12/08 16:13:31 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	check_len(char *new_map)
{
	int	j;
	int	x;
	int	i;

	i = 0;
	x = 0;
	j = i;
	while (new_map[j] == '#')
		j++;
	x = j - i;
	j = 0;
	while (new_map[i] == '#')
	{
		i += 5;
		j++;
	}
	if (x + j == 3)
		return (3);
	return ((x > j) ? x : j);
}

void	move_tetri(char *new_map)
{
	int i;
	int	j;
	int x;

	j = 0;
	i = 0;
	x = 0;
	while (new_map[i] != '#')
		i++;
	if (i == 0)
		return;
	if (new_map[i + 4] == '#')
		x = 1;
	while (new_map[j])
	{
		if (new_map[j] == '#')
		{
			new_map[j - i + x] = new_map[j];
			new_map[j] = '.';
		}
		j++;
	}
}

void	check_tetri(char *new_map, char *map)
{
	int	i;

	i = 0;
	if (check_len(new_map) == 4)
		pose_up_left(new_map, map);
	else
		return;
}

int		found_best(char *new_map, char *map)
{
	move_tetri(new_map);
	check_tetri(new_map, map);
	return (1);
}