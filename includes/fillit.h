/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:38:34 by sksourou          #+#    #+#             */
/*   Updated: 2015/12/04 16:38:35 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 500
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_tetri
{
	int 		nbr_tetri;
	int 		len;
	char		**tetrimi;
}				t_tetri;

int 	valid_tetri(char *map);
int 	check_map(char *map);
int		parse_map(char *file);
int		count_tetri(char *map);
int 	**stock_tetri(char *map, t_tetri *tetris);
void	init(t_tetri *tetri, char *map);
int 	valid_tetri(char *map);
int 	found_diez(char *map, int i);


#endif