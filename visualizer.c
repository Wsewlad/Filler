/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:28:31 by vfil              #+#    #+#             */
/*   Updated: 2018/03/08 17:28:33 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <mlx.h>

void	vsl_init(t_param *param)
{
	param->vsl.win_x = 500;
	param->vsl.win_y = 500;
	param->vsl.mlx_ptr = mlx_init();
	param->vsl.win_ptr = mlx_new_window(param->vsl.mlx_ptr, param->vsl.win_x, \
	param->vsl.win_y, "Filler");
	param->vsl.img_ptr = mlx_new_image(param->vsl.mlx_ptr, param->vsl.win_x, \
	param->vsl.win_y);
}

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

void	visualizer(t_param *param)
{
	int i;
	int j;
	int k;
	int	k2;
	int enemy;

	enemy = param->plr == 1 ? 2 : 1;
	mlx_destroy_image(param->vsl.mlx_ptr, param->vsl.img_ptr);
	param->vsl.img_ptr = mlx_new_image(param->vsl.mlx_ptr, param->vsl.win_x, param->vsl.win_y);
	i = 0;
	while (i < param->map.size_y)
	{
		j = 0;
		while (j < param->map.size_x)
		{
			k = 0;
			k2 = 0;
			if (param->map.m[i][j] == param->plr)
			{
				while (k2++ < 5)
				{
					while (k++ < 5)
						put_pixel_to_image(param, j + k + j * 15, i + i * 15, 0xffff66);
				}
				while (k-- > 0)
				{
					while (k2-- > 0)
						put_pixel_to_image(param, j + j * 15, i + k2 + i * 15, 0xffff66);
				}
			}
			else if (param->map.m[i][j] == enemy)
			{
				while (k++ < 5)
					put_pixel_to_image(param, j + k + j * 15, i + i * 15, 0x00d2ff);
				while (k2++ < 5)
					put_pixel_to_image(param, j + j * 15, i + k2 + i * 15, 0x00d2ff);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(param->vsl.mlx_ptr, param->vsl.win_ptr, param->vsl.img_ptr, 20, 20);
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
}

void	gnl_continue2(t_param *param)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "vfil.filler]"))
		param->plr = line[10] - '0';
	ft_strdel(&line);
}

int		deal_key(int key, t_param *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->vsl.mlx_ptr, param->vsl.win_ptr);
		exit(1);
	}
	if (key && !param->stop)
	{
		parse_map(param);
		gnl_continue(param);
		//usleep(10000);
		print_map(*param);
		visualizer(param);
	}
	return (0);
}

int 	main(void)
{
	t_param	param;
	int i;
	int loop;

	loop = 0;
	param.piece.p = NULL;
	param.crd = NULL;
	param.map.created = 0;
	vsl_init(&param);
	i = 0;
	param.stop = 0;
	while (i < 9)
	{
		gnl_continue2(&param);
		i++;
	}
	mlx_hook(param.vsl.win_ptr, 2, 5, deal_key, &param);
	mlx_loop(param.vsl.mlx_ptr);
	return (0);
}