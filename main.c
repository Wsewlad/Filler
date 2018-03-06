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
	int i;

	i = 0;
	//ft_printf("%d %d\n", param->res[0].y, param->res[0].x);
	ft_printf("%d\n", param->nb);
	/*while (i < param->nb)
		i++;
	i--;
	ft_printf("%d %d\n", param->crd[0].y, param->crd[0].x);*/
	while (i < param->nb)
	{
		ft_printf("%d %d\n", param->crd[i].y, param->crd[i].x);
		i++;
	}
}

int main(void)
{
	t_param	param;
	//int 	i;

	param.map.created = 0;
	param.piece.p = NULL;
	param.crd = NULL;
	param.nb = 0;
	whoami(&param);
	//i = 0;
	while (param.nb != -1)
	{
		parse_map(&param);
		play(&param);
		if (param.nb > 0)
			print_res(&param);
		//i++;
		// debug
		//print_map(*param);
	}
	return (0);
}
