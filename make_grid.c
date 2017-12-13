/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:01:44 by kmckee            #+#    #+#             */
/*   Updated: 2017/10/18 17:13:38 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_grid(char **grid, int let)
{
	int		i;
	int		j;
	char	letter;

	i = 0;
	letter = let + 'A';
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == letter)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

/*
** adjusts size variable being under 4
**  //not  sure if supposed to protect this
*/

char	**create_new_box(int size)
{
	int		char_size;
	char	**nbox;
	int		i;
	int		j;
	int		cnt;

	i = 0;
	cnt = 0;
	char_size = size + 3;
	nbox = (char**)malloc((char_size + 1) * sizeof(char*));
	while (i < char_size)
		nbox[i++] = ft_strnew(char_size);
	i = 0;
	while (i < char_size)
	{
		j = 0;
		while (j < char_size)
			nbox[i][j++] = '.';
		nbox[i][j] = '\0';
		i++;
	}
	nbox[i] = (char*)malloc(sizeof(char));
	nbox[i] = NULL;
	return (nbox);
}

void	grid_helper(int ***three_d_arr, int **two_d, int ind, int i)
{
	int x;
	int y;
	int j;
	int k;

	x = 0;
	y = 0;
	k = -1;
	while (k++ < 3)
	{
		j = 0;
		if (two_d[ind][k] == 3)
			x -= 2;
		if (two_d[ind][k] == 4)
			x--;
		if (two_d[ind][k] == 1)
			x++;
		three_d_arr[ind][i][j++] = x;
		if (two_d[ind][k] == 5 || two_d[ind][k] == 3 || two_d[ind][k] == 4)
			three_d_arr[ind][i++][j] = ++y;
		else
			three_d_arr[ind][i++][j] = y;
	}
}

void	make_grid(int ***three_d_arr, int **two_d, int index)
{
	int i;
	int j;

	i = 0;
	j = 0;
	three_d_arr[index][i][j++] = 0;
	three_d_arr[index][i][j] = 0;
	i++;
	grid_helper(three_d_arr, two_d, index, i);
}
