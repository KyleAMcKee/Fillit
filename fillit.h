/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 21:36:23 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/18 17:19:44 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

char		*ft_get_stdin(char *buf, int *i);
int			check_if_valid(char *final, int *tot_char);
char		**turn_into_2d(char *final, int *tot_char);
int			**get_shape(char **two_d_arr, int tet_nubr_npie);
int			check_if_possible(int **two_d_int_arr,
							char **two_d_arr, int x, int y);
char		**solver(int ***tree_d_int_arr, int tet_nbr_npie);
char		**create_new_box(int size);
void		ft_clean_grid(char **grid, int let);
int			***get_three_d_arr(char **two_d_arr, int tet_nubr_npie);
void		make_grid(int ***three_d_arr, int **two_d, int index);

#endif
