/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:16:11 by sksourou          #+#    #+#             */
/*   Updated: 2015/12/05 17:16:13 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_tetri(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '#')
			map[i] = '.';
		i++;
	}
}

int		isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		len_tetri(char *new_map)
{
	int	i;
	int	x;
	int	n;

	n = 0;
	x = 0;
	i = 0;
	while (new_map[i])
	{
		if (new_map[i] == '#')
		{
			while (new_map[i] == '#')
			{
				i++;
				x++;
			}
		}
		if (x > n)
			n = x;
		i++;
	}
	return (n);
}

int check_alph(char *map, char alph)
{
	while(*map)
	{
		if (*map == alph)
			return (1);
		map++;
	}
	return (0);
}

void	change_first_map(char *map)
{
	int	k;

	k = 0;
	while (map[k])
	{
		if (map[k] == '#')
		{
			map[k] = 'A';
		}
		k++;
	}
}

int		change_diez(char *new_map, char Alph)
{
	int k;

	k = 0;
	while (new_map[k])
	{
		if (new_map[k] == '#')
		{
			new_map[k] = Alph;
		}
		k++;
	}
	return (0);
}
