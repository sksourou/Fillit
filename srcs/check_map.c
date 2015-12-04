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

int valid_tetri(char *map)
{
	int i;
	int j;

	i = 0;
	j = 20;

	while (map[i])
	{
		if (map[i] == '#')
			k++;
		else if (i = 20 && k != 4)
			return (0);
		else
			k = 0;

	}
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

	fd = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	buff = ft_strnew(BUF_SIZE);
	if(read(fd, buff, BUF_SIZE) < 0)
		return (0);
	if (check_map(buff) == 0)
		return (0);
	if (valid_tetri(buff) == 0)
		return (0);
	return 1;
}