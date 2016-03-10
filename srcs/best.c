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
	int	i;

	i = 0;
	while (new_map[i])
	{
		if (new_map[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		supp_line(char *new_map)
{
	int	i;

	i = 5;
	while (new_map[i] && i < 20)
	{
		if (new_map[i])
			new_map[i - 5] = new_map[i];
		i++;
	}
	new_map[15] = '.';
	new_map[16] = '.';
	new_map[17] = '.';
	new_map[18] = '.';
	return (0);
}

int		supp_col(char *new_map)
{
	int	i;

	i = 0;
	while (new_map[i] && i < 20)
	{
		if (new_map[i] == '#')
		{
			new_map[i - 1] = '#';
			new_map[i] = '.';
		}
		i++;
	}
	return (0);
}

char	*move_tetri(char *new_map)
{
	int i;
	int	j;

	j = 0;
	i = 0;
	while (new_map[i])
	{
		if (new_map[0] == '.' && new_map[1] == '.' && new_map[2] == '.'
			&& new_map[3] == '.')
			supp_line(new_map);
		if (new_map[0] == '.' && new_map[5] == '.' && new_map[10] == '.'
			&& new_map[15] == '.')
			supp_col(new_map);
		i++;
	}
	return (new_map);
}

char	*move_map(char *new_map)
{
	int i;
	int	j;

	j = check_len(new_map);
	i = 0;
	while (new_map[i])
	{
		if (isupper(new_map[i]) == 1)
		{
			new_map[i - j - 1] = new_map[i];
			new_map[i] = '.';
		}
		i++;
	}
	return (new_map);
}


int		found_best(char *new_map, char *map)
{
	static char alph = 'A';

	alph++;
	move_tetri(new_map);
	change_first_map(map);
	pose_up_left(new_map, map);
	change_diez(map, alph);
	if (check_alph(map, alph) == 0)
	{
		alph--;
		return (0);
	}
	if (good_tetri(map, alph) != 4)
	{
		while (*map)
		{
			if (*map == alph)
				*map = '.';
			map++;
		}
		alph--;
		return (0);
	}
	//printf("--Map--\n%s", map);
	return (1);
}