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

int 	check_tetri(char *new_map, int i)
{
	int	j;
	int	x;

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
}

int		found_best(t_tetri *tetris, char *new_map, int i)
{
	new_map = tetris->tetrimi[i];
	ft_putstr(new_map);
	move_tetri(new_map);
	ft_putstr(new_map);
	return (1);
}