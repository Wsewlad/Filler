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

int		check_plr_enemy(t_param *param, t_var *v, int mi, int mj)
{
	if (param->map.m[v->i + mi][v->j + mj] == param->piece.p[v->i][v->j]
		&& param->map.m[v->i + mi][v->j + mj] == param->plr)
		v->k++;
	if (param->map.m[v->i + mi][v->j + mj] == param->enemy && \
		param->piece.p[v->i][v->j] == param->plr)
		return (0);
	return (1);
}

void	check_pset(t_param *param, int mi, int mj, int *iter)
{
	t_var	v;

	v.i = 0;
	v.k = 0;
	while (v.i < param->piece.size_y)
	{
		v.j = 0;
		while (v.j < param->piece.size_x)
		{
			if (!check_plr_enemy(param, &v, mi, mj))
				return ;
			v.j++;
		}
		v.i++;
	}
	if (*iter == -1 && v.k == 1)
		param->nb++;
	else if (v.k == 1)
	{
		param->crd[*iter].x = mj;
		param->crd[*iter].y = mi;
		(*iter)++;
	}
}

void	count_set_place(t_param *param, int itr)
{
	int i;
	int j;
	int iter;

	iter = itr;
	i = 0;
	while (i < param->map.size_y - param->piece.size_y + 1)
	{
		j = 0;
		while (j < param->map.size_x - param->piece.size_x + 1)
		{
			check_pset(param, i, j, &iter);
			j++;
		}
		i++;
	}
}

void	play(t_param *param)
{
	param->nb = 0;
	count_set_place(param, -1);
	if (param->crd)
		free(param->crd);
	if (param->nb)
		param->crd = (t_coord*)malloc(sizeof(t_coord) * param->nb);
	else
	{
		param->nb = -1;
		return ;
	}
	count_set_place(param, 0);
	if (!(param->iter % 3))
	{
		param->play.x = param->crd[0].x;
		param->play.y = param->crd[0].y;
		param->iter++;
	}
	else
		find_enemy(param);
}
