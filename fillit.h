/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:19:11 by vfil              #+#    #+#             */
/*   Updated: 2018/03/02 17:19:13 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_map
{
	int 		size_x;
	int 		size_y;
	int 		**m;
	int			created;
}				t_map;

typedef struct	s_piece
{
	int 		size_x;
	int 		size_y;
	int 		**p;
}				t_piece;

typedef struct	s_param
{
	t_map		map;
	t_piece		piece;
	int 		plr;
}				t_param;

void			parse_map(t_param *param);
void 			whoami(t_param *param);
void 			create_map(t_param *param);
void			parse_mline(t_param *param, int *i);
void			parse_pline(t_param *param, int *i);
void			create_piece(t_param *param);
void			free_piece(t_param *param);

#endif
