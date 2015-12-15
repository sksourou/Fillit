/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:32:10 by dmathe            #+#    #+#             */
/*   Updated: 2015/12/10 12:32:12 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		good_tetri(char *map, char alph)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == alph)
			j++;
		i++;
	}
	return (j);
}

int		char_cmp(char *map, int i, int x, int n)
{
	if (map[x + i + n] == '\0')
		return (1);
	if (map[x + i + n] == '.')
	{
		map[x + i + n] = '#';
		return (1);
	}
	return (0);
}	

int		verif_tetri(char *map)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (map[i])
	{
		if (map[i] == '#' && map[i + 1] == '\n' && map[i + 2] == '#')
		{
			i = 0;
			break;
		}
		i++;
	}
	if (i == 0)
	{
		delete_tetri(map);
	}
	return ((i == 0) ? 0 : 1);
}

int		tetri_cmp(char *new_map, char *map, int n)
{
	int	x;
	int	j;

	j = 0;
	x = 0;
	while (new_map[j])
	{
		if (new_map[j] == '#')
		{
			if (char_cmp(map, j, x, n) == 0)
			{
				delete_tetri(map);
				j = -1;
				x++;
			}
		}
		if (new_map[j] == '\n' && check_len(map) > 4)
			x += (check_len(map) - 4);
		j++;
	}
	if (verif_tetri(map) == 0)
	{
		n++;
		tetri_cmp(new_map, map, n);
	}
	return (0);
}

void	pose_up_left(char *new_map, char *map)
{
	int	n;

	n = 0;
 	if (check_len(new_map) > check_len(map))
 	{
 		map = add_new_space(map);
 		move_tetri(map);
 	}
	tetri_cmp(new_map, map, n);
}