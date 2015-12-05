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

void	init(t_tetri *tetri)
{
	tetri->len = 21;
	tetri->nbr_tetri = 0;
}

int 	stock_tetri(char *map)
{
	int 	i;
	int 	j;
	int 	x;
	char	**tetrimi;
	t_tetri	tetri;

	i = 0;
	j = 0;
	init(&tetri);
	tetrimi = (char **)malloc(sizeof(char *) * count_tetri(map));
	while (i <= count_tetri(map))
	{
		x = 0;
		tetrimi[i] = (char *)malloc(sizeof(char) * 20);
		while (x <= tetri.len)
		{
			tetrimi[i][x] = map[j];
			x++;
			j++;
		}
		ft_putstr(tetrimi[i]);
		i++;
	}
	return (0);
}