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
		ft_printf("%d: ", i);
		while (j < param.map.size_x)
		{
			ft_printf("%d ", param.map.m[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	i = 0;
	while (i < param.piece.size_y)
	{
		j = 0;
		ft_printf("%d: ", i);
		while (j < param.piece.size_x)
		{
			ft_printf("%d ", param.piece.p[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_res(t_param *param)
{
	ft_printf("%d %d\n", param->res_y, param->res_x);
	//ft_printf("{file}%d %d\n", 2, param->res_y, param->res_x);
}

int main(void)
{
	t_param	param;
	//int 	i;

	param.map.created = 0;
	param.piece.p = NULL;
	param.end = 0;
	whoami(&param);
	//i = 0;
	while (!param.end)
	{
		parse_map(&param);
		play(&param);

		if (!param.end)
			print_res(&param);
		//i++;
		// debug
		//print_map(*param);
	}
	return (0);
}
