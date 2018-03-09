/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:15:30 by vfil              #+#    #+#             */
/*   Updated: 2018/03/09 14:15:31 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	vis_parse_mline(t_param *param, int *i)
{
	char	*line;
	int		j;

	line = NULL;
	get_next_line(0, &line);
	while (line && line[0] != '0')
	{
		check_fin(param, line);
		ft_strdel(&line);
		line = NULL;
		if (!param->vsl.stop)
			get_next_line(0, &line);
	}
	if (line)
	{
		j = 0;
		while (j < param->map.size_x)
		{
			set_plr_numb(param, i, j, line + 4);
			j++;
		}
		ft_strdel(&line);
	}
	(*i)++;
}

void	vis_create_map(t_param *param)
{
	char	*buf;
	char	*line;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	while (!ft_strstr(line, "Plateau"))
	{
		if (ft_strstr(line, "vfil.filler]"))
			param->plr = line[10] - '0';
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	buf = line;
	buf += 8;
	param->map.size_y = ft_atoi(buf);
	while (ft_isalnum(*buf))
		buf++;
	param->map.size_x = ft_atoi(buf);
	ft_strdel(&line);
	param->map.m = (int**)malloc(sizeof(int*) * param->map.size_y);
	i = 0;
	while (i < param->map.size_y)
		param->map.m[i++] = (int*)malloc(sizeof(int) * param->map.size_x);
	set_scale(param);
}

void	vis_parse(t_param *param)
{
	int i;

	usleep(50000);
	if (!param->map.created)
		vis_create_map(param);
	i = 0;
	while (i < param->map.size_y)
		vis_parse_mline(param, &i);
}
