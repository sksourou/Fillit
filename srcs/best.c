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
	printf("--New_map--\n%s", new_map);
	printf("--Map--\n%s", map);
	return (1);
}