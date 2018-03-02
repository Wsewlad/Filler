/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 23:03:30 by vfil              #+#    #+#             */
/*   Updated: 2018/03/02 23:03:32 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_piece(t_param *param)
{
	int i;

	i = 0;
	while (i < param->piece.size_y)
		free(param->piece.p[i++]);
	free(param->piece.p);
	param->piece.p = NULL;
}

void	create_piece(t_param *param)
{
	char	*buf;
	char 	*line;
	int 	i;

	line = NULL;
	if (param->piece.p)
		free_piece(param);
	get_next_line(0, &line);
	buf = line;
	buf += 6;
	param->piece.size_y = ft_atoi(buf);
	while (ft_isalnum(*buf))
		buf++;
	param->piece.size_x = ft_atoi(buf);
	if (line)
		ft_strdel(&line);
	param->piece.p = (int**)malloc(sizeof(int*) * param->piece.size_y);
	i = 0;
	while (i < param->piece.size_y)
		param->piece.p[i++] = (int*)malloc(sizeof(int) * param->piece.size_x);
}

void	parse_pline(t_param *param, int *i)
{
	char	*line;
	int 	j;

	line = NULL;
	get_next_line(0, &line);
	j = 0;
	while (j < param->piece.size_x)
	{
		if (line[j] == '.')
			param->piece.p[*i][j] = 0;
		else
			param->piece.p[*i][j] = param->plr;
		j++;
	}
	(*i)++;
	if (line)
		ft_strdel(&line);
}
