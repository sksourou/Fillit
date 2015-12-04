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
	int k;
	int i;
	int ct;

	i = 0;
	k = 0;
	ct = 20;
	while (map[i])
	{
		if (map[i] == '#')
			k++;
		else if (i == ct && k != 4)
			return (0);
		else if (i == ct && map[i] == '\n')
		{
			ct += 20;
			k = 0; 
		}
		// ft_putnbr(i);
		// ft_putendl("");
		// ft_putnbr(ct);
		// ft_putendl("");
		// ft_putchar(map[i]);
		i++;
	}
	if (map[i] != '\0')
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
	ft_putnbr(ft_strlen(map));
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
		if (map[i] == '\0' && ct != 3)
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