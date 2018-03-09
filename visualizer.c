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

void	vsl_init(t_param *param)
{
	param->vsl.win_x = 744;
	param->vsl.win_y = 744;
	param->vsl.mlx_ptr = mlx_init();
	param->vsl.win_ptr = mlx_new_window(param->vsl.mlx_ptr, param->vsl.win_x, \
	param->vsl.win_y, "Filler");
	param->vsl.img_ptr = mlx_new_image(param->vsl.mlx_ptr, param->vsl.win_x, \
	param->vsl.win_y);
	param->vsl.stop = 0;
	param->map.created = 0;
	param->vsl.scale = 5;
}

int		deal_key(int key, t_param *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->vsl.mlx_ptr, param->vsl.win_ptr);
		exit(1);
	}
	return (0);
}

int		runner(t_param *param)
{
	if (!param->vsl.stop)
	{
		vis_parse(param);
		visualizer(param);
	}
	return (0);
}

int		main(void)
{
	t_param	param;

	vsl_init(&param);
	mlx_hook(param.vsl.win_ptr, 2, 5, deal_key, &param);
	mlx_loop_hook(param.vsl.mlx_ptr, runner, &param);
	mlx_loop(param.vsl.mlx_ptr);
	return (0);
}
