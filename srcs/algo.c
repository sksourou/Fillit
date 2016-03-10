/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:59:49 by sksourou          #+#    #+#             */
/*   Updated: 2015/12/07 17:59:52 by sksourou         ###   ########.fr       */
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

int 	first_line(char *new_line)
{
	int i;

	i = 0;

	while(new_line[i] != '\n')
		i++;
	return (i + 1);
}

char 	*add_new_space(char *new_map)
{
	char *n_map;
	int i;
	int ct;

	ct = 0;
	i = first_line(new_map);
	n_map = ft_strnew(i * i);
	while (ct < i)
	{
		n_map[ct] = '.';
		ct++;
	}
	n_map[ct++] = '\n';
	i = 0;
	while (new_map[i])
	{
		if (new_map[i] == '\n' && new_map[i - 1] != '\n')
		{
			n_map[ct++] = '.';
			n_map[ct++] = '\n';
			i++;
		}
		else if(new_map[i - 1] == '\n' && new_map[i] == '\n')
		{
			n_map[ct + 1] = '\0';
			return (n_map);	
		}
		else 
			n_map[ct++] = new_map[i++];
	}
	return(n_map);
}

void		display(char *map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	if ((map[i - 1] == '\n') && (map[i - 2] == '\n'))
		map[i - 1] = '\0';
}

void	algo(t_tetri tetris)
{
	char *map;
	char *new_map;
	int i;

	map = tetris.tetrimi[0];
	move_tetri(map);
	i = 1;
	while (i < tetris.nbr_tetri)
	{
		new_map = tetris.tetrimi[i];
		if (found_best(new_map, map) != 1)
		{
			map = add_new_space(map);
			map = move_map(map);
		}
		else
			i++;
	}
	display(map);
	printf("--Map--\n%s", map);
}