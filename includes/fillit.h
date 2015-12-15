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

int		good_tetri(char *map, char alph);
char	*move_map(char *new_map);
int		check_alph(char *map, char alph);
void	change_first_map(char *map);
void	delete_tetri(char *map);
int		isupper(char c);
int		len_tetri(char *new_map);
void	check_tetri(char *new_map, char *map);
int		tetri_cmp(char *new_map, char *map, int n);
void	pose_up_left(char *new_map, char *map);
int 	check_len(char *new_map);
char	*move_tetri(char *new_map);
int		found_best(char *new_map, char *map);
int 	valid_tetri(char *map);
int 	check_map(char *map);
int		parse_map(char *file);
int		count_tetri(char *map);
int 	**stock_tetri(char *map, t_tetri *tetris);
void	init(t_tetri *tetri, char *map);
int 	valid_tetri(char *map);
int 	found_diez(char *map, int i);
void	algo(t_tetri tetris);
int 	change_diez(char *new_map, char Alph);
char 	*add_new_space(char *new_map);
int 	first_line(char *new_line);
char 	*add_new_space(char *new_map);

#endif