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
# include <mlx.h>
# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_map
{
	int			size_x;
	int			size_y;
	int			**m;
	int			created;
}				t_map;

typedef struct	s_piece
{
	int			size_x;
	int			size_y;
	int			**p;
}				t_piece;

typedef struct	s_var
{
	int			i;
	int			j;
	int			k;
}				t_var;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_vsl
{
	int			win_x;
	int			win_y;
	int			img_x;
	int			img_y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_coord		res;
	int			stop;
	int			scale;
}				t_vsl;

typedef struct	s_param
{
	t_map		map;
	t_piece		piece;
	int			plr;
	int			enemy;
	t_coord		*crd;
	int			nb;
	t_coord		play;
	t_coord		enm;
	int			pos;
	int			iter;
	t_vsl		vsl;
}				t_param;

void			parse_map(t_param *param);
void			whoami(t_param *param);
void			create_map(t_param *param);
void			parse_mline(t_param *param, int *i);
void			parse_pline(t_param *param, int *i);
void			create_piece(t_param *param);
void			free_piece(t_param *param);
void			gnl_continue();
void			play(t_param *param);
void			find_enemy(t_param *param);
void			check_piece_len(t_param *param, int *min, int px, int py);
void			set_player_crd(t_param *param, int *min_len, int len, int i);
void			choose_crd(t_param *param, int *min_len);
void			count_set_place(t_param *param, int itr);
void			check_pset(t_param *param, int mi, int mj, int *iter);
int				check_plr_enemy(t_param *param, t_var *v, int mi, int mj);
void			check_start_pos(t_param *param);
void			print_map(t_param param);
void			put_pixel_to_image(t_param *param, int x, int y, int color);
void			visualizer(t_param *param);
void			vis_parse_mline(t_param *param, int *i);
void			vis_create_map(t_param *param);
void			vis_parse(t_param *param);
void			set_plr_numb(t_param *param, int *i, int j, char *buf);
void			check_fin(t_param *param, char *line);
void			set_scale(t_param *param);
void			print_score(t_param *param);
void			print_lines(t_param *param);
void			print_name(t_param *param);

#endif
