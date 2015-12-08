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


void	algo(t_tetri tetris)
{
	char *new_map;
	char alph;
	int i;

	i = 0;
	alph = 'A';
	new_map = tetris.tetrimi[0];
	while(i < tetris.nbr_tetri)
	{
		if (found_best(tetris, new_map, i) != 1)
			add_new_space(new_map);
		else
			i++;
	}
}