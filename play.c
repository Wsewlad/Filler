/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:34:25 by vfil              #+#    #+#             */
/*   Updated: 2018/03/05 13:34:26 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_pset(t_param *param, int pi, int pj)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < param->piece.size_y)
	{
		j = 0;
		while (j < param->piece.size_x)
		{
			if (param->map.m[i + pi][j + pj] == param->piece.p[i][j] && param->piece.p[i][j] == param->plr &&
						param->map.m[i + pi][j + pj] != param->enemy)
			{
				k++;
			}
			j++;
		}
		i++;
	}
	if (k == 1)
	{
		param->res_y = pi;
		param->res_x = pj;
		return (1);
	}
	return (0);
}

void	play(t_param *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->map.size_y - param->piece.size_y)
	{
		j = 0;
		while (j < param->map.size_x - param->piece.size_x)
		{
			if ((check_pset(param, i, j)) == 1)
				return ;
			j++;
		}
		i++;
	}
	param->end = 1;
}
