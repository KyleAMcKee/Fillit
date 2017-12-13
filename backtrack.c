/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:26:30 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/18 17:15:59 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**convert_to_letts(char **src, int tet_nubr_npie)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = src;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				str[i][j] = tet_nubr_npie + 'A';
			}
			j++;
		}
		i++;
	}
	return (str);
}

/*
** int array has the coordinates for the peice that looks like this
** {0, 2}
** {1, 2}
** {2, 2}
** {3, 2}
** navigate by checking the first value as x and the second value as y
*/

int		check_if_possible(int **two_d_int_arr, char **two_d_arr, int x, int y)
{
	int i;
	int x1;
	int y1;
	int size;

	size = 0;
	while (two_d_arr[0][size] != '\0')
		size++;
	i = 0;
	while (i < 4)
	{
		x1 = x;
		y1 = y;
		x1 = x1 + two_d_int_arr[i][0];
		y1 = y1 + two_d_int_arr[i][1];
		if (x1 > size - 1 || y1 > size - 1 || two_d_arr[y1][x1] == '\0'
			|| two_d_arr[y1][x1] != '.')
			return (0);
		i++;
	}
	return (1);
}

char	**place(int **two_d_int_arr, char **two_d_arr, int x, int y)
{
	int		i;
	int		x1;
	int		y1;
	char	**two_d_fin;

	i = 0;
	two_d_fin = two_d_arr;
	while (i < 4)
	{
		x1 = x;
		y1 = y;
		x1 = x1 + two_d_int_arr[i][0];
		y1 = y1 + two_d_int_arr[i][1];
		two_d_fin[y1][x1] = '#';
		i++;
	}
	return (two_d_fin);
}

/*
** returns null if no solution found
** //added while loop to get rid of box size variable in function///
** j = -1; //reduce number of lines in code
** //adds three to get to 4, for the 4x4 array
** 	box_n_tet_nbr[0] = box_size;
**	box_n_tet_nbr[1] = tet_nbr_npie(amount of tets);
** possible to change whole function/change **char within (less variables)
** tmp = NULL (not nessessary)
*/

char	**backtrack(char **two_d_arr,
					int ***three_d,
					int tet_cnt,
					int *box_n_tet_nbr)
{
	int		j;
	int		i;
	char	**tmp;

	j = -1;
	tmp = NULL;
	if (tet_cnt == box_n_tet_nbr[1])
		return (two_d_arr);
	while (j++ < box_n_tet_nbr[0] + 3)
	{
		i = -1;
		while (i++ < box_n_tet_nbr[0] + 3)
		{
			if ((check_if_possible(three_d[tet_cnt], two_d_arr, i, j)))
			{
				two_d_arr = place(three_d[tet_cnt], two_d_arr, i, j);
				two_d_arr = convert_to_letts(two_d_arr, tet_cnt);
				tmp = backtrack(two_d_arr, three_d, tet_cnt + 1, box_n_tet_nbr);
				if (tmp)
					return (tmp);
				ft_clean_grid(two_d_arr, tet_cnt);
			}
		}
	}
	return (0);
}

/*
** When box_size = 1 that means 4x4
** passing an int array with values of box_size [0] and tet_num [1]
**	box_n_tet_nbr[0] = box_size
**	box_n_tet_nbr[1] = tet_nbr_npie(amount of tets)
** might need to add  "free_array(two_d_arr);" but causes seg fault?
*/

char	**solver(int ***three_d_int_arr, int tet_nbr_npie)
{
	int		tet_cnt;
	char	**two_d_arr;
	int		*box_n_tet_nbr;

	box_n_tet_nbr = (int*)malloc(sizeof(int) * 2);
	tet_cnt = 0;
	box_n_tet_nbr[0] = round_up_sqrt(tet_nbr_npie * 4) - 3;
	box_n_tet_nbr[1] = tet_nbr_npie;
	two_d_arr = NULL;
	while (!two_d_arr)
	{
		two_d_arr = create_new_box(box_n_tet_nbr[0]);
		two_d_arr = backtrack(two_d_arr, three_d_int_arr,
			tet_cnt, box_n_tet_nbr);
		box_n_tet_nbr[0]++;
	}
	ft_putarr(two_d_arr);
	return (two_d_arr);
}
