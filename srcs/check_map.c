/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:32:46 by sksourou          #+#    #+#             */
/*   Updated: 2015/12/04 18:32:47 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int found_diez(char *map, int i)
{
	if (map[i + 1] && map[i + 1] == '#')
		return (1);
	if (map[i + 5] && map[i + 5] == '#')
		return (1);
	return (0);
}

int valid_tetri(char *map)
{
	int nbr_tetri;
	int i;
	int k;
	int ct;

	ct = 0;
	k = 0;
	i = 0;
	nbr_tetri = count_tetri(map);
	while(map[i])
	{
		if (map[i] == '#' && ct != 3)
		{
			ct++;
			if (found_diez(map, i) != 1 && map[i + 3] != '#' && map[i + 4] != '#') 
					return (0);
		}
		else if (ct == 3 && map[i] == '#')
			ct++;
		else if (map[i] == '#')
			return (0);
		i++;
	}
	if (ct == 4)
		return (1);
	return (0);
}

int check_map(char *map)
{
	int i;
	int j;
	int ct;

	ct = 0;
	i = 0;
	j = 0;
	while(map[i])
	{
		if (map[i] == '#' || map[i] == '.')
			j++;
		else if ((map[i] == '\n' || map[i] == '\0') && j == 4)
		{
			j = 0;
			ct++;
		}
		else if (map[i] == '\n' && j == 0 && ct == 4)
			ct = 0;
		else	
			return (0);
		i++;
		if (map[i] == '\0' && ct != 4)
			return (0);
	}
	return (1);
}

int	parse_map(char *file)
{
	int fd;
	char *buff;
	t_tetri tetris;	

	fd = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	buff = ft_strnew(BUF_SIZE);
	if(read(fd, buff, BUF_SIZE) < 0)
		return (0);
	if (check_map(buff) == 0)
		return (0);
	init(&tetris, buff);
	stock_tetri(buff, &tetris);
	fd = 0;
	while (fd < tetris.nbr_tetri)
	{
		if (valid_tetri(tetris.tetrimi[fd]) == 0)
			return (0);
		fd++;
	}
	algo(tetris);
	return (1);
}