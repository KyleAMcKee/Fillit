/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:25:35 by kmckee            #+#    #+#             */
/*   Updated: 2017/10/18 15:50:59 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	populate_int_arr(int **arr, char **two_d_arr, int i, int j)
{
	int k;
	int l;

	while (two_d_arr[i] != 0)
	{
		l = 0;
		while (two_d_arr[i][j] != '\0')
		{
			k = 1;
			if (two_d_arr[i][j++] == '#')
			{
				while (two_d_arr[i][j] != '#')
				{
					j++;
					k++;
				}
				arr[i][l++] = k;
			}
			if (l == 3)
				j++;
		}
		i++;
		j = 0;
	}
}

int		**get_shape(char **two_d_arr, int tet_nubr_npie)
{
	int		**arr;
	int		i;
	int		j;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * tet_nubr_npie);
	while (i < tet_nubr_npie)
		arr[i++] = (int *)malloc(sizeof(int) * 3);
	i = 0;
	j = 0;
	populate_int_arr(arr, two_d_arr, i, j);
	return (arr);
}

int		***get_three_d_arr(char **two_d_arr, int tet_nubr_npie)
{
	int	***three_d_arr;
	int **two_d_int;
	int i;
	int j;
	int tet_num;

	two_d_int = get_shape(two_d_arr, tet_nubr_npie);
	three_d_arr = (int***)malloc(sizeof(int**) * tet_nubr_npie);
	tet_num = tet_nubr_npie;
	i = 0;
	j = 0;
	while (tet_nubr_npie--)
	{
		three_d_arr[i] = (int**)malloc(sizeof(int*) * 5);
		while (j < 4)
			three_d_arr[i][j++] = (int*)malloc(sizeof(int) * 2);
		three_d_arr[i][4] = (int*)malloc(sizeof(int));
		three_d_arr[i][4][0] = i;
		j = 0;
		i++;
	}
	i = 0;
	while (i < tet_num)
		(make_grid(three_d_arr, two_d_int, i++));
	return (three_d_arr);
}
