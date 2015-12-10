/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:56:57 by dmathe            #+#    #+#             */
/*   Updated: 2015/12/05 18:56:59 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init(t_tetri *tetri, char *map)
{
	tetri->len = 20;
	tetri->nbr_tetri = count_tetri(map);
}

int	**stock_tetri(char *map, t_tetri *tetri)
{
	int 	i;
	int 	j;
	int 	x;

	i = 0;
	j = 0;
	tetri->tetrimi = (char **)malloc(sizeof(char *) * count_tetri(map));
	while (i < count_tetri(map))
	{
		x = 0;
		tetri->tetrimi[i] = (char *)malloc(sizeof(char) * 20);
		while (x <= tetri->len)
		{
			tetri->tetrimi[i][x] = map[j];
			x++;
			j++;
		}
		i++;
	}
	return (0);
}