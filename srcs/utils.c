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

int		count_tetri(char *map)
{
	int i;
	int j;
	int ct;

	i = 0;
	ct = 21;
	j = 0;
	while(map[i])
	{
		if (i == ct)
		{
			j++;
			ct += 21;
		}
		i++;
	}
	return (j + 1);
}

char	*change_diez(char *new_map, char Alph)
{
	int k;

	k = 0;
	while (new_map[k])
	{
		if (new_map[k] == '#')
			new_map[k] = Alph;
		k++;
	}
	return (new_map);
}