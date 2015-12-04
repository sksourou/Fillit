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

int valid_tetri(char *map);
int check_map(char *map);
int	parse_map(char *file);

#endif