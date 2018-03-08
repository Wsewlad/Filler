/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:55:23 by vfil              #+#    #+#             */
/*   Updated: 2018/03/07 15:55:24 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_enemy(t_param *param)
{
	int i;
	int j;
	int min_len;

	min_len = 0;
	i = 0;
	while (i < param->map.size_y)
	{
		j = 0;
		while (j < param->map.size_x)
		{
			if (param->map.m[i][j] == param->enemy)
			{
				param->enm.x = j;
				param->enm.y = i;
				choose_crd(param, &min_len);
			}
			j++;
		}
		i++;
	}
}

void	check_piece_len(t_param *param, int *min, int px, int py)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < param->piece.size_y)
	{
		j = 0;
		while (j < param->piece.size_x)
		{
			if (param->piece.p[i][j] == param->plr)
			{
				len = ABS((param->enm.y - (py + i))) + \
						ABS((param->enm.x - (px + j)));
				if (len < *min)
					*min = len;
			}
			j++;
		}
		i++;
	}
}

void	set_player_crd(t_param *param, int *min_len, int len, int i)
{
	*min_len = len;
	param->play.x = param->crd[i].x;
	param->play.y = param->crd[i].y;
}

void	choose_crd(t_param *param, int *min_len)
{
	int i;
	int len;

	i = 0;
	while (i < param->nb)
	{
		len = ABS((param->enm.y - param->crd[i].y)) + \
		ABS((param->enm.x - param->crd[i].x));
		check_piece_len(param, &len, param->crd[i].x, param->crd[i].y);
		if (!*min_len)
			set_player_crd(param, min_len, len, i);
		else if (param->pos == 1 && len <= *min_len)
			set_player_crd(param, min_len, len, i);
		else if (param->pos == 2 && len < *min_len)
			set_player_crd(param, min_len, len, i);
		i++;
	}
}
