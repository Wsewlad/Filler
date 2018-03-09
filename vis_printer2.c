/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_printer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:27:23 by vfil              #+#    #+#             */
/*   Updated: 2018/03/09 20:27:25 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_name(t_param *param)
{
	char *map;

	mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, \
	param->vsl.win_x / 2 - 80, 120, 0x00d2ff, "FILLER");
	mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, \
	param->vsl.win_x / 2 - 80, 120, 0x003f4c, "        MAP: ");
	map = ft_strnew(1);
	ft_strjoin_free(&map, ft_itoa(param->map.size_y));
	ft_strjoin_free(&map, " ");
	ft_strjoin_free(&map, ft_itoa(param->map.size_x));
	mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, \
	param->vsl.win_x / 2 + 50, 120, 0x003f4c, map);
}

void	print_lines(t_param *param)
{
	int i;

	print_name(param);
	i = 0;
	if (!(param->map.size_y == 100 && param->map.size_x == 99))
		while (i < param->vsl.win_x)
		{
			mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, i, \
		140, 0x003f4c, "-");
			i++;
		}
	mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, 100, \
	param->vsl.win_y - 120, 0x003f4c, "Score:");
	i = 0;
	while (i < param->vsl.win_x)
	{
		mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, i, \
	param->vsl.win_y - 140, 0x003f4c, "-");
		i++;
	}
	mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, \
	param->vsl.win_x / 2 - 50, param->vsl.win_y - 90, 0x003f4c, "vfil.filler ");
}

void	print_score(t_param *param)
{
	char *score1;
	char *score2;

	score1 = ft_strnew(1);
	score2 = ft_strnew(1);
	ft_strjoin_free(&score1, "O -> ");
	ft_strjoin_free(&score1, ft_itoa(param->vsl.res.y));
	ft_strjoin_free(&score2, "X -> ");
	ft_strjoin_free(&score2, ft_itoa(param->vsl.res.x));
	mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, 90, \
	param->vsl.win_y - 100, param->plr == 1 ? 0x00d2ff : 0xffff66, score1);
	mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, 90, \
	param->vsl.win_y - 80, param->plr == 2 ? 0x00d2ff : 0xffff66, score2);
	if ((param->plr == 2 && param->vsl.res.x > param->vsl.res.y) || \
	(param->plr == 1 && param->vsl.res.x < param->vsl.res.y))
		mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, \
		param->vsl.win_x / 2, param->vsl.win_y - 90, 0x00d2ff, "        won!");
	else
		mlx_string_put(param->vsl.mlx_ptr, param->vsl.win_ptr, \
		param->vsl.win_x / 2, param->vsl.win_y - 90, 0xffff66, "        lost!");
}
