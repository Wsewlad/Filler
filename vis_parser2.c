/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:44:46 by vfil              #+#    #+#             */
/*   Updated: 2018/03/09 17:44:47 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_plr_numb(t_param *param, int *i, int j, char *buf)
{
	if (buf[j] == 'O')
		param->map.m[*i][j] = 1;
	else if (buf[j] == 'o')
		param->map.m[*i][j] = 3;
	else if (buf[j] == 'X')
		param->map.m[*i][j] = 2;
	else if (buf[j] == 'x')
		param->map.m[*i][j] = 4;
	else
		param->map.m[*i][j] = 0;
}

void	check_fin(t_param *param, char *line)
{
	if (ft_strstr(line, "== O"))
		param->vsl.res.y = ft_atoi(line + 10);
	else if (ft_strstr(line, "== X"))
	{
		param->vsl.res.x = ft_atoi(line + 10);
		param->vsl.stop = 1;
	}
}

void	set_scale(t_param *param)
{
	int x;
	int y;

	x = param->map.size_x;
	y = param->map.size_y;
	param->map.created = 1;
	if (y == 15 && x == 17)
	{
		param->vsl.scale = 20;
		param->vsl.img_x = (param->vsl.win_x - x * param->vsl.scale) / 2;
		param->vsl.img_y = (param->vsl.win_y - y * param->vsl.scale) / 2;
	}
	else if (y == 24 && x == 40)
	{
		param->vsl.scale = 15;
		param->vsl.img_x = (param->vsl.win_x - x * param->vsl.scale) / 4;
		param->vsl.img_y = (param->vsl.win_y - y * param->vsl.scale) / 2;
	}
	else if (y == 100 && x == 99)
	{
		param->vsl.scale = 5;
		param->vsl.img_x = (param->vsl.win_x - x * param->vsl.scale) / 3;
		param->vsl.img_y = 5;
	}
}
