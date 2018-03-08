/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:38:53 by vfil              #+#    #+#             */
/*   Updated: 2018/03/02 17:38:54 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
}

void	print_res(t_param *param)
{
	ft_printf("%d %d\n", param->play.y, param->play.x);
}

int		main(void)
{
	t_param	param;

	param.map.created = 0;
	param.piece.p = NULL;
	param.crd = NULL;
	param.nb = 0;
	param.pos = 0;
	param.iter = 1;
	whoami(&param);
	while (param.nb != -1)
	{
		parse_map(&param);
		play(&param);
		if (param.nb > 0)
			print_res(&param);
	}
	ft_printf("%d %d\n", -1, -1);
	return (0);
}