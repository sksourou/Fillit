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

char	*move_tetri(char *new_map)
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
		return (NULL);
	if (new_map[i + 4] == '#' || new_map[i + 9] == '#')
		x = 1;
	if (x == 1 && i == 1)
		return (NULL);
	while (new_map[j])
	{
		if (new_map[j] == '#' && new_map[j] != '\n')
		{
			new_map[j - i + x] = new_map[j];
			new_map[j] = '.';
		}
		j++;
	}
	return (new_map);
}

char	*move_map(char *new_map)
{
	int i;
	int	j;
	int x;

	j = 0;
	i = 0;
	x = 0;
	while (isupper(new_map[i]) == 0)
		i++;
	if (i == 0)
		return (NULL);
	if (isupper(new_map[i + 4]) == 1)
		x = 1;
	while (new_map[j])
	{
		if (isupper(new_map[j]) == 1)
		{
			new_map[j - i + x] = new_map[j];
			new_map[j] = '.';
		}
		j++;
	}
	return (new_map);
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
	static char alph = 'A';

	alph++;
	move_tetri(new_map);
	change_first_map(map);
	check_tetri(new_map, map);
	change_diez(map, alph);
	if (check_alph(map, alph) == 0)
	{
		alph--;
		return (0);
	}
	printf("--Map--\n%s", map);
	return (1);
}