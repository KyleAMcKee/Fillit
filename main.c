/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/19 19:01:13 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error(int npiece, char *final)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (npiece == 1)
	{
		while (final[i] != '\0')
		{
			if (final[i] == '\n')
				c++;
			i++;
		}
		if (c != 4)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		tot_char;
	int		npiece;
	int		***int_arr;
	char	*final;

	tot_char = 0;
	if (argc > 0)
	{
		final = ft_get_stdin(argv[1], &tot_char);
		if (!final)
		{
			ft_putstr("error\n");
			return (0);
		}
		npiece = check_if_valid(final, &tot_char);
		if (!(error(npiece, final)) || turn_into_2d(final, &tot_char) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		int_arr = get_three_d_arr(turn_into_2d(final, &tot_char), npiece);
		solver(int_arr, npiece);
	}
	return (0);
}
