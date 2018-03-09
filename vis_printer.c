/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:16:12 by vfil              #+#    #+#             */
/*   Updated: 2018/03/09 14:16:14 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_pixel_to_image(t_param *param, int x, int y, int color)
{
	int *data;
	int bits_per_pixel;
	int size_line;
	int endian;

	data = (int *)mlx_get_data_addr(param->vsl.img_ptr, &bits_per_pixel, \
	&size_line, &endian);
	if (x < param->vsl.win_x && y < param->vsl.win_y && x > 0 && y > 0)
		data[x + y * size_line / 4] = color;
}

void	put_pixels(t_param *param, int i, int j, int scl)
{
	int y;
	int x;

	y = param->vsl.img_y;
	x = param->vsl.img_x;
	if (param->map.m[i][j] == param->plr)
		put_pixel_to_image(param, x + j + (j + 1) * scl, y + i + \
		(i + 1) * scl, 0x00d2ff);
	else if (param->map.m[i][j] == param->plr + 2)
		put_pixel_to_image(param, x + j + (j + 1) * scl, y + i + \
		(i + 1) * scl, 0xffffff);
	else if (param->map.m[i][j] == param->enemy)
		put_pixel_to_image(param, x + j + (j + 1) * scl, y + i + \
		(i + 1) * scl, 0xffff66);
	else if (param->map.m[i][j] == param->enemy + 2)
		put_pixel_to_image(param, x + j + (j + 1) * scl, y + i + \
		(i + 1) * scl, 0x000000);
}

void	visualizer(t_param *param)
{
	int i;
	int j;

	param->enemy = param->plr == 1 ? 2 : 1;
	mlx_destroy_image(param->vsl.mlx_ptr, param->vsl.img_ptr);
	param->vsl.img_ptr = mlx_new_image(param->vsl.mlx_ptr, param->vsl.win_x, \
	param->vsl.win_y);
	i = 0;
	while (i < param->map.size_y)
	{
		j = 0;
		while (j < param->map.size_x)
		{
			put_pixels(param, i, j, param->vsl.scale);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(param->vsl.mlx_ptr, param->vsl.win_ptr, \
	param->vsl.img_ptr, 0, 0);
	print_lines(param);
	if (param->vsl.stop)
		print_score(param);
}

void	print_map(t_param param)
{
	int i;
	int j;

	i = 0;
	while (i < param.map.size_y)
	{
		j = 0;
		while (j < param.map.size_x)
		{
			ft_printf("%d ", param.map.m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	if (param.vsl.stop)
		ft_printf("SCORE:\nO: %d\nX: %d\n", param.vsl.res.y, param.vsl.res.x);
}
