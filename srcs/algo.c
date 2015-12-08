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
		if (new_map[i] == '\n' && new_map[i + 1] != '\0')
		{
			if (new_map[i + 1] != '\0')
				n_map[ct++] = '.';
			n_map[ct++] = '\n';
			i++;
		}
		else
			n_map[ct++] = new_map[i++];
	}
	ft_putstr(n_map);
	return(n_map);
}

void	algo(t_tetri tetris)
{
	char *new_map;
	char alph;
	int i;

	i = 0;
	alph = 'A';
	new_map = tetris.tetrimi[0];
	// while(i < tetris.nbr_tetri)
	// {
	// 	if (found_best(tetris, new_map) != 1)
	new_map = add_new_space(new_map);
	ft_putendl("--NEW MAP--");
	new_map = add_new_space(new_map);
	ft_putendl("--NEW MAP--");
	new_map = add_new_space(new_map);
	ft_putendl("--NEW MAP--");
	new_map = add_new_space(new_map);
	ft_putendl("--NEW MAP--");
	new_map = add_new_space(new_map);
	ft_putendl("--NEW MAP--");
	new_map = add_new_space(new_map);
	ft_putendl("--NEW MAP--");
	new_map = add_new_space(new_map);	
	// 	else
	// 		i++;
	// }
}