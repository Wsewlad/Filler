/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:18:39 by vfil              #+#    #+#             */
/*   Updated: 2018/03/02 17:18:41 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	whoami(t_param *param)
{
	char	*line;

	get_next_line(0, &line);
	if (line)
	{
		param->plr = line[10] - '0';
		param->enemy = param->plr == 1 ? 2 : 1;
		ft_strdel(&line);
	}
}

void	parse_map(t_param *param)
{
	int		i;

	if (!param->map.created)
		create_map(param);
	else
		gnl_continue();
	gnl_continue();
	i = 0;
	while (i < param->map.size_y)
		parse_mline(param, &i);
	if (!param->pos)
		check_start_pos(param);
	create_piece(param);
	i = 0;
	while (i < param->piece.size_y)
		parse_pline(param, &i);
}

void	create_map(t_param *param)
{
	char	*buf;
	char	*line;
	int		i;

	line = NULL;
	get_next_line(0, &line);
	if (line)
	{
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
		param->map.created = 1;
	}
}

void	gnl_continue(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if (line)
		ft_strdel(&line);
}

void	parse_mline(t_param *param, int *i)
{
	char	*line;
	char	*buf;
	int		j;

	line = NULL;
	get_next_line(0, &line);
	if (line)
	{
		buf = line + 4;
		j = 0;
		while (j < param->map.size_x)
		{
			if (buf[j] == 'O' || buf[j] == 'o')
				param->map.m[*i][j] = 1;
			else if (buf[j] == 'X' || buf[j] == 'x')
				param->map.m[*i][j] = 2;
			else
				param->map.m[*i][j] = 0;
			j++;
		}
		(*i)++;
		ft_strdel(&line);
	}
}
